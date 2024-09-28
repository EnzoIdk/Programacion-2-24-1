/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
   
using namespace std;

#include "Estructuras.h"
#include "AperturaDeArchivos.h"     
#include "Ventas_LP1_20221.h"


ifstream & operator>>(ifstream &arch,struct Estructura_ClienteRegistrado &cliente){
    arch>>cliente.dni;
    if(arch.eof()){
        cliente.dni=0;
        return arch;
    }
    arch>>cliente.nombre>>cliente.telefono;
    int tam=strlen(cliente.nombre);
    if(cliente.nombre[tam-2]=='-'){
        asignarCategoria(cliente.categoria,cliente.nombre[tam-1]);
        cliente.nombre[tam-2]=0;
    }
    else strcpy(cliente.categoria,"Cliente nuevo");
    cliente.montoTotalGastado=0;
    cliente.numeroDePedidos=0;
    return arch;
}

void asignarCategoria(char *categoria,char tipo){
    if(tipo=='A') strcpy(categoria,"Cliente muy frecuente");
    else if(tipo=='B') strcpy(categoria,"Cliente frecuente");
    else strcpy(categoria,"Cliente ocasional");
}

void operator +=(struct Estructura_ClienteRegistrado *arreglo,
        struct Estructura_ClienteRegistrado &cliente){
    int i=0;
    while(true){
        if(arreglo[i].dni==0){
            arreglo[i]=cliente;
            arreglo[i+1].dni=0;
            break;
        }
        i++;
    }
}

void operator +=(struct Estructura_ClienteRegistrado &cliente,
        struct Estructura_PedidoRealizado pedido){
    cliente.pedidosRealizados[cliente.numeroDePedidos]=pedido;
    cliente.numeroDePedidos++;
    int monto=pedido.cantidad*pedido.precioUnitario;
    cliente.montoTotalGastado+=monto*(1-pedido.descuento/100);
}

void operator +=(struct Estructura_ProductosEnAlmacen *arreglo,
        struct Estructura_ProductosEnAlmacen producto){
    int i=0;
    while(true){
        if(strcmp(arreglo[i].codigo,producto.codigo)==0){
            cout<<"El producto del codigo "<<producto.codigo<<" ya se encuentra"<<endl;
            break;
        }
        if(strcmp(arreglo[i].codigo,"X")==0){
            arreglo[i]=producto;
            strcpy(arreglo[i+1].codigo,"X");
            break;
        }
        i++;
    }
}

void operator <<(ofstream &arch,struct Estructura_ClienteRegistrado cliente){
    arch<<setw(2)<<' '<<"DNI"<<setw(4)<<' '<<"NOMBRE"<<endl;
    arch<<cliente.dni<<setw(4)<<' '<<cliente.nombre<<endl<<cliente.categoria<<endl;
    arch<<left<<setw(4)<<"No."<<setw(6)<<"CODIGO"<<right<<setw(18)
            <<"CANTIDAD"<<setw(18)<<"FECHA"<<endl;
    for(int i=0;i<cliente.numeroDePedidos;i++){
        arch << right << setfill('0')<<setw(2)<<i+1<<setfill(' ')
                <<left<<") " << setw(6) <<cliente.pedidosRealizados[i].codigo << right << setw(18)
                <<cliente.pedidosRealizados[i].cantidad <<setw(11)<< ' ';
        imprimirFecha(arch,cliente.pedidosRealizados[i].fecha);
        arch<<endl;
    }
    arch<<"Monto total comprado: "<<cliente.montoTotalGastado<<endl;
}

void imprimirFecha(ofstream &arch,int fecha){
    int aa=fecha/10000;
    int mm=(fecha/100)%100;
    int dd=fecha%100;
    arch<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa<<
            setfill(' ');
}

void operator<<(ofstream &arch,struct Estructura_ProductosEnAlmacen *arr){
    arch<<setw(50)<<"PRODUCTOS ALMACENADOS"<<endl;
    arch<<"No."<<setw(10)<<"Codigo"<<setw(10)<<' '
            <<left<<setw(20)<<"Descripcion"<<right
            <<setw(33)<<"Precio unitario"<<setw(17)<<"Descuento"<<endl;
    int i=0;
    while(strcmp(arr[i].codigo,"X")!=0){
        arch<<setfill('0')<<setw(2)<<i+1<<')'<<setfill(' ')
                <<setw(10)<<arr[i].codigo<<left<<setw(10)<<' '
                <<setw(20)<<arr[i].descripcion<<right<<setw(20)
                <<arr[i].precioUnitario<<setw(20)<<arr[i].descuento<<endl;
        i++;
    }
}