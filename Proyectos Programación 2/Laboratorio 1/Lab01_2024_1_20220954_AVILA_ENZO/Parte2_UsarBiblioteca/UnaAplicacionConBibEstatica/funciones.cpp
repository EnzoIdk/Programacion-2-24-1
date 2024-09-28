/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 5 de abril de 2024, 08:06 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "BibliotecaEstatica.h"
#include "funciones.h"
#define NO_ENCONTRADO -1
#define TAM_LINEA 120

void leerLibros(ifstream &archLibros,struct Libro *libros,int &numLibros){
    for(numLibros=0;archLibros>>libros[numLibros];numLibros++);
//    for(int i=0;i<numLibros;i++) cout<<libros[i].codigo<<endl;
}

void leerClientes(ifstream &archClientes,struct Cliente *clientes,int &numClientes){
    for(numClientes=0;archClientes>>clientes[numClientes];numClientes++){
//        cout<<clientes[numClientes].nombre<<endl;
    }
//    cout<<clientes[56].nombre<<endl;
}

void leerPedidos(ifstream &archPedidos,struct Libro *libros,int numLibros,
        struct Cliente *clientes,int numClientes){
    struct LibroSolicitado libroPedido;
    int dni,posCliente;
    while(true){
        archPedidos>>libroPedido.numeroDePedido;
        if(archPedidos.eof()) break;
        archPedidos.get();
        archPedidos>>dni;
        posCliente=buscarCliente(clientes,numClientes,dni);
        if(posCliente!=NO_ENCONTRADO){
            archPedidos.get();
            while(true){
                archPedidos>>libroPedido.codigoDelLibro;
                libroPedido>>libros;
                
                if(archPedidos.get()=='\n') break;
            }
        }
        else while(archPedidos.get()!='\n');
        
    }
}

int buscarCliente(struct Cliente *clientes,int numClientes,int dni){
    for(int i=0;i<numClientes;i++){
        if(clientes[i].dni==dni) return i;
    }
    return NO_ENCONTRADO;
}

void emitirReporte(struct Libro *libros,int numLibros,struct Cliente *clientes,
        int numClientes){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    imprimirEncabezado(archReporte);
    for(int i=0;i<numLibros;i++) archReporte<<libros[i];
    archReporte<<endl;
    for(int i=0;i<numClientes;i++) archReporte<<clientes[i];
}

void imprimirEncabezado(ofstream &archReporte){
    archReporte<<"INFORMACION DE CLIENTES"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'-');
}

void imprimirLinea(ofstream &archReporte,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) archReporte.put(simbolo);
    archReporte<<endl;
}