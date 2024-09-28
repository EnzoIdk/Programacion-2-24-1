
/* 
 * File:   BibliotecaEstatica.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 3 de enero de 2024, 11:57 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Estruturas.h"
#include "BibliotecaEstatica.h"
#define PRECISION 0.001

ifstream & operator >>(ifstream &arch,struct Estructura_ClienteRegistrado &cliente){
    arch>>cliente.dni>>cliente.nombre>>cliente.telefono;
    int tam = strlen(cliente.nombre);
    if(cliente.nombre[tam-2]=='-'){
        AsignarCategoria(cliente.categoria,cliente.nombre[tam-1]);
        cliente.nombre[tam-2]=0;
    }
    cliente.numeroDePedidos = 0;
    cliente.montoTotalGastado = 0.0;
    return arch;
}

void AsignarCategoria(char *categoria,char tipo){
    switch(tipo){
        case 'A':{
            strcpy(categoria,"Cliente muy frecuente");
            break;
        }
        case 'B':{
            strcpy(categoria,"Cliente frecuente");
            break;
        }
        case 'C':{
            strcpy(categoria,"Cliente ocasional");
            break;
        }
        default:{
            strcpy(categoria,"Cliente nuevo");
            break;
        }
    }
}

ofstream & operator <<(ofstream &arch,
        const struct Estructura_ClienteRegistrado &cliente){
    arch<<setw(5)<<"DNI"<<setw(20)<<"NOMBRE"<<endl;
    arch<<cliente.dni<<setw(6)<<' '<<left<<setw(40)<<cliente.nombre<<right<<endl;
    arch<<cliente.categoria<<endl;
    arch<<left<<setw(4)<<"No."<<setw(6)<<"CODIGO"<<right<<setw(18)
            <<"CANTIDAD"<<setw(18)<<"FECHA"<<endl;
    ImprimirPedidos(cliente.pedidosRealizados,cliente.numeroDePedidos,arch);
    arch<<"Monto total comprado: "<<cliente.montoTotalGastado<<endl;
}

void ImprimirPedidos(const struct Estructura_PedidoRealizado *pedidosRealizados,
        int numeroDePedidos,ofstream &arch){
    for(int i=0;i<numeroDePedidos;i++){
        arch << right << setfill('0')<<setw(2)<<i+1<<setfill(' ')
                <<left<<") " << setw(6) 
                << pedidosRealizados[i].codigo << right << setw(18)
                << pedidosRealizados[i].cantidad << setw(11) 
                << ' ';
        ImprimirFecha(pedidosRealizados[i].fecha,arch);
        arch<<endl;
    }
}

void operator +=(struct Estructura_ClienteRegistrado* arr,
        const struct Estructura_ClienteRegistrado &cliente){
    int i = 0;
    while(true){ //Asumo que el arreglo es muy grande
        if(arr[i].dni == 0){
            arr[i] = cliente;
            break;
        }
        i++;
    }
}

void operator +=(struct Estructura_ClienteRegistrado &cliente,
        const struct Estructura_PedidoRealizado &pedido){
    int num = cliente.numeroDePedidos;
    cliente.pedidosRealizados[num] = pedido;
    cliente.numeroDePedidos++;
    int monto = pedido.cantidad*pedido.precioUnitario;
    cliente.montoTotalGastado+= (pedido.descuento>PRECISION and pedido.descuento<100)
            ?monto*(1 - pedido.descuento/100):monto;
}

void operator +=(struct Estructura_ProductosEnAlmacen *arr,
        const struct Estructura_ProductosEnAlmacen &producto){
    int i=0;
    while(true){ //Asumo que el arreglo es muy grande
        if(strcmp(arr[i].codigo,producto.codigo)==0){
            cout<<"El producto del codigo "<<producto.codigo<<" ya se encuentra"<<endl;
            break;
        }
        if(strcmp(arr[i].codigo,"X")==0){
            arr[i] = producto;
            strcpy(arr[i+1].codigo,"X");
            break;
        }
        i++;
    }
}

ofstream & operator <<(ofstream &arch,
        const struct Estructura_ProductosEnAlmacen *arr){
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

void ImprimirFecha(int fecha,ofstream &arch){
    arch<<setfill('0')<<setw(2)<<fecha%100<<'/'
            <<setw(2)<<(fecha%10000)/100<<'/'
            <<setw(4)<<fecha/10000<<setfill(' ');
}

