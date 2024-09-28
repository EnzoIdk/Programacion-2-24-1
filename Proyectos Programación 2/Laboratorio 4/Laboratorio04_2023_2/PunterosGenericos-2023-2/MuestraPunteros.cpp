/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

void imprimeProductos(void *prod){
    void **productos=(void**)prod;
    for(int i=0;productos[i];i++){
        imprimirProd(productos[i]);
    }
}

void imprimirProd(void *prod){
    void **productos=(void**)prod;
    char *codigo=(char*)productos[0];
    char *descripcion=(char*)productos[1];
    double *precio=(double*)productos[2];
    char *tipo=(char*)productos[3];
    cout<<left<<setw(10)<<codigo<<setw(60)<<descripcion<<right<<
            setw(7)<<*precio<<setw(5)<<*tipo<<endl;
}

void imprimeClientes(void *cli){
    void **clientes=(void**)cli;
    for(int i=0;clientes[i];i++){
        imprimirCli(clientes[i]);
    }
}

void imprimirCli(void *cli){
    void **clientes=(void**)cli;
    int *dni=(int*)clientes[0];
    char *nombre=(char*)clientes[1];
    double *linea=(double*)clientes[3];
    cout<<*dni<<setw(4)<<' '<<left<<setw(50)<<nombre<<right<<setw(10)<<*linea<<endl;
    if(clientes[2]) imprimirPedidos(clientes[2]);
}

void imprimirPedidos(void *ped){
    void **pedidos=(void**)ped;
    for(int i=0;pedidos[i];i++){
        imprimirPed(pedidos[i]);
    }
}

void imprimirPed(void *ped){
    void **pedido=(void**)ped;
    int *cantidad=(int*)pedido[1];
    char *codigo=(char*)pedido[0];
    double *total=(double*)pedido[2];
    cout<<setw(4)<<' '<<codigo<<setw(5)<<*cantidad<<setw(10)<<*total<<endl;
}

//void imprimeReporte(){
//    
//}