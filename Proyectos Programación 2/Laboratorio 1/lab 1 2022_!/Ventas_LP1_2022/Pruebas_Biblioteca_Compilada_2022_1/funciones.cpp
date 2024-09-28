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
    cout<<cliente.nombre<<endl;
    cout<<cliente.categoria<<endl;
    cout<<cliente.dni<<endl;
    return arch;
}
void     modificarNombre(char nombre[], char &categoria){
    int tamanio=strlen(nombre);
    int i;
    for ( i = tamanio-1; i>=0; i--) {
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
    cliente.montoTotalGastado+=pedido.cantidad;
     cliente.numeroDePedidos++;
}
void operator +=(struct Estructura_ProductosEnAlmacen productos[], struct Estructura_ProductosEnAlmacen &producto){
    int iden=buscar(producto.codigo, productos);
    int numero;
    if (iden==-1){
        int numero;
        if (productos[0].descuento==0){
            numero=0;
            productos[0]=producto;
            numero++;
            strcpy(productos[numero].codigo, "x");
        }else{
             productos[numero]=producto;
        }
    }
}
int buscar(char cod[], struct Estructura_ProductosEnAlmacen productos[]){
    for (int i = 0; productos[i].descuento!=0; i++) {
        if (strcmp(productos[i].codigo, cod)==0) return i;
    }
    return -1;
}
void operator <<(ofstream &arch, struct Estructura_ClienteRegistrado &cliente){
    arch<<"DNI" <<setw(20)<<"Nombre"<<endl;
    arch<<fixed<<setprecision(2);
    arch<<cliente.dni<<setw(5)<<' ';
    arch<<setw(50)<<left<<cliente.nombre<<endl;
    arch<<cliente.categoria<<endl;
    for (int i = 0; i < cliente.numeroDePedidos; i++) {
        arch<<i+1<<')'<<setw(4)<<' ';
        arch<<setw(10)<<left<<cliente.pedidosRealizados[i].codigo;
        arch<<setw(20)<<left<<cliente.pedidosRealizados[i].cantidad;
        arch<<setw(20)<<left<<cliente.pedidosRealizados[i].fecha;
    }
    arch<<endl<<"Monto total comprado: "<<cliente.montoTotalGastado<<endl;;
}
void operator <<(ofstream &arch, struct Estructura_ProductosEnAlmacen prod[]){
    for (int i = 0; strcmp(prod[i].codigo,"x")!=0; i++) {
        arch<<setw(2)<<setfill('0')<<i+1<<')'<<setfill(' ')<<setw(5)<<' '<<prod[i].codigo<<setw(60)
                <<left<<prod[i].descripcion<<right<<setw(7)<<prod[i].precioUnitario<<setw(10)<<prod[i].descuento<<endl;
    }
}
