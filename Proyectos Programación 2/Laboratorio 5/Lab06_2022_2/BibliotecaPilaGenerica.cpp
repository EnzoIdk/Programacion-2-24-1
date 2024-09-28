/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>  
#include <cstdlib>

using namespace std;

#include "BibliotecaPilaGenerica.h"

enum Pila{INI,NUM};

void cargaarreglo(void *&arreglo,int (*cmp)(const void*,const void*),
        void *(*lee)(ifstream &),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *buffer[50]{},**registro,*dato;
    int nd=0;
    arreglo=nullptr;
    while(true){
        dato=lee(arch);
        if(arch.eof()) break;
        buffer[nd]=dato;
        nd++;
    }
    registro=new void*[nd+1]{};
    for(int i=0;i<nd;i++) registro[i]=buffer[i];
    qsort(registro,nd,sizeof(void*),cmp);
    arreglo=registro;
}

void cargapila(void *&pila,void *arreglo){
    void **aux=(void**)arreglo;
    generapila(pila);
    for(int i=0;aux[i];i++) push(pila,aux[i]);
}

void generapila(void *&pila){
    void **cabeza;
    int *n=new int{0};
    cabeza=new void*[2]{};
    cabeza[INI]=nullptr;
    cabeza[NUM]=n;
    pila=cabeza;
}

/*apilar*/
void push(void *&pila,void *aux){
    void **tad=(void**)pila,**nuevo;
    int *nDat=(int*)tad[NUM];
    nuevo=new void*[2];
    nuevo[0]=tad[INI];
    nuevo[1]=aux;
    tad[INI]=nuevo;
    (*nDat)++;
}

/*desapilar*/
void *pop(void *&pila){
    void **tad=(void**)pila,**aux,*dato=nullptr;
    int *numDat;
    if(!pilavacia(pila)){
        aux=(void**)tad[INI];
        dato=aux[1];
        tad[INI]=aux[0];
        delete aux;
        numDat=(int*)tad[NUM];
        (*numDat)--;
    }
    return dato;
}

void muevepila(void *&pilaini,void *&pilafin){
    void *pilaaux,**ini=(void**)pilaini;
    int *n=(int*)ini[NUM];
    generapila(pilafin);
    generapila(pilaaux);
    hanoi(*n,pilaini,pilaaux,pilafin);
}

void hanoi(int n,void *&pilaA,void *&pilaB,void *&pilaC){
    if(n==0) return;
    hanoi(n-1,pilaA,pilaC,pilaB);
    push(pilaC,pop(pilaA));
    hanoi(n-1,pilaB,pilaA,pilaC);
}

bool pilavacia(void *pila){
    void **tad=(void**)pila;
    return tad[INI]==nullptr;
}

void imprimepila(void *pila,void (*imprime)(ofstream &,void*),const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **tad=(void**)pila;
    int *numDat=(int*)tad[NUM];
    void **cabeza=(void**)tad[INI];
    arch<<setprecision(2)<<fixed;
    for(int i=0;i<(*numDat);i++){
        imprime(arch,cabeza[1]);
        cabeza=(void**)cabeza[0];
    }
}