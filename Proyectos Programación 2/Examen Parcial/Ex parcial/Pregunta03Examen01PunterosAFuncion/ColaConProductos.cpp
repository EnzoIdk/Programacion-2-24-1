/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ColaConProductos.h"
#include "ColaGenerica.h"

void procesarPedidos(int**fecha, char**codProd, void *&prod){
    void **productosDesc=(void**)prod;
    int idProd;
    for (int i = 0;fecha[i] ; i++) {
        idProd=buscarProd(codProd[i], prod);
        if (verificarStock(productosDesc[idProd])){
            crearColita(productosDesc[idProd],fecha[i] );
        }
    }     
}
int buscarProd(char*cod, void *prod){
    void **productos=(void **)prod;
    for (int i = 0; productos[i]; i++) {
        if (compararproductos(cod, productos[i])) return i;
    }
    return -1;
}
bool compararproductos(char*cod, void*prod){
    void **productos=(void **)prod;
    void**registro=(void**)productos[0];
    char *codigo=(char*)registro[0];
    if( strcmp(codigo, cod)==0) return true;
    else return false;
}
bool verificarStock(void *prod){
    void **productos=(void **)prod;
    void**registro=(void**)productos[0];
    int *stock=(int *)registro[3];
    if (*stock>0) return true;
    else return false;
}
void crearColita(void *&prod, int *pedido){
    void **productos=(void **)prod;
    void**registro=(void**)productos[0];
    int *pedidoC;
   if (productos[1]==nullptr){
      crearCola(productos[1]);
   }
    encolar(productos[1], pedido);
    void **cabeza=(void**)productos[1];//cabeza no apuntaba a nada, porque la asigne primero
    int cantPedidos=*(int*)cabeza[2];
    cantPedidos+=pedido[2];
    *(int*)cabeza[2]=cantPedidos;//agregarle la cantidad del pedido
    if ( ((*(int*)registro[3])-pedido[2])>0) (*(int*)registro[3])-=pedido[2];//actualizar
    else (*(int*)registro[3])=0;
}

void reporteDePedidos(void *prod, const char *nombarch){
    ofstream arch(nombarch,ios::out);
    if (not arch.is_open()){
        cout<<"error con la apertura del archivo: "<<nombarch<<endl;
        exit(1);
    }
    void **productos=(void**)prod;
    for (int i = 0; productos[i]; i++) {
        impresionProductos(productos[i], i, arch);
    }

}
void impresionProductos(void *prod, int ind,ofstream &arch){
     void **productos=(void**)prod;
     impresionRegistro(productos[0], ind,arch);
    if (productos[1]!=nullptr) impresionLista(productos[1], arch);

}
void impresionRegistro(void *prod, int ind,ofstream &arch){
    void **productos=(void**)prod;
    arch<<"Producto: "<<ind+1<<endl;
    arch<<setw(10)<<left<<(char*)productos[0]<<setw(3)<<' '<<(char*)productos[1]
            <<setw(60-strlen((char*)productos[1]))<<' '<<endl<<right<<"Precio: "<<setw(15)<<*(double*)productos[2]
            <<setw(5)<<' '<<"Stock: "<<setw(10)<<*(int*)productos[3]<<endl;
}
void impresionLista(void *cola,  ofstream &arch){
    arch<<"Pedidos aceptados"<<endl;
    arch<<setw(8)<<"Fecha"<<setw(11)<<"DNI"<<setw(17)<<"Cantidad"<<endl;
    while(!colavacia(cola)){
        void *numero=desencolar(cola);
        impresionPedido(numero, arch);
        void **eliminar=(void**)numero;
        delete eliminar;
    }
}
void  impresionPedido(void *prod,  ofstream &arch){
    void **produ=(void**)prod;
    int fecha=(int)produ[0];
    int dni=(int)produ[1];
    int cant=(int)produ[2];
    arch<<right<<setw(10)<<fecha<<setw(10)<<dni<<setw(15)<<cant<<endl;
}
