/* 
 * File:   Arbol.cpp
 * Author: ramir
 * 
 * Created on 7 de junio de 2024, 11:17 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Arbol.h"
#define MAX_LINEA 90

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}
/*
P,202119153,MENDOZA/ARIAS/HENRY,4,19.5,10
S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,30
V,202318072,RIVERA/MONTERO/GLORIA-OFELIA,3,20,323R33-02
*/
void Arbol::crear(const char *nombArch){
    ifstream archAlum(nombArch,ios::in);
    if(not archAlum.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char tipo;
    Boleta boleta;
    while(1){
        archAlum>>tipo;
        if(archAlum.eof()) break;
        archAlum.get();
        boleta.asignaMemoria(tipo);
        boleta.leerDatos(archAlum);
        insertarRaiz(raiz,boleta);
        boleta.SetNull();
    }
}

void Arbol::insertarRaiz(class Nodo *&arbol,const class Boleta &dato){
    if(arbol==nullptr){
        arbol = new Nodo;
        arbol->dboleta = dato;
        return;
    }
    if(arbol->dboleta.GetCodigo()>dato.GetCodigo())
        insertarRaiz(arbol->izq,dato);
    else
        insertarRaiz(arbol->der,dato);
}

void Arbol::mostrarEnOrden(const char *nombArch){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<left<<setw(10)<<"Codigo"<<setw(40)<<"Nombre"<<setw(8)<<"Escala"
           <<setw(10)<<"Creditos"<<setw(12)<<"Licencia"<<setw(10)<<"Total"<<endl;
    imprimirLinea(archRep,'=');
    mostrarEnOrdenRaiz(archRep,raiz);
}

void Arbol::imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}

void Arbol::mostrarEnOrdenRaiz(ofstream &archRep,class Nodo *raiz){
    if(raiz){
        mostrarEnOrdenRaiz(archRep,raiz->izq);
        raiz->dboleta.imprimealumnos(archRep);
        mostrarEnOrdenRaiz(archRep,raiz->der);
    }
}
/*
5,666.90
4,556.70
*/
void Arbol::cargaEscalas(const char *nombArch){
    ifstream archEsc(nombArch,ios::in);
    if(not archEsc.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numEsc;
    double costoXCred;
    while(1){
        archEsc>>numEsc;
        if(archEsc.eof()) break;
        archEsc.get();
        archEsc>>costoXCred;
        lescala[numEsc-1].SetCodigo(numEsc);
        lescala[numEsc-1].SetPrecio(costoXCred);
    }
}
    
void Arbol::actualizaBoleta(){
    actualizaBoletaRaiz(raiz);
}

void Arbol::actualizaBoletaRaiz(class Nodo *arbol){
    
    if(arbol==nullptr) return;
    
    int numEsc = arbol->dboleta.GetEscala();
    double costoXCred = lescala[numEsc-1].GetPrecio();
    
    arbol->dboleta.actualizaBoleta(costoXCred);
    actualizaBoletaRaiz(arbol->izq);
    actualizaBoletaRaiz(arbol->der);
}