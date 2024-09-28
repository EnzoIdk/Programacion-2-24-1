/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "AperturaDeArchivos.h"
#include "PunterosMultiples1Examen01Pregunta01.h"
#include "PunteroVoid.h"
#include "MuestraVoid.h"
#include "PunterosFuncion1Examen01Pregunta03.h"
#include "ColaPrioridadGenerica.h"
#include "Registros.h"

enum Cola{INI,FIN3,FIN2,FIN1};
enum Nodo{DATO,SGTE};

void generacola(void *&cola){
    void **aux=new void*[4]{};
    cola=aux;
}

void encola(void *cl,void *dato){
    void **cola=(void**)cl;
    void **nuevoNodo,**auxFin;
    crearNodo(nuevoNodo,dato);
    int ranking=obtenerRanking(dato);
    if(colavacia(cl)){
        cola[INI]=nuevoNodo;
        cola[FIN1]=nuevoNodo;
        if(ranking==3) cola[FIN3]=nuevoNodo;
        else if(ranking==2) cola[FIN2]=nuevoNodo;
    }
    else{
        if(ranking==3){
            if(cola[FIN3]==nullptr){
                nuevoNodo[SGTE]=cola[INI];
                cola[INI]=nuevoNodo;
                cola[FIN3]=nuevoNodo;
            }
            else{
                auxFin=(void**)cola[FIN3];
                if(auxFin[SGTE]==nullptr) cola[FIN1]=nuevoNodo;
                nuevoNodo[SGTE]=auxFin[SGTE];
                auxFin[SGTE]=nuevoNodo;
                cola[FIN3]=nuevoNodo;
            }
        }
        else if(ranking==2){
            if(cola[FIN2]==nullptr){
                if(cola[FIN3]==nullptr){
                    nuevoNodo[SGTE]=cola[INI];
                    cola[INI]=nuevoNodo;
                    cola[FIN2]=nuevoNodo;
                }
                else{
                    auxFin=(void**)cola[FIN3];
                    nuevoNodo[SGTE]=auxFin[SGTE];
                    auxFin[SGTE]=nuevoNodo;
                    cola[FIN2]=nuevoNodo;
                }
            }
            else{
                auxFin=(void**)cola[FIN2];
                if(auxFin[SGTE]==nullptr) cola[FIN1]=nuevoNodo;
                nuevoNodo[SGTE]=auxFin[SGTE];
                auxFin[SGTE]=nuevoNodo;
                cola[FIN2]=nuevoNodo;
            }
        }
        else{
            auxFin=(void**)cola[FIN1];
            nuevoNodo[SGTE]=auxFin[SGTE];
            auxFin[SGTE]=nuevoNodo;
            cola[FIN1]=nuevoNodo;
        }
    }
}

int obtenerRanking(void *dato){
    void **aux=(void**)dato;
    int *ranking=(int*)aux[3];
    return *ranking;
}

void crearNodo(void **&nuevoNodo,void *dato){
    nuevoNodo=new void*[2]{};
    nuevoNodo[DATO]=dato;
    nuevoNodo[SGTE]=nullptr;
}

void *desencola(void *cola){
    void **auxCola=(void**)cola;
    void **ini=(void**)auxCola[INI];
    void *dato;
    dato=ini[DATO];
    auxCola[INI]=ini[SGTE];
    delete ini;
    return dato;
}

bool colavacia(void *cola){
    void **aux=(void**)cola;
    return aux[INI]==nullptr;
}

// otra solu
//
//void generacola(void *&cola){
//    void **cuarteto = new void*[4];
//    void **nodo1,**nodo2,**nodo3;
//    
//    nodo1 = new void*[2];
//    nodo1[0] = nullptr;
//    nodo1[1] = nullptr;
//    cuarteto[3] = nodo1;
//    
//    nodo2 = new void*[2];
//    nodo2[0] = nullptr;
//    nodo2[1] = nodo1;
//    cuarteto[2] = nodo2;
//    
//    nodo3 = new void*[2];
//    nodo3[0] = nullptr;
//    nodo3[1] = nodo2;
//    cuarteto[1] = nodo3;
//    
//    cuarteto[0] = nodo3;
//    cola = cuarteto;
//}
//
//void encola(void *cola,void *dato){
//    void **cuarteto = (void**)cola;
//    void **nuevo,**aux,**sig;
//    int posPrio;
//    nuevo = new void*[2];
//    nuevo[0] = dato;
//    nuevo[1] = nullptr;
//    
//    posPrio = obtenerRanking(dato);
//    
//    aux = (void**)cuarteto[posPrio];
//    if(aux[0]==nullptr){
//        aux[0] = dato;
//    }else{
//        sig = (void**)aux[1];
//        cuarteto[posPrio] = nuevo;
//        aux[1] = nuevo;
//        nuevo[1] = sig;
//    }
//}
//
//bool colavacia(void *cola){
//    void **cuarteto = (void**)cola;
//    if(cuarteto[0]==nullptr) return true;
//    return false;
//}
//
//int obtienePosPrioridad(void *dato){
//    void **registroDat = (void**)dato;
//    int *ranking;
//    ranking = (int*)registroDat[3];
//    if(*ranking==1) return 3;
//    else if(*ranking==2) return 2;
//    else return 1;
//}
//
//void *desencola(void *cola){
//    
//    if(colavacia(cola)) return nullptr;
//    
//    void **cuarteto = (void**)cola;
//    void **colaIni = (void**)cuarteto[0];
//    void **penultimo,*dato;
//    
//    if(cuarteto[0]==cuarteto[3]){
//        cuarteto[0] = nullptr;
//        cuarteto[3] = nullptr;
//    }else{
//        if(cuarteto[1]==colaIni) cuarteto[1] = nullptr;
//        if(cuarteto[2]==colaIni) cuarteto[2] = nullptr;
//        penultimo = (void**)colaIni[1];
//        colaIni[1] = nullptr;
//        cuarteto[0] = penultimo;
//    }
//    dato = colaIni[0];
//    delete colaIni;
//    return dato;
//}