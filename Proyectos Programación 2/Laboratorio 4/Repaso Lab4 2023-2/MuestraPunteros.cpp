/* 
 * File:   MuestraPunteros.cpp
 * Author: Lucas
 *
 * Created on 21 de abril de 2024, 19:28
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "MuestraPunteros.h"

#define MAXLINEA 120

enum Producto{COD, DESC, PREC, TIPO};
enum Cliente{DNI, NOMB, LISTA, LINEA};
enum Pedido{CANT=1, TOTAL};

void imprimeProductos(const char * nombArch, void * productos){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    void ** auxProd=(void ** )productos;
    
    arch<<fixed<<setprecision(2);
    for(int i=0; auxProd[i]; i++){
        imprimirProducto(arch, auxProd[i]);
    }
}

void imprimirProducto(ofstream &arch, void * producto){
    void ** prodFinal=(void ** )producto;
    char * cod, * desc, * tipo;
    double * precio;
    //EXTRACCION
    cod=(char * )prodFinal[COD];
    desc=(char * )prodFinal[DESC];
    tipo=(char * )prodFinal[TIPO];
    precio=(double * )prodFinal[PREC];
    //IMPRESION
    arch<<cod<<" - "<<left<<setw(60)<<desc<<right<<setw(5)<<*tipo<<setw(10)<<
            *precio<<endl;
}

void imprimeClientes(const char * nombArch, void * clientes){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    void ** arrClientes=(void ** )clientes;
    arch<<fixed<<setprecision(2);
    for(int i=0; arrClientes[i]; i++){
        imprimirCliente(arch, arrClientes[i]);
    }
}

void imprimirCliente(ofstream &arch, void * cliente){
    void ** auxCliente=(void ** )cliente;
    int * dni; 
    double * linea;
    char * nombre;
    //EXTRACCION
    dni=(int * )auxCliente[DNI];
    linea=(double * )auxCliente[LINEA];
    nombre=(char * )auxCliente[NOMB];
    //IMPRESOIN
    arch<<*dni<<" - "<<left<<setw(60)<<nombre<<right<<setw(10)<<*linea<<endl;
}

void imprimeReporte(const char * nombArch, void * clientes){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    void ** arrClientes=(void ** )clientes;
    arch<<fixed<<setprecision(2);
    for(int i=0; arrClientes[i]; i++){
        imprimirLinea(arch, MAXLINEA, '=');
        arch<<"DNI"<<setw(18)<<"Nombre"<<setw(68)<<"Credito"<<endl;
        imprimirPedidosPorCliente(arch, arrClientes[i]);
    }
}

void imprimirLinea(ofstream &arch, int largo, char car){
    for(int i=0; i<largo; i++) arch<<car;
    arch<<endl;
}

void imprimirPedidosPorCliente(ofstream &arch, void *cliente){
    void ** auxCliente=(void ** )cliente;
    int * dni=(int * )auxCliente[DNI];;
    double * linea=(double * )auxCliente[LINEA];
    char * nombre=(char * )auxCliente[NOMB];
    //IMPRESION
    arch<<left<<setw(15)<<*dni<<setw(60)<<nombre<<right<<setw(15)<<*linea<<endl;
    imprimirLinea(arch, MAXLINEA, '-');
    
    arch<<"Pedidos atendidos:"<<endl;
    imprimirLinea(arch, MAXLINEA, '-');
    arch<<"Codigo"<<setw(15)<<"Cantidad"<<setw(14)<<"Total"<<endl;
    imprimirLinea(arch, MAXLINEA, '-');
    
    if(auxCliente[LISTA]) imprimirLista(arch, auxCliente[LISTA]);
    else arch<<"NO TIENE PEDIDOS"<<endl;
    arch<<endl;
}

void imprimirLista(ofstream &arch, void * lista){
    void ** auxLista=(void ** )lista;
    for(int i=0; auxLista[i]; i++){
        imprimePedidoParcial(arch, auxLista[i]);
    }
}

void imprimePedidoParcial(ofstream &arch, void * pedido){
    void ** auxPedido=(void ** )pedido;
    char * cod=(char * )auxPedido[COD];
    int * cant=(int * )auxPedido[CANT];
    double * total=(double * )auxPedido[TOTAL];
    //IMPRESION
    arch<<cod<<setw(10)<<*cant<<setw(18)<<*total<<endl;
}