/* 
 * File:   BibliotecaListaGenerica.cpp
 * Author: Lucas
 *
 * Created on 3 de mayo de 2024, 0:03
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include <fstream>

#include "BibliotecaListaGenerica.h"
#include "AperturaDeArchivos.h"

enum Lista{INICIO, FIN};
enum Nodo{DATO, SIGUIENTE};

void crearLista(void * &lista, void * (*leer)(ifstream &), int cmp(const void *, 
        const void *), const char * nombArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    void ** listaTemp=new void*[2]{}, * dato;
    //LECTURA
    while(true){
        dato=leer(arch);
        if(arch.eof()) break;
        insertaLista(listaTemp, dato, cmp);
    }
    lista=listaTemp;
}

void insertaLista(void ** lista, void * dato, int (*cmp)(const void *, 
        const void *)){
    void ** nodo, ** recorre, ** anterior=nullptr;
    int comp;
    //CREAMOS NODO
    nodo=new void*[2]{};
    nodo[DATO]=dato;
    //EVALUAMOS
    if(listaVacia(lista)){
        lista[INICIO]=nodo;
        lista[FIN]=nodo;
    }
    else{
        recorre=(void ** )lista[INICIO];
        while(recorre){
            comp=cmp(recorre[DATO], dato);
            if(comp>=0) break; //LAS FECHAS NO SE REPITEN
            anterior=recorre;
            recorre=(void ** )recorre[SIGUIENTE];
        }
        if(comp!=0){
            nodo[SIGUIENTE]=recorre;
            if(nodo[SIGUIENTE]==nullptr) lista[FIN]=nodo;
            if(anterior!=nullptr) anterior[SIGUIENTE]=nodo;
            else lista[INICIO]=nodo; 
        }
    }
}

bool listaVacia(void ** lista){
    return lista[INICIO]==nullptr;
}

void uneLista(void * lista1, void * lista2){
    void ** auxLista1=(void ** )lista1, ** auxLista2=(void ** )lista2;
    void ** finalLista1=(void ** )auxLista1[FIN], 
            ** inicioLista2=(void ** )auxLista2[INICIO];
    finalLista1[SIGUIENTE]=inicioLista2;
    delete auxLista2; //ELIMINAMOS SOLO LOS PUNTEROS QUE MARCABAN SU INCIO Y SU FIN
}

void imprimeLista(void * lista, void imprime(ofstream &, void * dato), 
        const char * nombArch){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);
    void ** auxLista=(void ** )lista;
    void ** recorre=(void ** )auxLista[INICIO];
    while(recorre){
        imprime(arch, recorre[DATO]);
        recorre=(void ** )recorre[SIGUIENTE];
    }
}
