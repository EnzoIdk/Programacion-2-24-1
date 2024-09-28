/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaPilaGenerica.h"
using namespace std;


void abrirArchLeer(ifstream &arch,const char*nombArch){
    arch.open(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: NO se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}

void abrirArchEscribir(ofstream &arch,const char*nombArch){
    arch.open(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: NO se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}

void cargaarreglo(void*&arreglo,int(*cmp)(const void*,const void*),
        void*(*lee)(ifstream &),const char*nombArch){
    ifstream arch;
    abrirArchLeer(arch,nombArch);
    void*buff[500]{},*reg,**arr;
    int n=0;//Num datos
    while(true){
        reg = lee(arch);
        if(arch.eof())break;
        buff[n] = reg;
        n++;
    }
    arr = new void*[n+1]{};
    for(int i=0;i<=n;i++) arr[i] = buff[i];
    qsort(arr,n,sizeof(int),cmp);
    arreglo = arr;
}

void cargapila(void*&pila,void*arreglo){
    void**aux=(void**)arreglo;
    generapila(pila);
    for(int i=0;aux[i];i++)
        push(pila,aux[i]);
}

void generapila(void*&pila){
    void**cabeza;
    int*n;//Numero de elementos de la pila
    n = new int;
    *n=0;
    cabeza = new void*[2]{};
    cabeza[0] = nullptr;
    cabeza[1] = n;
    pila = cabeza;
}

void push(void*&pila,void*aux){
    void**tad = (void**)pila,**nuevo;
    int*nDat = (int*)tad[1];
    nuevo = new void*[2];
    nuevo[0] = tad[0];
    nuevo[1] = aux;
    tad[0] = nuevo;
    (*nDat)++;
}

void muevepila(void*&pilaini,void*&pilafin){
    void*pilaaux,**ini=(void**)pilaini;
    int*n = (int*)ini[1];//Numero de elementos en la pilaIni
    generapila(pilafin);
    generapila(pilaaux);
    hanoi(*n,pilaini,pilaaux,pilafin);
}

void hanoi(int n,void*&pilaini,void*&pilaaux,void*&pilafin){
    void*reg;
    if(n==1){
        push(pilafin,pop(pilaini));
        return;
    }else{
        hanoi(n-1,pilaini,pilafin,pilaaux);
        push(pilafin,pop(pilaini));
        hanoi(n-1,pilaaux,pilaini,pilafin);
    }
}

void *pop(void*&pilaini){
    void**tad=(void**)pilaini,**aux,*dato=nullptr;
    int *nDat;
    if(!esPilaVacia(pilaini)){
        aux = (void**)tad[0];
        dato = aux[1];
        tad[0] = aux[0];
        delete aux;
        nDat = (int*)tad[1];
        (*nDat)--;
    }
    return dato;
}

bool esPilaVacia(void*&pilaini){
    void**tad=(void**)pilaini;
    return tad[0]==nullptr;
}

void imprimepila(void*pilafin,void(*imprime)(ofstream &,void*),
        const char*nombArch){
    ofstream arch;
    abrirArchEscribir(arch,nombArch);
    void**tad = (void**)pilafin;
    int*nDat = (int*)tad[1];
    void**rec=(void**)tad[0];
    for(int i=0;i<(*nDat);i++){
        imprime(arch,rec[1]);
        rec = (void**)rec[0];
    }
}