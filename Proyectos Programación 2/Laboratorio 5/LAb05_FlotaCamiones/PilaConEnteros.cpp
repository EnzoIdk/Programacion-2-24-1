#include "FlotaGenerica.h"
enum pila{INICIO,PESO};
enum camion{DATO,SIGUIENTE};

void* leenumero(ifstream &arch){
    double num,*numPtr;
    arch>>num;
    if(arch.eof()) return nullptr;
    numPtr=new double{num};
    return numPtr;
}

double calculanumero(double pesoMax,void* dato){
    double *peso=(double*)dato;
    return pesoMax-*peso;
}


int cmpnumero(const void*dato1,const void *dato2){
    void **A=(void**)dato1;
    void **B=(void**)dato2;
    void **A1=(void**)A[DATO];
    void **B1=(void**)B[DATO];
    double *a=(double *)A1[PESO];
    double *b=(double *)B1[PESO];
    if(*a<*b) return 1;
    else if(*a==*b) return 0;
    else return -1;
}

void imprimenumero(ofstream &arch,void *pila){
    if(pila!=nullptr){
        void **ant=(void**)pila;
        double *dato=(double*)ant[DATO];
        imprimenumero(arch,ant[SIGUIENTE]);
        arch<<*dato<<endl;
    }
}