/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

#include "Estructuras.h"
#include "funciones.h"
#include "sobrecargas.h"
using namespace std;

ifstream & operator >>(ifstream &arch,struct Estructura_ClienteRegistrado &cliente){
    int numero; 
    char LetraCat;
    arch>>cliente.dni;
    if (arch.eof()) {
        cout<<"Se terminó de leer clientes.txt"<<endl;
        return arch;
    }
    arch>>cliente.nombre;
    modificarNombre(cliente.nombre, LetraCat);
    if (LetraCat=='A') strcpy(cliente.categoria, "Cliente muy frecuente");
    if (LetraCat=='B') strcpy(cliente.categoria, "Cliente frecuente");
    if (LetraCat=='C') strcpy(cliente.categoria, "Cliente ocasional");
    if (LetraCat=='D') strcpy(cliente.categoria, "Cliente nuevo");
    arch>>numero;
    cliente.numeroDePedidos=0;
    cliente.montoTotalGastado=0;
    return arch;
}
void     modificarNombre(char nombre[], char &categoria){
    int tamanio=strlen(nombre);
    int i;
    for ( i = tamanio-1; i>0; i--) {
        if (nombre[i]=='-') break;
    }
    if (i==0) categoria='D';
    else{ 
        categoria=nombre[tamanio-1];
        nombre[tamanio-2]='\0';
    }
}
void operator += (struct Estructura_ClienteRegistrado clientes[], struct Estructura_ClienteRegistrado &cliente){
    int i;
    for ( i = 0; clientes[i].dni!=0; i++);
    clientes[i]=cliente;
    clientes[i+1].dni=0;
}
void operator +=(struct Estructura_ClienteRegistrado &cliente, struct Estructura_PedidoRealizado &pedido){
   cliente.pedidosRealizados[cliente.numeroDePedidos].cantidad=pedido.cantidad;
    cliente.pedidosRealizados[cliente.numeroDePedidos].fecha=pedido.fecha;
    strcpy(cliente.pedidosRealizados[cliente.numeroDePedidos].codigo,pedido.codigo);
     cliente.numeroDePedidos++;
}
void operator +=(struct Estructura_ProductosEnAlmacen productos[], struct Estructura_ProductosEnAlmacen &producto){
    int i;
    for ( i = 0; productos[i].precioUnitario!=0; i++) ;
    productos[i]=producto;
    strcpy(productos[i+1].codigo, "x");
}
int buscar(char cod[], struct Estructura_ProductosEnAlmacen productos[]){
    for (int i = 0; productos[i].precioUnitario!=0; i++) {
        if (strcmp(productos[i].codigo, cod)==0) return i;
    }
    return -1;
}
void operator <<(ofstream &arch, struct Estructura_ClienteRegistrado &cliente){
    arch<<"PEDIDOS POR CLIENTE"<<endl;
    arch<<"DNI" <<setw(20)<<right<<"Nombre"<<endl;
    arch<<fixed<<setprecision(2);
    arch<<cliente.dni<<setw(5)<<' ';
    arch<<setw(50)<<left<<cliente.nombre<<endl;
    arch<<cliente.categoria<<endl;
    arch<<setw(13)<<right<<"Codigo"<<setw(17)<<"Cantidad"<<setw(23)<<"Fecha"<<endl;
    for (int i = 0; i < cliente.numeroDePedidos; i++) {
        arch<<i+1<<')'<<setw(4)<<' ';
        arch<<setw(10)<<left<<cliente.pedidosRealizados[i].codigo;
        arch<<setw(14)<<right<<cliente.pedidosRealizados[i].cantidad;
        arch<<setw(15)<<' ';
        fechaImpresion(arch, cliente.pedidosRealizados[i].fecha);
    }
    arch<<endl<<"Monto total comprado: "<<cliente.montoTotalGastado<<endl;;
}
void operator <<(ofstream &arch, struct Estructura_ProductosEnAlmacen prod[]){
    arch<<setw((100+28)/2)<<"EMPRESA COMERCIALIZADORE ABC"<<endl<<setw((100+21)/2)
            <<"PRODUCTOS ALMACENADOS"<<endl;
    arch<<"No."<<setw(12)<<right<<"Codigo"<<setw(21)<<"Descripcion"<<setw(53)
            <<"Precio Unitario"<<setw(12)<<"Descuento"<<endl;
    arch<<fixed<<setprecision(2);
    for (int i = 0; strcmp(prod[i].codigo,"x")!=0; i++) {
        arch<<setw(3)<<setfill('0')<<right<<i+1<<')'<<setfill(' ')<<setw(5)<<' '<<prod[i].codigo<<setw(5)<<' '<<setw(60)
                <<left<<prod[i].descripcion<<right<<setw(7)<<prod[i].precioUnitario<<setw(10)<<prod[i].descuento<<endl;
    }
}
void fechaImpresion(ofstream &arch, int fecha){
    int aa=fecha/10000;
    int mm=(fecha%10000)/100;
    int dd=(fecha%10000)%100;
    arch<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<setfill(' ')<<endl;
}