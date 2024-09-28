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
#include "funciones.h"
#define NO_ENCONTRADO -1

bool operator >>(ifstream &arch,struct Cliente &cliente){
    arch>>cliente.dni;
    if(arch.eof()){
        cliente.dni=0; /*no estamos llevando la cuenta de la cantidad, 
                        así que piden colocar el último dni así*/
        return false;
    }
    arch.get();
    arch.getline(cliente.nombre,60,',');
    arch>>cliente.telefono;
    /*tambien piden inicializar los otros campos*/
    cliente.montoTotal=0;
    cliente.cantidadProductosEntrgados=0;
    return true;
}

bool operator >>(ifstream &arch,struct Producto &producto){
    arch.getline(producto.codigo,8,',');
    if(arch.eof()){
        strcpy(producto.codigo,"XXXXXXX");
        return false;
    }
    arch.getline(producto.descripcion,60,',');
    arch>>producto.precio;
    arch.get();
    arch>>producto.stock;
    arch.get(); /*es necesario comerse el enter*/
    /*tambien piden inicializar los otros campos*/
    producto.cantidadClientesNoServidos=0;
    producto.cantidadClientesServidos=0;
    return true;
}

bool operator >>(ifstream &arch,struct Pedido &pedido){
    arch.getline(pedido.CodigoProducto,8,',');
    if(arch.eof()){
        strcpy(pedido.CodigoProducto,"XXXXXXX");
        return false;
    }
    arch>>pedido.dniCliente;
    arch.get();
    pedido.precioProducto=0;
    return true;
}

/*agrega un pedido al arreglo de clientes*/
void operator +=(struct Cliente *clientes,struct Pedido pedido){
    int posCliente=buscarCliente(clientes,pedido.dniCliente);
    int numPedido;
    if(posCliente!=NO_ENCONTRADO){
        numPedido=clientes[posCliente].cantidadProductosEntrgados;
        strcpy(clientes[posCliente].productosEntregados[numPedido].codigo,pedido.CodigoProducto);
        clientes[posCliente].productosEntregados[numPedido].precio=pedido.precioProducto;
        clientes[posCliente].montoTotal+=pedido.precioProducto;
        clientes[posCliente].cantidadProductosEntrgados++;
    }
}

/*agrega un pedido al arreglo de productos*/
bool operator +=(struct Producto *productos,struct Pedido &pedido){
    int posProducto=buscarProducto(productos,pedido.CodigoProducto);
    int numServido,numNoServido;
    if(posProducto!=NO_ENCONTRADO){
        pedido.precioProducto=productos[posProducto].precio;
        numServido=productos[posProducto].cantidadClientesServidos;
        numNoServido=productos[posProducto].cantidadClientesNoServidos;
        if(productos[posProducto].stock>0){
            productos[posProducto].clientesServidos[numServido]=pedido.dniCliente;
            productos[posProducto].cantidadClientesServidos++;
            productos[posProducto].stock--;
            return true;
        }
        else{
            productos[posProducto].clientesNoServidos[numNoServido]=pedido.dniCliente;
            productos[posProducto].cantidadClientesNoServidos++;
            return false;
        }
    }
}

int buscarCliente(struct Cliente *clientes,int dni){
    for(int i=0;clientes[i].dni;i++){
        if(dni==clientes[i].dni) return i;
    }
    return NO_ENCONTRADO;
}

int buscarProducto(struct Producto *productos,const char *codigo){
    for(int i=0;strcmp(productos[i].codigo,"XXXXXXX")!=0;i++){
        if(strcmp(productos[i].codigo,codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

/*permite imprimir la información de UN cliente*/
void operator <<(ofstream &arch,struct Cliente cliente){
    arch<<setprecision(2)<<fixed;
    arch<<cliente.dni<<setw(3)<<' '<<left<<setw(50)<<cliente.nombre<<setw(15)<<
            cliente.telefono<<right<<setw(10)<<cliente.montoTotal<<setw(2)<<' '<<
            "Productos entregados: ";
    if(cliente.cantidadProductosEntrgados>0){
        for(int i=0;i<cliente.cantidadProductosEntrgados;i++){
            arch<<left<<setw(10)<<cliente.productosEntregados[i].codigo;
        }
    }
    else arch<<"NO SE LE ENTREGARON PRODUCTOS";
    arch<<endl;
}

/*permite imprimir la información de UN producto*/
void operator <<(ofstream &arch,struct Producto producto){
    arch<<setprecision(2)<<fixed;
    arch<<producto.codigo<<setw(3)<<' '<<left<<setw(60)<<producto.descripcion<<right<<
            setw(10)<<producto.precio<<setw(7)<<producto.stock<<endl;
    arch<<"Clientes atendidos:"<<setw(5)<<' ';
    if(producto.cantidadClientesServidos>0){
        for(int i=0;i<producto.cantidadClientesServidos;i++){
            arch<<producto.clientesServidos[i]<<setw(3)<<' ';
        }
    }
    else arch<<"NO SE ATENDIERON PEDIDOS";
    arch<<endl<<"Clientes no atendidos:"<<setw(2)<<' ';
    if(producto.cantidadClientesNoServidos>0){
        for(int i=0;i<producto.cantidadClientesNoServidos;i++){
            arch<<producto.clientesNoServidos[i]<<setw(3)<<' ';
        }
    }
    else arch<<"NO HAY CLIENTES SIN ATENDER";
    arch<<endl;
}