/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <ratio>
#include <regex>

using namespace std;

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
#define NO_ENCONTRADO -1

enum Prod{COD,DESC,PREC,TIP};
enum Cli{DNI,NOMB,LISTA,LIN};

void cargaProductos(void *&prod){
    ifstream arch("Productos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Productos2.csv"<<endl;
        exit(1);
    }
    void **productos=(void**)prod,*reg;
    void *buffProd[200]{};
    int numDat=0;
    while(true){
        reg=leerRegProd(arch);
        if(arch.eof()) break;
        buffProd[numDat]=reg;
        numDat++;
    }
    productos=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) productos[i]=buffProd[i];
    prod=productos;
//    imprimeProductos(productos);
}

void *leerRegProd(ifstream &arch){
    void **registro=new void*[4]{};
    char *codigo,*descripcion;
    double *precio=new double;
    char *tipo=new char;
    codigo=leerCadena(arch);
    if(arch.eof()) return nullptr;
    descripcion=leerCadena(arch);
    arch>>*precio;
    arch.get();
    arch>>*tipo;
    arch.get();
    registro[COD]=codigo;
    registro[DESC]=descripcion;
    registro[PREC]=precio;
    registro[TIP]=tipo;
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

void cargaClientes(void *&cli){
    ifstream arch("Clientes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Clientes2.csv"<<endl;
        exit(1);
    }
    void **clientes=(void**)cli,*reg;
    void *buffCli[200]{};
    int numDat=0;
    while(true){
        reg=leerRegCli(arch);
        if(arch.eof()) break;
        buffCli[numDat]=reg;
        numDat++;
    }
    clientes=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) clientes[i]=buffCli[i];
    cli=clientes;
//    imprimeClientes(cli);
}

void *leerRegCli(ifstream &arch){
    void **registro=new void*[4]{};
    int *dni=new int,telefono;
    double *linea=new double;
    char *nombre;
    arch>>*dni;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre=leerCadena(arch);
    arch>>telefono;
    arch.get();
    arch>>*linea;
    registro[0]=dni;
    registro[1]=nombre;
    registro[2]=nullptr;
    registro[3]=linea;
    return registro;
}

/*tipo S: requiere linea, tipo N: no requiere*/
void cargaPedidos(void *prod,void *cli){
    ifstream arch("pedidos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo pedidos2.csv"<<endl;
        exit(1);
    }
    void **productos=(void**)prod,**clientes=(void**)cli;
    char *codigo;
    int dni,cant,posProd,posCli,nd[200]{};
    while(true){
        codigo=leerCadena(arch);
        if(arch.eof()) break;
        arch>>dni;
        arch.get();
        arch>>cant;
        arch.get();
        posProd=buscarProd(codigo,productos);
        posCli=buscarCli(dni,clientes);
        if(posProd!=NO_ENCONTRADO and posProd!=NO_ENCONTRADO){
            colocarPedido(productos[posProd],clientes[posCli],nd[posCli],cant);
        }
    }
    memoriaExacta(cli,nd);
    imprimeClientes(cli);
}

void memoriaExacta(void *cli,int *nd){
    void **clientes=(void**)cli;
    for(int i=0;clientes[i];i++) asignarMemExacta(clientes[i],nd[i]);
}

void asignarMemExacta(void *cli,int nd){
    void **auxCliente=(void**)cli;
    void **lista=(void**)auxCliente[LISTA];
    void **arrPedidos=new void*[nd+1]{};
    for(int i=0;i<nd;i++){
        arrPedidos[i]=lista[i];
    }
    delete lista;
    auxCliente[LISTA]=arrPedidos;
}

int buscarProd(char *codigo,void **productos){
    for(int i=0;productos[i];i++){
        if(esProducto(codigo,productos[i])) return i;
    }
    return NO_ENCONTRADO;
}

bool esProducto(char *cod,void *prod){
    void **producto=(void**)prod;
    char *codigo=(char*)producto[COD];
    return strcmp(cod,codigo)==0;
}

int buscarCli(int dni,void **clientes){
    for(int i=0;clientes[i];i++){
        if(esCliente(dni,clientes[i])) return i;
    }
    return NO_ENCONTRADO;
}

bool esCliente(int dni,void *cli){
    void **cliente=(void**)cli;
    int *dniCli=(int*)cliente[0];
    return dni==*dniCli;
}

void colocarPedido(void *prod,void *cli,int &nd,int cant){
    void **auxProd=(void**)prod;
    void **auxCli=(void**)cli;
    double *precio=(double*)auxProd[PREC],*linea=(double*)auxCli[LIN],total;
    char *codigo=(char*)auxProd[COD],*tipo=(char*)auxProd[TIP];
    void *ped,**auxPed=(void**)ped;
    if(nd==0) auxCli[LISTA]=new void*[100]{};
    total=(*precio)*cant;
    if(*tipo=='S'){
        if(*linea>=total){
            *linea-=total;
            finalizarPedido(auxCli[LISTA],nd,codigo,cant,total);
            nd++;
        }
    }
    else{
        /*no se tiene que verificar la linea*/
        finalizarPedido(auxCli[LISTA],nd,codigo,cant,total);
        nd++;
    }
}

void finalizarPedido(void *ped,int nd,char *codigo,int cant,double total){
    void **pedido=(void**)ped;
    pedido[nd]=guardaPedido(codigo,cant,total);
}

void *guardaPedido(char *cod,int cant,double total){
    void **pedido=new void*[3]{};
    int *cantPed=new int;
    double *totalPed=new double;
    *cantPed=cant;
    *totalPed=total;
    pedido[0]=cod;
    pedido[1]=cantPed;
    pedido[2]=totalPed;
    return pedido;
}