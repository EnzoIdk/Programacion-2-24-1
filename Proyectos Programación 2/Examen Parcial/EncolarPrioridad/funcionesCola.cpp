/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "funcionesCola.h"

enum Cola{CABEZA,COLA,FINVIP,FINCLI};
enum Nodo{CAT,DNI,SGTE};

void construirCola(void *&cola){
    void **aux=new void*[4]{};
    cola=aux;
}

void encolar(void *cola,char categoria,int dni){
    void **auxCola=(void**)cola,**auxFin;
    void **nuevo=crearNodo(categoria,dni);
    if(auxCola[CABEZA]==nullptr){
        auxCola[CABEZA]=nuevo;
        auxCola[COLA]=nuevo;
        if(categoria=='V') auxCola[FINVIP]=nuevo;
        else if(categoria=='C') auxCola[FINCLI]=nuevo;
    }
    else{
        if(categoria=='V'){
            if(auxCola[FINVIP]==nullptr){
                nuevo[SGTE]=auxCola[CABEZA];
                auxCola[CABEZA]=nuevo;
                auxCola[FINVIP]=nuevo;
            }
            else{
                auxFin=(void**)auxCola[FINVIP];
                if(esColaVacia(auxFin[SGTE])) auxCola[COLA]==nuevo;
                nuevo[SGTE]=auxFin[SGTE];
                auxFin[SGTE]=nuevo;
                auxCola[FINVIP]=nuevo;
            }
        }
        else if(categoria=='C'){
            if(auxCola[FINCLI]==nullptr){
                if(auxCola[FINVIP]==nullptr){
                    nuevo[SGTE]=auxCola[CABEZA];
                    auxCola[CABEZA]=nuevo;
                    auxCola[FINCLI]=nuevo;
                }
                else{
                    auxFin=(void**)auxCola[FINVIP];
                    nuevo[SGTE]=auxFin[SGTE];
                    auxFin[SGTE]=nuevo;
                    auxCola[FINCLI]=nuevo;
                }
            }
            else{
                auxFin=(void**)auxCola[FINCLI];
                if(esColaVacia(auxFin[SGTE])) auxCola[COLA]=nuevo;
                nuevo[SGTE]=auxFin[SGTE];
                auxFin[SGTE]=nuevo;
                auxCola[FINCLI]=nuevo;
            }
        }
        else{
            auxFin=(void**)auxCola[COLA];
            nuevo[SGTE]=auxFin[SGTE];
            auxFin[SGTE]=nuevo;
            auxCola[COLA]=nuevo;
        }
    }
}

bool esColaVacia(void *cola){
    if(cola==nullptr) return true;
    else return false;
}

void **crearNodo(char categoria,int dni){
    void **nodo=new void*[3]{};
    char *ptrCat=new char{categoria};
    int *ptrDni=new int{dni};
    nodo[CAT]=ptrCat;
    nodo[DNI]=ptrDni;
    return nodo;
}

void imprimirCola(void *cola){
    void **auxCola=(void**)cola;
    if(esColaVacia(auxCola[CABEZA])) cout<<"La cola esta vacia"<<endl;
    else{
        void **cabeza=(void**)auxCola[CABEZA];
        while(!esColaVacia(cabeza)){
            imprime(cabeza[CAT],cabeza[DNI]);
            cabeza=(void**)cabeza[SGTE];
        }
    }
}

void imprime(void *datoCat,void *datoDNI){
    char *cat=(char*)datoCat;
    int *dni=(int*)datoDNI;
    cout<<*dni<<' '<<*cat<<endl;
}