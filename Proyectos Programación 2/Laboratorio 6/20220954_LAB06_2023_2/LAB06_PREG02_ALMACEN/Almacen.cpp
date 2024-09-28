/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Almacen.cpp
 * Author: aml
 * 
 * Created on 22 de mayo de 2024, 01:12 PM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Almacen.h"
#define NO_ENCONTRADO -1
#define TAM_LINEA 140

Almacen::Almacen() {
    cantidad_clientes=0;
    cantidad_productos=0;
}

Almacen::Almacen(const Almacen& orig) {
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}

void Almacen::cargar_clientes(){
    ifstream archCli("Clientes.csv",ios::in);
    if(not archCli.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Clientes.csv"<<endl;
        exit(1);
    }
    for(cantidad_clientes;archCli>>arreglo_clientes[cantidad_clientes];cantidad_clientes++);
//    cout<<cantidad_clientes<<endl;
}

void Almacen::cargar_productos(){
    ifstream archProd("Productos.csv",ios::in);
    if(not archProd.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Productos.csv"<<endl;
        exit(1);
    }
    for(cantidad_productos;archProd>>arreglo_productos[cantidad_productos];cantidad_productos++);
//    cout<<cantidad_productos<<endl;
}

void Almacen::cargar_pedidos(){
    ifstream archPed("Pedidos.csv",ios::in);
    if(not archPed.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos.csv"<<endl;
        exit(1);
    }
    Pedido ped;
    char codPed[8];
    int dniPed,posProd,posCli;
    double precioPed;
    while(archPed>>ped){
        dniPed=ped.GetDni_cliente();
        ped.GetCodigo(codPed);
        posProd=buscarProd(arreglo_productos,cantidad_productos,codPed);
        posCli=buscarCli(arreglo_clientes,cantidad_clientes,dniPed);
        if(posProd!=NO_ENCONTRADO and posCli!=NO_ENCONTRADO){
            precioPed=arreglo_productos[posProd].GetPrecio();
            ped.SetPrecio_producto(precioPed);
            /*si es V, se agrega a los clientes*/
            if(arreglo_productos[posProd]+=ped){
                arreglo_clientes[posCli]+=ped;
            }
        }
    }
}

int buscarProd(Producto *arreglo,int cant,char *codPed){
    char codProd[8];
    for(int i=0;i<cant;i++){
        arreglo[i].GetCodigo(codProd);
        if(strcmp(codProd,codPed)==0) return i;
    }
    return NO_ENCONTRADO;
}

int buscarCli(Cliente *arreglo,int cant,int dniPed){
    for(int i=0;i<cant;i++){
        if(arreglo[i].GetDni()==dniPed) return i;
    }
    return NO_ENCONTRADO;
}

void Almacen::mostrar_datos(){
    ofstream archRep("ReporteFinal.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteFinal.txt"<<endl;
        exit(1);
    }
    archRep<<"REPORTE DE CLIENTES"<<endl;
    imprimirLinea(archRep,TAM_LINEA,'=');
    archRep<<"CODIGO"<<setw(3)<<' '<<"NOMBRE"<<setw(30)<<' '<<"DNI"<<setw(3)<<
            ' '<<"MONTO TOTAL"<<' '<<"PRODUCTOS"<<endl;
    imprimirLinea(archRep,TAM_LINEA,'-');
    for(int i=0;i<cantidad_clientes;i++){
        archRep<<arreglo_clientes[i];
    }
    archRep<<endl;
    imprimirLinea(archRep,TAM_LINEA,'=');
    archRep<<"REPORTE DE PRODUCTOS"<<endl;
    imprimirLinea(archRep,TAM_LINEA,'=');
    archRep<<"CODIGO"<<setw(4)<<' '<<"DESCRIPCION"<<setw(45)<<' '<<"PRECIO"<<
            setw(2)<<' '<<"STOCK FINAL"<<endl;
    imprimirLinea(archRep,TAM_LINEA,'-');
    for(int i=0;i<cantidad_productos;i++){
        archRep<<arreglo_productos[i];
        imprimirLinea(archRep,TAM_LINEA,'-');
    }
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}


