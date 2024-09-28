/* 
 * File:   BibliotecaGenerica.cpp
 * Author: Lucas
 *
 * Created on 7 de mayo de 2024, 17:33
 */

#include <iostream>
using namespace std;

#include "BibliotecaGenerica.h"

enum Lista{INICIO, FIN};
enum NODO{DATO, SIGUIENTE};

void crearLista(void * &pedidos, void * (*leer)(ifstream &), const char* nomb){
    ifstream arch(nomb, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    void ** lista=new void*[2]{}, * dato;
    //LEEMOS LOS DATOS
    while(true){
        dato=leer(arch);
        if(arch.eof()) break;
        insertaLista(lista, dato);
    }
    pedidos=lista;
}

void insertaLista(void ** lista, void * dato){
    void ** aux, ** nodo=new void*[2]{};
    nodo[DATO]=dato;
    if(listaVacia(lista)){
        lista[INICIO]=nodo;
        lista[FIN]=nodo;
    }
    else{
        aux=(void ** )lista[FIN];
        aux[SIGUIENTE]=nodo;
        lista[FIN]=nodo;
    }
}

bool listaVacia(void ** lista){
    return lista[INICIO]==nullptr;
}

void imprimeLista(void * pedido, void (*imprimir)(ofstream &, void * ), 
        const char * nomb){
    ofstream arch(nomb, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nomb;
        exit(1);
    }
    //IMPRESION
    void ** lista=(void ** )pedido;
    void ** nodo=(void ** )lista[INICIO];
    while(nodo!=nullptr){
        imprimir(arch, nodo[DATO]);
        nodo=(void ** )nodo[SIGUIENTE];
    }
}

void combinaLista(void * pedidos1, void * pedidos2, void * &pedidosFinal, 
        int (*cmp)(const void *, const void *)){
    void ** lista1=(void ** )pedidos1, ** lista2=(void ** )pedidos2, 
            **listaFinal=new void*[2]{}, ** aux, ** aux1, ** aux2, * bin;
    int comp;
    //MERGE
    while(not listaVacia(lista1) and not listaVacia(lista2)){
        aux1=(void ** )lista1[INICIO];
        aux2=(void ** )lista2[INICIO];
        comp=cmp(aux1[DATO], aux2[DATO]);
        if(comp>0){
            insertaLista(listaFinal, quitaLista(lista2));
        }
        else if(comp==0){
            insertaLista(listaFinal, quitaLista(lista1));
            bin=quitaLista(lista2);
        }
        else{
            insertaLista(listaFinal, quitaLista(lista1));
        }
    }
    if(not listaVacia(lista1)){
        aux=(void ** )listaFinal[FIN];
        aux[SIGUIENTE]=lista1[INICIO];
        listaFinal[FIN]=lista1[FIN];
    }
    if(not listaVacia(lista2)){
        aux=(void ** )listaFinal[FIN];
        aux[SIGUIENTE]=lista2[INICIO];
        listaFinal[FIN]=lista2[FIN];
    }
    delete lista1;
    delete lista2;
    pedidosFinal=listaFinal;
}

void * quitaLista(void ** lista){
    void ** nodo, * regreso;
    if(listaVacia(lista)){
        return nullptr;
    }
    else{
        nodo=(void ** )lista[INICIO];
        lista[INICIO]=nodo[SIGUIENTE];
        regreso=nodo[DATO];
        delete nodo;
        return regreso;
    }
}




