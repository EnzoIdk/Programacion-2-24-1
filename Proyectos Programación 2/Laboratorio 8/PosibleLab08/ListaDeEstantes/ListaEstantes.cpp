/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ListaEstantes.cpp
 * Author: Enzo
 * 
 * Created on 13 de junio de 2024, 09:15 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>
using namespace std;
#include "ListaEstantes.h"
#include "Estante.h"
#include "EstanteHorizontal.h"
#include "EstanteVertical.h"
#include "NodoEst.h"

ListaEstantes::ListaEstantes() {
    lista=nullptr;
}

ListaEstantes::~ListaEstantes() {
    elimina();
}

void ListaEstantes::crear(ifstream &arch){
    class Estante *auxEst;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        asignarMemoria(auxEst,tipo);
        auxEst->leeEst(arch);
        insertar(auxEst);
    }
}

void ListaEstantes::asignarMemoria(class Estante *&aux,char tipo){
    switch(tipo){
        case 'H':
            aux=new class EstanteHorizontal;
            break;
        case 'V':
            aux=new class EstanteVertical;
            break;
    }
}

void ListaEstantes::insertar(class Estante *dato){
    class NodoEst *rec=lista,*ant=nullptr,*nuevoNodo;
    nuevoNodo=new class NodoEst;
    nuevoNodo->pEstante=dato;
    while(rec){
        ant=rec;
        rec=rec->sig;
    }
    nuevoNodo->sig=rec;
    if(ant==nullptr) lista=nuevoNodo;
    else ant->sig=nuevoNodo;
}

void ListaEstantes::imprimir(ofstream &arch){
    class NodoEst *rec=lista;
    while(rec){
        imprimirLinea(arch,60,'-');
        rec->pEstante->imprimeEst(arch);
        imprimirLinea(arch,60,'-');
        rec=rec->sig;
    }
    arch<<endl;
}

void ListaEstantes::elimina(){
    class NodoEst *sale;
    while(lista){
        sale=lista;
        lista=lista->sig;
        delete sale;
    }
    lista=nullptr;
}

void ListaEstantes::imprimirLinea(ofstream &arch,int tam,char simb){
    for(int i=0;i<tam;i++) arch.put(simb);
    arch<<endl;
}

void ListaEstantes::posicionarLibros(class Libro *libros[], int numLib){
    class NodoEst *rec=lista;
    while(rec){
        for(int i=0;i<numLib;i++){
            if(!libros[i]->IsColocado() and (rec->pEstante->GetPesoActual()+
                    libros[i]->GetPeso()<=rec->pEstante->GetPesoSoportado())){
                rec->pEstante->agregarLibro(libros[i]);
                rec->pEstante->SetPesoActual(rec->pEstante->GetPesoActual()
                        + libros[i]->GetPeso()); 
            }
        }
        rec=rec->sig;
    }
}