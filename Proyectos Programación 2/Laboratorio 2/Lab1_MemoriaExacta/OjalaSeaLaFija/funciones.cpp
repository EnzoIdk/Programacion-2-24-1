/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>      
#include <cstring>

using namespace std;

#include "funciones.h"
#define TAM_LINEA 150
#define NO_ENCONTRADO -1

enum Libro{COD,TIT,AUT};

void leerLibros(const char *nombArch,char ***&libros,int *&stock,double *&precios){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char **bufferLibros[300]{};
    int bufferStock[300]{},numDatos=0;
    double bufferPrecios[300]{};
    while(true){
        bufferLibros[numDatos]=leerDatosLibro(arch);
        if(arch.eof()) break;
        arch>>bufferStock[numDatos];
        arch.get();
        arch>>bufferPrecios[numDatos];
        arch.get();
        numDatos++;
    }
    libros=new char**[numDatos+1]{};
    stock=new int[numDatos+1]{};
    precios=new double[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        precios[i]=bufferPrecios[i];
        libros[i]=bufferLibros[i];
        stock[i]=bufferStock[i];
    }
}

char **leerDatosLibro(ifstream &arch){
    char **libro;
    libro=new char*[3]{};
    libro[COD]=leerCadena(arch);
    if(arch.eof()) return nullptr;
    libro[TIT]=leerCadena(arch);
    libro[AUT]=leerCadena(arch);
    return libro;
}

char *leerCadena(ifstream &arch){
    char cadena[100],*ptr;
    arch.getline(cadena,100,',');
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void mostrarLibros(const char *nombArch,char ***libros,int *stock,double *precios){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char **aux;
    archReporte<<setprecision(2)<<fixed;
    archReporte<<"INFORMACION DE LIBROS"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'-');
    archReporte<<"CODIGO"<<setw(4)<<' '<<"TITULO"<<setw(54)<<' '<<"AUTOR"<<
            setw(41)<<' '<<"STOCK"<<setw(5)<<' '<<"PRECIO"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'=');
    for(int i=0;libros[i];i++){
        aux=libros[i];
        archReporte<<aux[COD]<<setw(3)<<' '<<left<<setw(60)<<aux[TIT]<<setw(40)<<
            aux[AUT]<<right<<setw(10)<<stock[i]<<setw(12)<<precios[i]<<endl;
//        imprimirDatosLibro(archReporte,libros[i],stock[i],precios[i]);
    }
}

//void imprimirDatosLibro(ofstream &archReporte,char **libros,int stock,double precio){
//    archReporte<<libros[COD]<<setw(3)<<' '<<left<<setw(60)<<libros[TIT]<<setw(40)<<
//            libros[AUT]<<right<<setw(10)<<stock<<setw(12)<<precio<<endl;
//}

void leerPedidos(const char *nombArch,char ***&codPedidos,int *&codClientePed){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char **bufferCodPedidos[1000]{};
    for(int i=0;i<1000;i++) bufferCodPedidos[i]=new char*[50]{};
    int bufferClientePed[150]{},nd[50]{},numDatos=0,posCliente;
    int random,codCliente;
    while(true){
        arch>>random;
        if(arch.eof()) break;
        arch.get();
        arch>>codCliente;
        arch.get();
        posCliente=buscarCliente(bufferClientePed,codCliente);
        if(posCliente==NO_ENCONTRADO){
            bufferClientePed[numDatos]=codCliente;
            agregarCodPedidos(arch,bufferCodPedidos[numDatos],nd[numDatos]);
            numDatos++;
        }
        else{
            agregarCodPedidos(arch,bufferCodPedidos[posCliente],nd[posCliente]);
        }
    }
    codPedidos=new char**[numDatos+1]{};
    codClientePed=new int[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        codClientePed[i]=bufferClientePed[i];
        espaciosExactosCodPed(codPedidos[i],bufferCodPedidos[i],nd[i]);
    }
}

void espaciosExactosCodPed(char **&codPedido,char **&bufferCodPed,int nd){
    char **codPedidoAux;
    if(nd!=0){
        codPedidoAux=new char*[nd+1]{};
        for(int i=0;i<nd;i++) codPedidoAux[i]=bufferCodPed[i];
        delete bufferCodPed;
        codPedido=codPedidoAux;
    }
    else{
        delete bufferCodPed;
        codPedido=nullptr;
    }
}

void agregarCodPedidos(ifstream &arch,char **bufferCodPedidos,int &nd){
    char codigoLibro[8]{};
    while(true){
        arch>>codigoLibro;
        bufferCodPedidos[nd]=new char[strlen(codigoLibro)+1]{};
        strcpy(bufferCodPedidos[nd],codigoLibro);
        nd++;
        if(arch.get()=='\n') break;
    }
}

int buscarCliente(int *arreglo,int codigo){
    for(int i=0;arreglo[i];i++){
        if(codigo==arreglo[i]) return i;
    }
    return NO_ENCONTRADO;
}

void mostrarPedidos(const char *nombArch,char ***codigoPedidos,int *codClientePed){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archReporte<<"INFORMACION DE PEDIDOS"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'=');
    for(int i=0;codClientePed[i];i++){
        archReporte<<"Cliente: "<<codClientePed[i]<<endl<<"Pedidos: ";
        imprimirPedidos(archReporte,codigoPedidos[i]);
        imprimirLinea(archReporte,TAM_LINEA,'-');
    }
}

void imprimirPedidos(ofstream &archReporte,char **codPedidos){
    for(int i=0;codPedidos[i];i++){
        archReporte<<codPedidos[i]<<' ';
    }
    archReporte<<endl;
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}