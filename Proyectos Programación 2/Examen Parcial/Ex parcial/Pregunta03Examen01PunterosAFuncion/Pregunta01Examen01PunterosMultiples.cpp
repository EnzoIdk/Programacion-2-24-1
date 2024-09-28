/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

#include "Pregunta01Examen01PunterosMultiples.h"
#define INCREMENTO 5
#define MAXLINEA 60

using namespace std;
enum pedido{
    FECHA, DNI, CANT
};

void  cargarPedidos(int **&fechaClienteCantidad, char**&codigoDelProducto, const  char*nombarch){
    ifstream arch(nombarch, ios::in);
    if (not arch.is_open())
    {
        cout<<"error con el archivo: "<<nombarch<<endl;
        exit(1);
    }
    //JXD-139,50375303,6,24/08/2023
    fechaClienteCantidad=nullptr;
    codigoDelProducto=nullptr;
    int ndProd=0, capProd=0 ;
    int ndPedi=0, capPedi=0, idCod;
    int *pedi;
    char *codigo;
    while(true){
        codigo=lecturaExacta(arch);
        if (arch.eof()) break;
        pedi=obtenerPedido(arch);
        if (ndPedi==capPedi){
            incrementarPed(fechaClienteCantidad, codigoDelProducto, ndPedi, capPedi);
        }
        fechaClienteCantidad[ndPedi-1]=pedi;
        codigoDelProducto[ndPedi-1]=codigo;
        ndPedi++;
    }
        miQsort(fechaClienteCantidad,codigoDelProducto, 0, ndPedi-1);
}
    
void   miQsort(int **&fechaClienteCantidad,char **&codigoDelProducto, int izq, int der) {
    int limite, pos;
    if (izq>=der) return;
    pos=(izq+der)/2;
    cambiarInts(fechaClienteCantidad[izq], fechaClienteCantidad[pos]);
    cambiarChars(codigoDelProducto[izq], codigoDelProducto[pos]);
    limite=izq;
    for (int i = izq+1; i <der; i++) {
        if (compararEnteros(fechaClienteCantidad[i], fechaClienteCantidad[izq])>0){
            limite++;
            cambiarInts(fechaClienteCantidad[limite], fechaClienteCantidad[i]);
            cambiarChars(codigoDelProducto[limite], codigoDelProducto[i]);
        }
    }
    cambiarInts(fechaClienteCantidad[limite], fechaClienteCantidad[izq]);
    cambiarChars(codigoDelProducto[limite], codigoDelProducto[izq]);
    miQsort(fechaClienteCantidad,codigoDelProducto, izq, limite-1);
    miQsort(fechaClienteCantidad,codigoDelProducto, limite+1, der); 
}
void  cambiarInts(int *&fecha1, int *&fecha2){
    int *aux;
    aux=fecha1;
    fecha1=fecha2;
    fecha2=aux;
}
void cambiarChars(char *&fecha1, char *&fecha2){
    char *aux;
    aux=fecha1;
    fecha1=fecha2;
    fecha2=aux;
}
int compararEnteros(int *num1, int *num2){
    return num2[0]-num1[0];
}
int *obtenerPedido(ifstream &arch){
    int dni, cant, dd,mm,aa;
    char c;
    arch>>dni;
    arch.get();
    arch>>cant;
    arch.get();
    arch>>dd>>c>>mm>>c>>aa;
    int fecha=aa*10000+mm*100+dd;
    arch.get();
    int *arreglo=new int [3]{};
    arreglo[FECHA]=fecha;
    arreglo[DNI]=dni;
    arreglo[CANT]=cant;
    return arreglo;
}
void  incrementarPed(int **&fechaClienteCantidad, char **&codigoDelProducto,int& ndPedi, int &capPedi){
    capPedi+=INCREMENTO;
    if (ndPedi==0){
        fechaClienteCantidad=new int* [capPedi]{};
        codigoDelProducto=new char* [capPedi]{};
        ndPedi++;
    }else{
        int **aux=new int*[capPedi]{};
        char **Caux=new char*[capPedi]{};
        for (int i = 0; i < ndPedi; i++) {
            aux[i]=fechaClienteCantidad[i];
            Caux[i]=codigoDelProducto[i];
        }
        delete fechaClienteCantidad;
        delete codigoDelProducto;
        fechaClienteCantidad=aux;
        codigoDelProducto=Caux;
    }
}
char *lecturaExacta(ifstream &arch){
    char *aux, cadena[600]{};
    arch.getline(cadena, 600, ',');
    aux=new char[strlen(cadena)+1]{};
    strcpy(aux, cadena);
    return aux;
}

void pruebaDeCrargarDePedidos(int **fechaClientesCantidad, char **codigoDelPorducto,const char *nombarch){
    ofstream arch(nombarch, ios::out);
    if (not arch.is_open()){
        cout<<"error con la apertura del archivo: "<<nombarch<<endl;
        exit(1);
    }
    arch<<setw((MAXLINEA+15)/2)<<' '<<"REPORTE PEDIDOS"<<endl;
    arch<<right<<setw(14)<<"Codigo"<<setw(13)<<"Fecha"<<setw(13)<<"DNI"<<setw(20)<<"Cantidad"<<endl;
    for (int i = 0; fechaClientesCantidad[i]; i++) {
        imprimirMiniArregloPedidos(arch,  fechaClientesCantidad[i],codigoDelPorducto[i]);
    }
}
void  imprimirMiniArregloPedidos(ofstream &arch,  int *datos, char *prod ){ 
    arch<<setw(15)<<prod<<setw(15)<<datos[FECHA]<<setw(15)<<datos[DNI]<<setw(15)<<datos[CANT]<<endl;
}
int cmpEnteros(const void *a, const void *b){
    void **arregloA=(void **)a;
    void **arregloB=(void **)b;
    int *numA=(int *)arregloA[0];
    int *numB=(int *)arregloB[0];
    return numA[FECHA]-numB[FECHA];
}
int cmpChars(const void*a, const void*b){
     void **arregloA=(void **)a;
    void **arregloB=(void **)b;
    char *nomA=(char*)arregloA[0];
    char *nomB=(char*)arregloB[0];
    return strcmp(nomA, nomB);
}