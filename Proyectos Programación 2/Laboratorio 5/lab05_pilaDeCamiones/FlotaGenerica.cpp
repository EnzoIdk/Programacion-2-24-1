/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FlotaGenerica.h"
enum nodo{
    VALOR, SIGUIENTE
};
enum camion{
    PILA, MAX
};

void cargacamiones(void *&flota, int numcamiones, int pesomaximo, void*(*leenumero)(ifstream &arch), 
       int(*calculanumero)(void*),ifstream &arch){
    void **auxFlota=new void*[numcamiones]{};
    for (int i = 0; i < numcamiones; i++) {
        void **camion=new void*[2]{};//esto concierte el máximo y la pila
        auxFlota[i]=camion;
    }
    int suma=0, indice=0;
    void *numero;
    int numMax[numcamiones]{};
    while(true){
        numero=leenumero(arch);
        if (arch.eof()) break;
        int num=calculanumero(numero);
        suma+=num;//peso de la carga
        if (suma<pesomaximo and indice<numcamiones-1 ){
            void **camion=(void**)auxFlota[indice];
            numMax[indice]=suma;
            push(camion[PILA], numero);
//           cout<<suma<<endl;
        }else if (indice<numcamiones-1){
            suma=num;
            indice++;
            void **camion=(void**)auxFlota[indice];
             numMax[indice]=num;
//             cout<<num<<endl;
            push(camion[PILA], numero);
        }
    }
    for (int i = 0; i < numcamiones; i++) {
        asiganarMax(numMax[i],auxFlota[i] );
        cout<<numMax[i]<<' ';
    }
    flota=auxFlota;
}
void asiganarMax(int num,void *camion ){
    void **dentro=(void**)camion;
    int *ptr=new int;
    *ptr=num;
    dentro[MAX]=ptr;
}

void push(void *&pila, void *numero){
    //Creo la nueva carga
    void **nuevo=new void*[2]{};
    nuevo[VALOR]=numero;

    if (pila==nullptr){
      pila=nuevo;
    }else{
//        void **anterior=(void**)pila;
//        anterior[SIGUIENTE]=nuevo;
        nuevo[SIGUIENTE]=pila;
         pila=nuevo;
    }
}
void muestracamiones(void *flota,int numcamiones, int pesomaximo,void(*imprimenumero)(ofstream &arch,void*),
        ofstream &arch){
    void **camion=(void**)flota;
    for (int i = 0; i < numcamiones; i++) {
        ingresarAPila(arch,i+1,camion[i], imprimenumero);
    }
 }
void   ingresarAPila(ofstream &arch, int ind,void *camion, void(*imprimenumero)(ofstream &arch,void*)){
    void **fila=(void**)camion;
    void **p=(void**)fila[PILA];
    arch<<"flota de camion "<<ind<<' '<<"Peso: "<<*(int*)fila[MAX]<<endl;
    while(p){
        imprimenumero(arch,p[VALOR]);
        p=(void**)p[SIGUIENTE];
    }
}

