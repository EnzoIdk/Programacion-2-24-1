
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "AperturaDeArchivos.h"
#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"

#define NO_ENCONTRADO -1
#define TAM_LINEA 120

enum Res{COD,NOMB,AUT,LISTA,STO};
void cargaclientes(void *&cli){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Clientes.csv");
    void *bufferCli[100]{},**clientes,*reg;
    int numDat=0;
    while(true){
        reg=leerRegCli(arch);
        if(arch.eof()) break;
        bufferCli[numDat]=reg;
        numDat++;
    }
    clientes=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) clientes[i]=bufferCli[i];
    cli=clientes;
    muestraclientes(cli);
}

void *leerRegCli(ifstream &arch){
    void **registro=new void*[2]{};
    int *dni=new int;
    char *nombre;
    arch>>*dni;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre=leerCadena(arch,'\n');
    registro[0]=dni;
    registro[1]=nombre;
    return registro;
}

char *leerCadena(ifstream &arch,char delim){
    char cadena[60],*ptr;
    arch.getline(cadena,60,delim);
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void creareserva(void *&res){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Libros.csv");
    void *bufferRes[300]{},**reserva,*reg;
    int numDat=0;
    while(true){
        reg=leerRegRes(arch);
        if(arch.eof()) break;
        bufferRes[numDat]=reg;
        numDat++;
    }
    reserva=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) reserva[i]=bufferRes[i];
    res=reserva; 
    muestrareservas(res);
}

void imprimirRes(void *res){
    void **reserva=(void**)res;
    char *aux=(char*)reserva[0];
    int *stock=(int*)reserva[4];
    cout<<aux<<' '<<*stock<<endl;
}

void *leerRegRes(ifstream &arch){
    void **registro=new void*[5]{};
    char *codigo,*nombre,*autor;
    void **pedidos;
    int *stock=new int;
    double precio;
    codigo=leerCadena(arch,',');
    if(arch.eof()) return nullptr;
    nombre=leerCadena(arch,',');
    autor=leerCadena(arch,',');
    arch>>*stock;
    arch.get();
    arch>>precio;
    arch.get();
    pedidos=new void*[*stock]{};
    registro[COD]=codigo;
    registro[NOMB]=nombre;
    registro[AUT]=autor;
    registro[LISTA]=pedidos;
    registro[STO]=stock;
    return registro;
}

void cargareservar(void *cli,void *res){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"pedidos2.csv");
    void **clientes=(void**)cli,**reservas=(void**)res;
    int dni,posCli,posRes;
    char codigo[8];
    while(true){
        arch>>dni;
        if(arch.eof()) break;
        arch.get();
        arch>>codigo;
        posCli=buscarCli(dni,clientes);
        posRes=buscarRes(codigo,reservas);
        agregarReserva(clientes[posCli],reservas[posRes]);
    }
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

int buscarRes(char *codigo,void **reservas){
    for(int i=0;reservas[i];i++){
        if(esReserva(codigo,reservas[i])) return i;
    }
    return NO_ENCONTRADO;
}

bool esReserva(char *codigo,void *res){
    void **reserva=(void**)res;
    char *codLib=(char*)reserva[COD];
    return strcmp(codLib,codigo)==0;
}

void agregarReserva(void *cli,void *res){
    void **cliente=(void**)cli,**reserva=(void**)res;
    int *dni=(int*)cliente[0];
    char *nombre=(char*)cliente[1];
    int *stock=(int*)reserva[STO];
    void **lista=(void**)reserva[LISTA];
    agregarALista(lista,*dni,nombre,*stock);
}

void agregarALista(void *lis,int dni,char *nombre,int stock){
    void **lista=(void**)lis;
    int numDat;
    for(numDat=0;numDat<stock;numDat++){
        if(lista[numDat]==nullptr) break;
    }
    if(numDat<stock){
        lista[numDat]=new void*[2]{};
        colocarDatos(lista[numDat],dni,nombre);
    }
}

void colocarDatos(void *&lis,int dni,char *nombre){
    void **datoLis=(void**)lis;
    /*asignando nueva memoria*/
    int *dniLis=new int;
    char *nombreLis;
    *dniLis=dni;
    nombreLis=new char[strlen(nombre)+1]{};
    strcpy(nombreLis,nombre);
    datoLis[0]=dniLis;
    datoLis[1]=nombreLis;
}