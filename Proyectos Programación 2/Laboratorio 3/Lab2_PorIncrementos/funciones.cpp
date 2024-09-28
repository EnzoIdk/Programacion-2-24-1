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
#define INCREMENTO 5
#define TAM_LINEA 120
#define NO_ENCONTRADO -1

void lecturaDeLibros (const char *nombArch,char ***&libros,int **&stock){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char **auxLibros;
    int *auxStock,numDat=0,cap=0;
    double precio;
    libros=nullptr;
    stock=nullptr;
    while(true){
        auxLibros=leerLibros(arch);
        if(arch.eof()) break;
        auxStock=leerStock(arch);
        if(numDat==cap) aumentarCap(libros,stock,numDat,cap);
        libros[numDat-1]=auxLibros;
        stock[numDat-1]=auxStock;
        numDat++;
    }
}

char **leerLibros(ifstream &arch){
    char **auxLibros;
    auxLibros=new char*[3]{};
    auxLibros[0]=leerCadena(arch);
    if(arch.eof()) return nullptr;
    auxLibros[1]=leerCadena(arch);
    auxLibros[2]=leerCadena(arch);
    return auxLibros;
}

char *leerCadena(ifstream &arch){
    char cadena[100],*ptr;
    arch.getline(cadena,100,',');
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

int *leerStock(ifstream &arch){
    int *auxStock;
    int stock;
    double precio;
    arch>>stock;
    arch.get();
    arch>>precio;
    arch.get();
    auxStock=new int[2]{};
    auxStock[0]=stock;
    auxStock[1]=0;
    return auxStock;
}

void aumentarCap(char ***&libros,int **&stock,int &numDatos,int &cap){
    char ***nLibros;
    int **nStock;
    cap+=INCREMENTO;
    if(libros==nullptr){
        libros=new char**[cap]{};
        stock=new int*[cap]{};
        numDatos=1;
    }
    else{
        nLibros=new char**[cap]{};
        nStock=new int*[cap]{};
        for(int i=0;i<numDatos;i++){
            nLibros[i]=libros[i];
            nStock[i]=stock[i];
        }
        delete libros;
        delete stock;
        libros=nLibros;
        stock=nStock;
    }
}

void pruebaDeLecturaDeLibros (const char *nombArch,char ***libros,int **stock){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char **auxLib;
    int *auxStock;
    for(int i=0;libros[i];i++){
        auxLib=libros[i];
        auxStock=stock[i];
        arch<<left<<setw(60)<<auxLib[0]<<setw(60)<<auxLib[1]<<setw(60)<<
                auxLib[2]<<right<<setw(10)<<auxStock[0]<<setw(10)<<auxStock[1]<<endl;
    }
}

void atencionDePedidos (const char *nombArch,char ***libros,int **stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numCli=0,capCli=0,capPed=0;
    int numPed,dni,posDNI,arrCapCli[200]{},arrNDPed[200]{},arrCapPed[200]{};
    while(true){
        leerPedDNI(arch,numPed,dni);
        if(arch.eof()) break;
        if(numCli==capCli) aumentarCapPedCli(pedidosClientes,numCli,capCli);
        if(numPed>=capPed) aumentarCapPedLib(pedidosLibros,pedidosAtendidos,
                numPed,capPed);
        posDNI=buscarDNI(pedidosClientes,dni,numCli);
        if(posDNI==NO_ENCONTRADO){
            agregarCliente(dni,pedidosClientes[numCli-1]);
            posDNI=numCli-1;
            numCli++;
        }
        procesarPedidos(arch,numPed,libros,stock,pedidosClientes[posDNI],
                arrCapCli[posDNI],pedidosLibros[numPed-1],pedidosAtendidos[numPed-1],
                arrNDPed[numPed-1],arrCapPed[numPed-1]);
    }
}

void leerPedDNI(ifstream &arch,int &numPed,int &dni){
    arch>>numPed;
    if(arch.eof()) return;
    arch.get();
    arch>>dni;
}

int buscarDNI(int **pedidosClientes,int dni,int numCli){
    int *aux;
    for(int i=0;pedidosClientes[i];i++){
        aux=pedidosClientes[i];
        if(aux[0]==dni) return i;
    }
    return NO_ENCONTRADO;
}

void aumentarCapPedCli(int **&pedidosClientes,int &numDat,int &cap){
    cap+=INCREMENTO;
    int **auxPedCli=new int*[cap]{};
    if(numDat==0) numDat=1;
    else{
        for(int i=0;i<numDat;i++) auxPedCli[i]=pedidosClientes[i];
        delete pedidosClientes;
    }
    pedidosClientes=auxPedCli;
}

void aumentarCapPedLib(char ***&pedidosLibros,bool **&pedidosAtendidos,int numPed,int &cap){
    char ***auxPedLib;
    bool **auxPedAten;
    if(cap==0){
        pedidosLibros=new char**[numPed+1]{};
        pedidosAtendidos=new bool*[numPed+1]{};
        cap=numPed;
    }
    else if(numPed>cap){
        auxPedLib=new char**[numPed+1]{};
        auxPedAten=new bool*[numPed+1]{};
        for(int i=0;i<cap;i++){
            auxPedLib[i]=pedidosLibros[i];
            auxPedAten[i]=pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosAtendidos=auxPedAten;
        pedidosLibros=auxPedLib;
        cap=numPed;
    }
}

void agregarCliente(int dni,int *&pedCli){
    pedCli=new int[2]{};
    pedCli[0]=dni;
    pedCli[1]=0;
}

void procesarPedidos(ifstream &arch,int numPed,char ***libros,int **stock,int *&pedCli,
        int &capCli,char **&pedLib,bool *&pedAten,int &ndPed,int &capPed){
    char codigo[8];
    int posLibro,*auxStock;
    if(pedCli[1]==capCli) aumentarSubCapCli(pedCli,capCli);
    pedCli[pedCli[1]+2]=numPed;
    pedCli[1]++;
    while(true){
        arch>>codigo;
        posLibro=buscarLibro(libros,codigo);
        if(ndPed==capPed) aumentarSubCapPed(pedLib,pedAten,ndPed,capPed);
        if(posLibro!=NO_ENCONTRADO){
            auxStock=stock[posLibro];
            pedLib[ndPed-1]=new char[strlen(codigo)+1]{};
            strcpy(pedLib[ndPed-1],codigo);
            if(auxStock[0]>0){
                pedAten[ndPed-1]=true;
                auxStock[0]--;
            }
            else{
                pedAten[ndPed-1]=false;
                auxStock[1]++;
            }
            ndPed++;
        }
        if(arch.get()=='\n') return;
    }
}

void aumentarSubCapCli(int *&pedCli,int &capCli){
    capCli+=INCREMENTO;
    int *aux=new int[capCli]{};
    for(int i=0;i<pedCli[1]+2;i++) aux[i]=pedCli[i];
    delete pedCli;
    pedCli=aux;
}

void aumentarSubCapPed(char **&pedLib,bool *&pedAten,int &nd,int &cap){
    cap+=INCREMENTO;
    char **auxPedLib=new char*[cap]{};
    bool *auxPedAten=new bool[cap]{};
    if(nd==0){
        nd=1;
    }
    else{
        for(int i=0;i<nd;i++){
            auxPedAten[i]=pedAten[i];
            auxPedLib[i]=pedLib[i];
        }
        delete pedAten;
        delete pedLib;
    }
    pedAten=auxPedAten;
    pedLib=auxPedLib;
}


int buscarLibro(char ***libros,char *codigo){
    char **auxLib;
    for(int i=0;libros[i];i++){
        auxLib=libros[i];
        if(strcmp(auxLib[0],codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

void pruebaDePedidos(const char *nombArch,int **pedidosClientes){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int *aux;
    for(int i=0;pedidosClientes[i];i++){
        aux=pedidosClientes[i];
        arch<<aux[0]<<setw(6)<<' '<<aux[1]<<endl;
        for(int j=0;j<aux[1];j++){
            arch<<aux[j+2]<<' ';
        }
        arch<<endl<<endl;
    }
}

void reporteDeEntregaDePedidos (const char *nombArch,int **pedidosClientes,char ***pedidosLibros,
        bool **pedidosAtendidos){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numClientes=0;
    while(pedidosClientes[numClientes]) numClientes++;
    qSort(pedidosClientes,0,numClientes-1);
    arch<<setw(30)<<' '<<"REPORTE DE ATENCION DE PEDIDOS"<<endl;
    int *auxPedCli,posPed;
    for(int i=0;pedidosClientes[i];i++){
        auxPedCli=pedidosClientes[i];
        imprimirLinea(arch,TAM_LINEA,'=');
        arch<<"CLIENTE: "<<auxPedCli[0]<<endl;
        imprimirLinea(arch,TAM_LINEA,'=');
        for(int j=0;j<auxPedCli[1];j++){
            arch<<setw(4)<<' '<<"Pedido No."<<setw(10)<<' '<<"Codigo Libro"<<
                setw(10)<<' '<<"Observacion"<<endl;
            imprimirLinea(arch,TAM_LINEA,'-');
            arch<<setw(4)<<' '<<setfill('0')<<setw(6)<<auxPedCli[j+2]<<setfill(' ');
            posPed=auxPedCli[j+2]-1;
            imprimirDatosPedidos(arch,pedidosLibros[posPed],pedidosAtendidos[posPed]);
            if(j!=auxPedCli[1]-1) imprimirLinea(arch,TAM_LINEA,'-');
        }
    }
}

void qSort(int **pedidosClientes,int izq,int der){
    int limite=izq,pos=(izq+der)/2;
    int *auxIzq,*auxI;
    if(izq>=der) return;
    cambiar(pedidosClientes[izq],pedidosClientes[pos]);
    for(int i=izq+1;i<=der;i++){
        auxIzq=pedidosClientes[izq];
        auxI=pedidosClientes[i];
        if(auxI[0]<auxIzq[0]){
            limite++;
            cambiar(pedidosClientes[limite],pedidosClientes[i]);
        }
    }
    cambiar(pedidosClientes[limite],pedidosClientes[izq]);
    qSort(pedidosClientes,izq,limite-1);
    qSort(pedidosClientes,limite+1,der);
}

void cambiar(int *&dato1,int *&dato2){
    int *aux=dato1;
    dato1=dato2;
    dato2=aux;
}

void imprimirDatosPedidos(ofstream &arch,char **pedidos,bool *atendidos){
    for(int i=0;pedidos[i];i++){
        if(i==0) arch<<setw(25)<<pedidos[i]<<setw(10)<<' ';
        else arch<<setw(35)<<pedidos[i]<<setw(10)<<' ';
        if(atendidos[i]) arch<<"ATENDIDO"<<endl;
        else arch<<"NO ATENDIDO"<<endl;
    }
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}