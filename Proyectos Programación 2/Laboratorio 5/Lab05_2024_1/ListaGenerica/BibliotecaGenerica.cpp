/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "BibliotecaGenerica.h"
#include "FuncionesEnteros.h"
using namespace std;

enum Lista{INI,FIN};
enum Nodo{DATO,SGTE};

void crealista(void *&lista,void *(*lee)(ifstream &),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *dato;
    inicializarLista(lista);
    while(true){
        dato=lee(arch);
        if(arch.eof()) break;
        insertalista(lista,dato);
    }
}

void inicializarLista(void *&lista){
    void **auxLista=new void*[2]{};
    auxLista[INI]=nullptr;
    auxLista[FIN]=nullptr;
    lista=auxLista;
}

void insertalista(void *&lst,void *dato){
    void **lista=(void**)lst;
    void **cola,**nuevoNodo;
    crearNodo(nuevoNodo,dato);
    if(listavacia(lst)){
        lista[INI]=nuevoNodo;
        lista[FIN]=nuevoNodo;
    }
    else{
        cola=(void**)lista[FIN];
        cola[SGTE]=nuevoNodo;
        lista[FIN]=nuevoNodo;
    }
}

void *quitalista(void *&lista){
    void **auxLista=(void**)lista;
    void **cabeza,*dato;
    if(listavacia(lista)) return nullptr;
    else{
        cabeza=(void**)auxLista[INI];
        dato=cabeza[DATO];
        /*modificando la lista*/
        auxLista[INI]=cabeza[SGTE];
        delete cabeza;
        return dato;
    }
}

void crearNodo(void **&nuevoNodo,void *dato){
    nuevoNodo=new void*[2]{};
    nuevoNodo[DATO]=dato;
    nuevoNodo[SGTE]=nullptr;
}

bool listavacia(void *lista){
    void **auxLista=(void**)lista;
    if(auxLista[INI]==nullptr) return true;
    else return false;
}

void imprimelista(void *lista,void (*imprime)(ofstream &,void*),const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **auxLista=(void**)lista;
    void **ini=(void**)auxLista[INI];
    while(ini!=nullptr){
        imprime(arch,ini[DATO]);
        ini=(void**)ini[SGTE];
    }
}

void combinalista(void *ped1,void *ped2,void *&pedFin,int (*cmp)(const void*,const void*)){
    inicializarLista(pedFin);
    //Si solo queremos unirlas
//    void **pedido1=(void**)ped1,**pedido2=(void**)ped2;
//    void **fin1=(void**)pedido1[FIN];
//    fin1[SGTE]=pedido2[INI];
//    pedido1[FIN]=pedido2[FIN];
//    pedFin=pedido1;
    void **pedido1,**pedido2,**cabeza1,**cabeza2,**pedidoFinal,**cabezaFin;
    void *dato1,*dato2;
    while(!listavacia(ped1) and !listavacia(ped2)){
        pedido1=(void**)ped1;
        pedido2=(void**)ped2;
        cabeza1=(void**)pedido1[INI];
        cabeza2=(void**)pedido2[INI];
        if(cmp(cabeza1[DATO],cabeza2[DATO])>0){
           dato2=quitalista(ped2);
           insertalista(pedFin,dato2);
        }
        else if(cmp(cabeza1[DATO],cabeza2[DATO])<0){
           dato1=quitalista(ped1);
           insertalista(pedFin,dato1); 
        }
        else{
            dato1=quitalista(ped1);
            dato2=quitalista(ped2);
            insertalista(pedFin,dato1);
        }
    }
    pedidoFinal=(void**)pedFin;
    cabezaFin=(void**)pedidoFinal[FIN];
    if(!listavacia(ped1)){    
        cabezaFin[SGTE]=pedido1[INI];
        pedidoFinal[FIN]=pedido1[FIN];
    }
    else if(!listavacia(ped2)){
        cabezaFin[SGTE]=pedido2[INI];
        pedidoFinal[FIN]=pedido2[FIN];
    }
}