/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "MuestraPunteros.h"        
#include "PunterosGenericos.h"

using namespace std;

#define INCREMENTO 5
#define NO_ENCONTRADO -1

enum Prod{COD,DESC,PRE,STOCK};
enum Ped{CODPED,DESCPED,CANTPED,DNIPED,FECHAPED,ESTADO};

void cargaproductos(void *&prod){
    ifstream arch("productos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo productos2.csv"<<endl;
        exit(1);
    }
    void **productos,*reg;
    int numDat=0,cap=0;
    while(true){
        reg=leerRegProd(arch);
        if(arch.eof()) break;
        if(numDat==cap) aumentarCap(productos,numDat,cap);
        productos[numDat-1]=reg;
        numDat++;
    }
    prod=productos;
    imprimeproductos(prod);
}

void *leerRegProd(ifstream &arch){
    void **registro=new void*[4]{};
    int *codigo=new int,*cant=new int;
    double *precio=new double;
    char *descripcion,car;
    arch>>*codigo;
    if(arch.eof()) return nullptr;
    arch.get();
    descripcion=leerCadena(arch,',');
    arch>>*precio>>car>>*cant;
    registro[COD]=codigo;
    registro[DESC]=descripcion;
    registro[PRE]=precio;
    registro[STOCK]=cant;
    return registro;
}

char *leerCadena(ifstream &arch,char delim){
    char cadena[60],*ptr;
    arch.getline(cadena,60,delim);
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void aumentarCap(void **&arreglo,int &nd,int &cap){
    cap+=INCREMENTO;
    void **aux=new void*[cap]{};
    if(nd==0) nd=1;
    else{
        for(int i=0;i<nd;i++) aux[i]=arreglo[i];
        delete arreglo;
    }
    arreglo=aux;
}

void cargapedidos(void *&ped){
    ifstream arch("pedidos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo pedidos2.csv"<<endl;
        exit(1);
    }
    void **pedidos,*reg;
    int numDat=0,cap=0;
    while(true){
        reg=leerRegPed(arch);
        if(arch.eof()) break;
        if(numDat==cap) aumentarCap(pedidos,numDat,cap);
        pedidos[numDat-1]=reg;
        numDat++;
    }
    ped=pedidos;
    imprimepedidos(ped);
}

void *leerRegPed(ifstream &arch){
    void **registro=new void*[6]{};
    int *codigo=new int,*cant=new int,*dni=new int,*fecha=new int,dd,mm,aa;
    char *descripcion,*estado=new char{'N'},car;
    arch>>*codigo;
    if(arch.eof()) return nullptr;
    arch.get();
    descripcion=leerCadena(arch,',');
    arch>>*cant>>car>>*dni>>car>>dd>>car>>mm>>car>>aa;
    *fecha=aa*10000+mm*100+dd;
    registro[CODPED]=codigo;
    registro[DESCPED]=descripcion;
    registro[CANTPED]=cant;
    registro[DNIPED]=dni;
    registro[FECHAPED]=fecha;
    registro[ESTADO]=estado;
    return registro;
}

void procesaclientes(void *prod,void *ped,void *&cli){
    ifstream arch("clientes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo clientes2.csv"<<endl;
        exit(1);
    }
    actualizarEstados(prod,ped);
    void **clientes,*reg;
    int numDat=0,cap=0,arrND[20]{},arrCap[20]{};
    while(true){
        reg=leerRegCli(arch);
        if(arch.eof()) break;
        if(numDat==cap) aumentarCap(clientes,numDat,cap);
        clientes[numDat-1]=reg;
        colocarPedidos(clientes[numDat-1],arrND[numDat-1],arrCap[numDat-1],ped);
        numDat++;
    }
    cli=clientes;
}

void colocarPedidos(void *cli,int &nd,int &cap,void *ped){
    void **cliente=(void**)cli,**pedidos=(void**)ped,**auxPed;
    int *dni,*dniCli=(int*)cliente[0];
    char *estado;
    for(int i=0;pedidos[i];i++){
        auxPed=(void**)pedidos[i];
        dni=(int*)auxPed[DNIPED];
        estado=(char*)auxPed[ESTADO];
        if(*estado=='A' and *dni==*dniCli){
            if(nd==cap) aumentarSubCap(cliente[2],nd,cap);
            agregarPedido(cliente[2],nd,pedidos[i]);
            nd++;
        }
    }
}

void aumentarSubCap(void *&lista,int &nd,int &cap){
    cap+=INCREMENTO;
    void **regLista=(void**)lista;
    void **aux=new void*[cap]{};
    if(nd==0) nd=1;
    else{
        for(int i=0;i<nd;i++) aux[i]=regLista[i];
        delete regLista;
    }
    lista=aux;
}

void agregarPedido(void *lista,int numDat,void *pedido){
    void **listaPed=(void**)lista,**regPedido=(void**)pedido;
    void **registro=new void*[4]{};
    registro[0]=regPedido[FECHAPED];
    registro[1]=regPedido[CODPED];
    registro[2]=regPedido[DESCPED];
    registro[3]=regPedido[CANTPED];
    listaPed[numDat-1]=registro;
}

void actualizarEstados(void *prod,void *ped){
    void **pedidos=(void**)ped,**auxPed;
    void **productos=(void**)prod;
    int *codigo;
    int posProd;
    for(int i=0;pedidos[i];i++){
        auxPed=(void**)pedidos[i];
        codigo=(int*)auxPed[CODPED];
        posProd=buscarProd(prod,*codigo);
        if(posProd!=NO_ENCONTRADO){
            actualizarEst(productos[posProd],pedidos[i]);
        }
    }
    imprimepedidos(ped);
    imprimeproductos(prod);
}

void actualizarEst(void *producto,void *pedido){
    void **auxProd=(void**)producto,**auxPed=(void**)pedido;
    int *stock=(int*)auxProd[STOCK],*cantSol=(int*)auxPed[CANTPED];
    char *estado=(char*)auxPed[ESTADO];
    if(*stock>=*cantSol){
        *estado='A';
        *stock-=*cantSol;
    }
}

int buscarProd(void *prod,int codigo){
    void **productos=(void**)prod;
    void **auxProd;
    int *cod;
    for(int i=0;productos[i];i++){
        auxProd=(void**)productos[i];
        cod=(int*)auxProd[0];
        if(codigo==*cod) return i;
    }
    return NO_ENCONTRADO;
}

void *leerRegCli(ifstream &arch){
    void **registro=new void*[3]{};
    int *dni=new int;
    char *nombre;
    void **lista=new void*[INCREMENTO]{};
    arch>>*dni;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre=leerCadena(arch,'\n');
    registro[0]=dni;
    registro[1]=nombre;
    registro[2]=lista;
    return registro;
}