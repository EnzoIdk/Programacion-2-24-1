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
#include "funciones.h"
#define TAM_LINEA 180

void leerClientes(ifstream &archClientes,struct Cliente *clientes){
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.csv");
    for(int i=0;archClientes>>clientes[i];i++);
}

void leerProductos(ifstream &archProductos,struct Producto *productos){
    AperturaDeUnArchivoDeTextosParaLeer(archProductos,"Productos.csv");
    for(int i=0;archProductos>>productos[i];i++);
}

void leerPedidos(ifstream &archPedidos,struct Pedido *pedidos,struct Cliente *clientes,
        struct Producto *productos){
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.csv");
    for(int i=0;archPedidos>>pedidos[i];i++){
        productos+=pedidos[i];
        clientes+=pedidos[i];
    }
}

void emitirReporte(struct Cliente *clientes,struct Producto *productos){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    archReporte<<setw(50)<<' '<<"INFORMACION DE CLIENTES"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'=');
    archReporte<<"DNI"<<setw(10)<<' '<<"NOMBRE"<<setw(42)<<' '<<
            "TELEFONO"<<setw(8)<<' '<<"MONTO TOTAL"<<setw(2)<<' '<<
            "LISTADO DE PRODUCTOS"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'-');
    for(int i=0;clientes[i].dni;i++){
         archReporte<<clientes[i];
         imprimirLinea(archReporte,TAM_LINEA,'-');
    }
    archReporte<<endl<<setw(50)<<' '<<"INFORMACION DE PRODUCTOS"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'=');
    archReporte<<"CODIGO"<<setw(4)<<' '<<"DESCRIPCION"<<setw(52)<<' '<<
            "PRECIO"<<setw(3)<<' '<<"STOCK FINAL"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'-');
    for(int i=0;strcmp(productos[i].codigo,"XXXXXXX")!=0;i++){
        archReporte<<productos[i];
        imprimirLinea(archReporte,TAM_LINEA,'-');
    }
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}