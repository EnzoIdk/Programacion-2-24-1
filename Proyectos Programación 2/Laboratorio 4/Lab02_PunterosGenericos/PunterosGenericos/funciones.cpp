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
#define NO_ENCONTRADO -1
#define TAM_LINEA 120

enum Reg{COD,TIT,AUT,STOCK,NOATEND,PRECIO};
enum PedCli{DNI,CANT,LISTA_PED};
enum PedLib{CODLIB,ATEND};

void leerLibros(const char *nombArch,void *&lib){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *bufferLib[300]{},**libros,*reg;
    int numDat=0;
    while(true){
        reg=leerRegLib(arch);
        if(arch.eof()) break;
        bufferLib[numDat]=reg;
        numDat++;
    }
    libros=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) libros[i]=bufferLib[i];
    lib=libros;
}

void *leerRegLib(ifstream &arch){
    void **registro=new void*[6]{};
    char *codigo,*titulo,*autor;
    double *precio=new double;
    int *stock=new int,*cantNA=new int;
    codigo=leerCadena(arch);
    if(arch.eof()) return nullptr;
    titulo=leerCadena(arch);
    autor=leerCadena(arch);
    arch>>*stock;
    arch.get();
    arch>>*precio;
    arch.get();
    *cantNA=0;
    registro[COD]=codigo;
    registro[TIT]=titulo;
    registro[AUT]=autor;
    registro[STOCK]=stock;
    registro[NOATEND]=cantNA;
    registro[PRECIO]=precio;
    return registro;
}

char *leerCadena(ifstream &arch){
    char cadena[60],*ptr;
    arch.getline(cadena,60,',');
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void mostrarLibros(const char *nombArch,void *lib){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **libros=(void**)lib;
    for(int i=0;libros[i];i++){
        imprimirLibro(arch,libros[i]);
    }
}

void imprimirLibro(ofstream &arch,void *lib){
    void **libro=(void**)lib;
    char *codigo=(char*)libro[COD],*titulo=(char*)libro[TIT],*autor=(char*)libro[AUT];
    int *stock=(int*)libro[STOCK],*cantNA=(int*)libro[NOATEND];
    double *precio=(double*)libro[PRECIO];
    arch<<codigo<<setw(3)<<' '<<left<<setw(60)<<titulo<<setw(40)<<autor<<
            right<<setw(10)<<*stock<<setw(10)<<*cantNA<<setw(10)<<*precio<<endl;
}

void atenderPedidos(const char *nombArch,void *lib,void *&pedCli,void *&pedLib){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *buffPedCli[200]{},*buffPedLib[200]{},**libros=(void**)lib;
    int numPed,dni,posCli,numCli=0;
    while(true){
        leerPrimerosDatos(arch,numPed,dni);
        if(arch.eof()) break;
        posCli=buscarCli(dni,buffPedCli);
        if(posCli==NO_ENCONTRADO){
            agregarCliente(dni,buffPedCli[numCli]);
            posCli=numCli;
            numCli++;
        }
        registrarPedidos(arch,libros,buffPedCli[posCli],buffPedLib[numPed],numPed);
    }
}

void leerPrimerosDatos(ifstream &arch,int &numPed,int &dni){
    arch>>numPed;
    if(arch.eof()) return;
    arch.get();
    arch>>dni;
}

int buscarCli(int dni,void **buffPedCli){
    for(int i=0;buffPedCli[i];i++){
        if(esCliente(dni,buffPedCli[i])) return i;
    }
    return NO_ENCONTRADO;
}

bool esCliente(int dni,void *pedCli){
    void **pedidoCli=(void**)pedCli;
    int *dniPedCli=(int*)pedidoCli[DNI];
    return dni==*dniPedCli;
}

void agregarCliente(int dni,void *&pedCli){
    void **pedidoCli=(void**)pedCli;
    int *dniPedCli=new int;
    int *cantPedCli=new int;
    int *pedidos=new int[20]{};
    *dniPedCli=dni;
    *cantPedCli=0;
    pedidoCli=new void*[3]{};
    pedidoCli[DNI]=dniPedCli;
    pedidoCli[CANT]=cantPedCli;
    pedidoCli[LISTA_PED]=pedidos;
//    pedCli=pedidoCli;
}

void registrarPedidos(ifstream &arch,void **libros,void *pedCli,void *&pedLib,int numPed){
    void **pedidoCli=(void**)pedCli;
    int *ndPedCli=(int*)pedidoCli[CANT];
    int *lista=(int*)pedidoCli[LISTA_PED];
    agregarPedCli(lista,*ndPedCli,numPed);
    char codigo[8]{};
    while(true){
        arch>>codigo;
        
        if(arch.get()=='\n') return;
    }
}

void agregarPedCli(int *lista,int &nd,int numPed){
    lista[nd]=numPed;
    nd++;
}