/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
enum producto{
    DATOS, COLA
};
enum dats{
     CODIGO, DESCRIPCION, PRECIO, CANTI
};
#include "Pregunta02Examen01PunterosGenericos.h"
#define INCREMENTO 5
#define MAXLINEA 100
void   cargarProductos(void *&prod, const char *nombarch){
    //BIT-434,Campana Extractora modelo Glass,375.09,10
     ifstream arch(nombarch, ios::in);
    if (not arch.is_open())
    {
        cout<<"error con el archivo: "<<nombarch<<endl;
        exit(1);
    }
     void **productos=nullptr;
     void *reg;
     int nd=0, cap=0;
    while(true){
        reg=obtenerProducto(arch);
        if (arch.eof()) break;
        if (cap==nd){
            incrementarEspacio(productos, cap, nd);
        }
        productos[nd-1]=reg;
        nd++;
    }
     prod=productos;
     qsort(prod, nd-1, sizeof(void*), cmpVoid);
}
void *obtenerProducto(ifstream &arch){
    char *codigo=lecturaExacta2(arch);
    if (arch.eof()) return nullptr;
    char *decr=lecturaExacta2(arch);
    double precio, *pre=new double;
    int cant, *can=new int;
    arch>>precio;
    arch.get();
    arch>>cant;
    arch.get();
    *pre=precio;
    *can=cant;
    void **dats=new void*[4]{};
    dats[CODIGO]=codigo;
    dats[DESCRIPCION]=decr;
    dats[PRECIO]=pre;
    dats[CANTI]=can;
    void **registro=new void*[2]{};
    registro[DATOS]=dats;
    registro[COLA]=nullptr;
    return registro;
}
char *lecturaExacta2(ifstream &arch){
    char *aux, cadena[600]{};
    arch.getline(cadena, 600, ',');
    aux=new char[strlen(cadena)+1]{};
    strcpy(aux, cadena);
    return aux;
}
void incrementarEspacio(void **&productos, int &cap, int &nd){
        cap+=INCREMENTO;
    if (nd==0){
        productos=new void* [cap]{};
        nd++;
    }else{
        void **aux=new void*[cap]{};
        for (int i = 0; i < nd; i++) {
            aux[i]=productos[i];
        }
        delete productos;
        productos=aux;
    }
}
void pruebaDeCargaDeProductos(void *prod){
      ofstream arch("pruebaProductos.txt", ios::out);
    if (not arch.is_open()){
        cout<<"error con la apertura del archivo: "<<"pruebaProductos"<<endl;
        exit(1);
    }
      arch<<fixed<<setprecision(2);
      arch<<setw((MAXLINEA+20)/2)<<' '<<"REPORTE DE PRODUCTOS"<<endl;
      arch<<setw(15)<<right<<"Codigos"<<setw(16)<<"Descripcion"<<setw(60)<<"Precio"<<setw(10)<<"Cantidad"<<endl;
      void **productos=(void **)prod;
      for (int i = 0; productos[i]; i++) {
          impresionProd(productos[i], arch);
    }
      
}
void impresionProd(void *prod, ofstream &arch){
    void **reg=(void**)prod;
    void **datos=(void**)reg[DATOS];
    arch<<setw(15)<<right<<(char*)datos[CODIGO]<<setw(5)<<' '<<(char*)datos[DESCRIPCION]
            <<setw(60-strlen((char*)datos[DESCRIPCION]))<<' '
            <<setw(10)<<*(double*)datos[PRECIO]<<setw(10)<<*(int*)datos[CANTI]<<endl;
}
int  cmpVoid(const void*a, const void*b){
    void **regA=(void**)a;
    void **regB=(void**)b;
    void **miniA=(void**)regA[0];
    void **miniB=(void**)regB[0];
    void**datosA=(void**)miniA[0];
    void**datosB=(void**)miniB[0];
    char *cadA=(char*)datosA[CODIGO];
    char *cadB=(char*)datosB[CODIGO];
    return strcmp(cadA, cadB);
}