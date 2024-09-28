
#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>

using namespace std;

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
#define TAM_LINEA 120
#define NO_ENCONTRADO -1

enum Prod{COD,DESC,PRE,CANT};
enum Ped{CODPED,DESCPED,CANTPED,DNIPED,FECHAPED,ESTADO};
enum Cli{DNICLI,NOMB,PEDIDOS};

void cargaproductos(void *&prod){
    ifstream arch("productos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo productos2.csv"<<endl;
        exit(1);
    }
    void **productos,*buffProd[100]{},*reg;
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
    imprimeproductos(prod);
}

void *leerRegProd(ifstream &arch){
    void **registro=new void*[4]{};
    char *descripcion;
    double *precio=new double;
    int *codigo=new int,*cant=new int;
    arch>>*codigo;
    if(arch.eof()) return nullptr;
    arch.get();
    descripcion=leerCadena(arch,',');
    arch>>*precio;
    arch.get();
    arch>>*cant;
    registro[COD]=codigo;
    registro[DESC]=descripcion;
    registro[PRE]=precio;
    registro[CANT]=cant;
    return registro;
}

char *leerCadena(ifstream &arch,char delim){
    char cadena[70],*ptr;
    arch.getline(cadena,70,delim);
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void cargapedidos(void *&ped){
    ifstream arch("pedidos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo pedidos2.csv"<<endl;
        exit(1);
    }
    void **pedidos,*buffPed[200]{},*reg;
    int numDat=0;
    while(true){
        reg=leerRegPed(arch);
        if(arch.eof()) break;
        buffPed[numDat]=reg;
        numDat++;
    }
    pedidos=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) pedidos[i]=buffPed[i];
    ped=pedidos;
    imprimepedidos(ped);
//    Verificando que sí se leyó bien aunque en el reporte salga todo raro
//    void **aux;
//    for(int i=0;pedidos[i];i++){
//        aux=(void**)pedidos[i];
//        cout<<*(char*)aux[ESTADO]<<' '<<*(int*)aux[DNIPED]<<endl;
//    }
}

void *leerRegPed(ifstream &arch){
    void **registro=new void*[6]{};
    int *codigo=new int,*cantidad=new int,*dni=new int,*fecha=new int;
    int dd,mm,aa;
    char *descripcion,*estado=new char,car;
    arch>>*codigo;
    if(arch.eof()) return nullptr;
    arch.get();
    descripcion=leerCadena(arch,',');
    arch>>*cantidad>>car>>*dni>>car>>dd>>car>>mm>>car>>aa;
    *fecha=aa*10000+mm*100+dd;
    *estado='N';
    registro[CODPED]=codigo;
    registro[DESCPED]=descripcion;
    registro[CANTPED]=cantidad;
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
    void **clientes,*bufferCli[20]{},*reg;
    int numDat=0,nd[20]{},dni;
    while(true){
        reg=leerRegCli(arch,dni);
        if(arch.eof()) break;
        bufferCli[numDat]=reg;
        colocarPedidos(bufferCli[numDat],nd[numDat],dni,ped);
        numDat++;
    }
    clientes=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++){
        clientes[i]=bufferCli[i];
        espaciosExactosPedCli(clientes[i],nd[i]);
    }
    cli=clientes;
    imprimerepfinal(cli);
}

void espaciosExactosPedCli(void *cli,int nd){
    void **cliente=(void**)cli;
    void **pedidos=(void**)cliente[PEDIDOS];
    void **auxPed=new void*[nd+1]{};
    for(int i=0;i<nd;i++) auxPed[i]=pedidos[i];
    delete pedidos;
    cliente[PEDIDOS]=auxPed;
}

void actualizarEstados(void *prod,void *ped){
    void **pedidos=(void**)ped;
    for(int i=0;pedidos[i];i++){
        actualizarEst(prod,pedidos[i]);
    }
    imprimepedidos(ped);
    imprimeproductos(prod);
}

void actualizarEst(void *prod,void *ped){
    void **auxPed=(void**)ped;
    int *cod=(int*)auxPed[CODPED],*cant=(int*)auxPed[CANTPED];
    char *estado=(char*)auxPed[ESTADO];
    void **productos=(void**)prod,**auxProd;
    int posProd=buscarProd(*cod,productos),*stock;
    if(posProd!=NO_ENCONTRADO){
        auxProd=(void**)productos[posProd];
        stock=(int*)auxProd[CANT];
        if(*stock>=*cant){
            *estado='A';
            *stock-=(*cant);
        }
    }
}

int buscarProd(int cod,void **productos){
    for(int i=0;productos[i];i++){
        if(esProducto(cod,productos[i])) return i;
    }
    return NO_ENCONTRADO;
}

bool esProducto(int cod,void *prod){
    void **auxProd=(void**)prod;
    int *codProd=(int*)auxProd[COD];
    return cod==*codProd;
}

void *leerRegCli(ifstream &arch,int &dni){
    void **registro=new void*[3]{};
    int *ptDni=new int;
    char *nombre;
    arch>>dni;
    if(arch.eof()) return nullptr;
    arch.get();
    *ptDni=dni;
    nombre=leerCadena(arch,'\n');
    registro[DNICLI]=ptDni;
    registro[NOMB]=nombre;
    registro[PEDIDOS]=nullptr;
    return registro;
}

void colocarPedidos(void *cli,int &numDat,int dni,void *ped){
    void **cliente=(void**)cli,**pedidos=(void**)ped;
    void **auxPed;
    char *estado;
    int *dniPed;
    if(numDat==0) cliente[PEDIDOS]=new void*[50]{};
    for(int i=0;pedidos[i];i++){
        auxPed=(void**)pedidos[i];
        dniPed=(int*)auxPed[DNIPED];
        estado=(char*)auxPed[ESTADO];
        if(dni==*dniPed and *estado=='A'){
            agregarPedido(cliente[PEDIDOS],numDat,auxPed);
            numDat++;
        }
    }
}

void agregarPedido(void *cliPed,int numDat,void **pedido){
    void **clientePedido=(void**)cliPed;
    clientePedido[numDat]=cargarDatosPedido(pedido);
}

void *cargarDatosPedido(void **pedido){
    void **registro=new void*[4]{};
//    char *estado=(char*)pedido[ESTADO];
//    int *aux;
    registro[0]=pedido[FECHAPED];
    registro[1]=pedido[CODPED];
    registro[2]=pedido[DESCPED];
//    if(*estado=='A') aux=(int*)pedido[CANTPED];
//    else{
//        aux=new int; /*si no está atendido, tenemos que crear 
//                      una nueva dirección de memoria que apunte al valor 0*/
//        *aux=0;
//    }
//    registro[3]=aux;
    registro[3]=pedido[CANTPED];
    return registro;
}

void imprimereporte(void *cli){
    imprimerepfinal(cli);
}