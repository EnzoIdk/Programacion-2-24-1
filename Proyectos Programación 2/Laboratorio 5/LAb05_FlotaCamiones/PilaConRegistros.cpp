#include "FlotaGenerica.h"
enum pedido{CODIGO,DNI,CANTIDAD,PESO};
enum pila{INICIO,PESOTOTAL};
enum camion{DATO,SIGUIENTE};

char*leeCadenaExacta(ifstream &arch,char c){
    char cadena[100],*aux;
    arch.getline(cadena,100,c);
    aux=new char[strlen(cadena)+1];
    strcpy(aux,cadena);
    return aux;
}

void *leeregistro(ifstream &arch){
    char *cadena,c;
    int *dni,*cantidad;
    double *peso;
    
    cadena=leeCadenaExacta(arch,',');
    if(arch.eof()){
        delete cadena;
        return nullptr;
    }
    dni=new int;
    cantidad=new int;
    peso=new double;
    arch>>*dni>>c>>*cantidad>>c>>*peso;
    arch.get();//para el enter
    void **reg=new void*[4];
    reg[CODIGO]=cadena;
    reg[DNI]=dni;
    reg[CANTIDAD]=cantidad;
    reg[PESO]=peso;
    return reg;
}

double calcularegistro(double pesoMax,void* dato){
    void**aux=(void**)dato;
    double *peso=(double*)aux[PESO];
    return pesoMax-*peso;
}

int cmpregistro(const void*dato1,const void *dato2){
    void **A=(void**)dato1;
    void **B=(void**)dato2;
    void **A1=(void**)A[DATO];
    void **B1=(void**)B[DATO];
    double *a=(double *)A1[PESOTOTAL];
    double *b=(double *)B1[PESOTOTAL];
    if(*a<*b) return 1;
    else if(*a==*b) return 0;
    else return -1;
}

void imprimeregistro(ofstream &arch,void *pila){
    if(pila!=nullptr){
        void **ant=(void**)pila;
        imprimeregistro(arch,ant[SIGUIENTE]);
        void **dato=(void**)ant[DATO];
        char *codigo=(char*)dato[CODIGO];
        int *cantidad=(int*)dato[CANTIDAD];
        double *peso=(double*)dato[PESO];
        arch<<setw(15)<<codigo<<setw(6)<<" "<<setw(2)<<*cantidad<<setw(8)<<*peso<<endl;
    }
}