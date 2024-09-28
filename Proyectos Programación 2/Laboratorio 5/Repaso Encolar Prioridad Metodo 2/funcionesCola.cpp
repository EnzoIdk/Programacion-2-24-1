/* 
 * File:   funcionesCola.cpp
 * Author: Lucas
 *
 * Created on 1 de mayo de 2024, 17:55
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "funcionesCola.h"

enum Cola{CABEZA, COLA, VIEJOS, ADULTOS, NINOS};
enum Nodo{CAT, DNI, SIG};

void construirCola(void * &cola){
    void ** aux=new void*[5]{};
    cola=aux;
}

void encolar(void * cola, char categoria, int dni){
    
    void ** aux=(void ** )cola, ** auxFin;
    void ** nuevo=crearNodo(categoria, dni, nullptr);
    
    if(aux[CABEZA]==nullptr){
        aux[CABEZA]=nuevo;
        aux[COLA]=nuevo;
        if(categoria=='V') aux[VIEJOS]=nuevo;
        if(categoria=='N') aux[NINOS]==nuevo;
    }
    else{
        if(categoria=='V'){
            if(aux[VIEJOS]==nullptr){
                nuevo[SIG]=aux[CABEZA];
                aux[CABEZA]=nuevo;
            }
            else{
                if(siguienteVacio(aux[VIEJOS])) aux[COLA]=nuevo;
                //RECORDEMOS QUE ES OTRA VARIABLE
                auxFin=(void ** )aux[VIEJOS];
                nuevo[SIG]=auxFin[SIG];
                auxFin[SIG]=nuevo;
                aux[VIEJOS]=nuevo;
            }
            aux[VIEJOS]=nuevo;
        }
        else if(categoria=='N'){
            if(aux[NINOS]==nullptr){
                if(aux[VIEJOS]==nullptr){
                    nuevo[SIG]=aux[CABEZA];
                    aux[CABEZA]=nuevo;
                }
                else{
                    auxFin=(void ** )aux[VIEJOS];
                    nuevo[SIG]=auxFin[SIG];
                    auxFin[SIG]=nuevo;
                }
            }
            else{
                if(siguienteVacio(aux[NINOS])) aux[COLA]=nuevo;
                auxFin=(void ** )aux[NINOS];
                nuevo[SIG]=auxFin[SIG];
                auxFin[SIG]=nuevo;
                aux[NINOS]=nuevo;
            }
            aux[NINOS]=nuevo;
        }
        else{
            nuevo[SIG]=nullptr;
            auxFin=(void ** )aux[COLA];
            auxFin[SIG]=nuevo;
            aux[COLA]=nuevo;
        }
    }
}

void ** crearNodo(char categoria, int dni, void * siguiente){
    void ** nuevo=new void*[3];
    char * catAux=new char;
    int * dniAux=new int;
    *catAux=categoria;
    *dniAux=dni;
    nuevo[CAT]=catAux;
    nuevo[DNI]=dniAux;
    nuevo[SIG]=siguiente;
    return nuevo;
}

void * extraerSiguiente(void * nodo){
    void ** aux=(void ** )nodo;
    void * regreso=aux[SIG];
    return regreso;
}

bool siguienteVacio(void * nodo){
    void ** aux=(void ** )nodo;
    return aux[SIG]==nullptr;
}

void imprimirCola(void * cola){
    void ** aux=(void ** )cola;
    void ** recorre;
    if(aux[CABEZA]==nullptr){
        cout<<"La cola esta vacia"<<endl;
    }
    else{
        recorre=(void ** )aux[CABEZA];
        while(recorre){
            imprimeNodo(recorre);
            recorre=(void ** )recorre[SIG];
        }
    }
}

void imprimeNodo(void ** recorre){
    char * cat=(char * )recorre[CAT];
    int * dni=(int * )recorre[DNI];
    cout<<*dni<<":"<<*cat<<endl;
}