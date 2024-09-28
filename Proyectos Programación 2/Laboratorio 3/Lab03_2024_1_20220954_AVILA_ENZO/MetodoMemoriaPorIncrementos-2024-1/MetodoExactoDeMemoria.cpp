/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "MetodoExactoDeMemoria.h"
#include "AperturaDeArchivos.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1
#define TAM_LINEA 100

void lecturaDeLibros (const char *nombArch,char ***&libros,int **&stock){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    char **auxLibros;
    int sto,numDat=0,cap=0;
    while(true){
        auxLibros=leerLibros(arch);
        if(arch.eof()) break;
        leerStock(arch,sto);
        if(numDat==cap) aumentarCapLib(libros,stock,numDat,cap);
        libros[numDat-1]=auxLibros;
        guardarStock(stock[numDat-1],sto);
        numDat++;
    }
}

char **leerLibros(ifstream &arch){
    char **aux;
    aux=new char*[3]{};
    aux[0]=leerCadena(arch);
    if(arch.eof()) return nullptr;
    aux[1]=leerCadena(arch);
    aux[2]=leerCadena(arch);
    return aux;
}

char *leerCadena(ifstream &arch){
    char cadena[100],*ptr;
    arch.getline(cadena,100,',');
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void leerStock(ifstream &arch,int &stock){
    double precio;
    arch>>stock;
    arch.get();
    arch>>precio;
    arch.get();
}

void aumentarCapLib(char ***&libros,int **&stock,int &nD,int &cap){
    cap+=INCREMENTO;
    char ***auxLib=new char**[cap]{};
    int **auxStock=new int*[cap]{};
    if(nD==0) nD=1;
    else{
        for(int i=0;i<nD;i++){
            auxLib[i]=libros[i];
            auxStock[i]=stock[i];
        }
        delete libros;
        delete stock;
    }
    libros=auxLib;
    stock=auxStock;
}

void guardarStock(int *&stock,int sto){
    stock=new int[2]{};
    stock[0]=sto;
    stock[1]=0;
}

void pruebaDeLecturaDeLibros (const char *nombArch,char ***libros,int **stock){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    arch<<"CODIGO"<<setw(10)<<' '<<"TITULO"<<setw(20)<<' '<<"AUTOR"<<endl;
    char **auxLib;
    int *auxStock;
    for(int i=0;libros[i];i++){
        auxLib=libros[i];
        auxStock=stock[i];
        arch<<left<<setw(30)<<auxLib[0]<<setw(60)<<auxLib[1]<<setw(40)<<
                auxLib[2]<<right<<setw(10)<<auxStock[0]<<setw(6)<<auxStock[1]<<endl;
    }
}

void atencionDePedidos (const char *nombArch,char ***libros,int **stock, 
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    int dni,numPed,posDni;
    int numCli=0,capCli=0,capPed=0,arrCapCli[200]{},arrNDPed[200]{},
            arrCapPed[200]{};
    while(true){
        leerDniNumPed(arch,dni,numPed);
        if(arch.eof()) break;
        if(numCli==capCli) aumentarCapCli(pedidosClientes,numCli,capCli);
        if(numPed>=capPed) aumentarCapPed(pedidosLibros,pedidosAtendidos,numPed,capPed);
        posDni=buscarDni(pedidosClientes,dni);
        if(posDni==NO_ENCONTRADO){
            agregarCliente(pedidosClientes[numCli-1],dni);
            posDni=numCli-1;
            numCli++;
        }
        procesarPedido(arch,numPed,libros,stock,pedidosClientes[posDni],
                arrCapCli[posDni],pedidosLibros[numPed-1],pedidosAtendidos[numPed-1],
                arrNDPed[numPed-1],arrCapPed[numPed-1]);
    }
}

void procesarPedido(ifstream &arch,int numPed,char ***libros,int **stock,
        int *&pedCli,int &capPedCli,char **&pedLib,bool *&pedAten,int &ndPedLib,
        int &capPedLib){
    if(pedCli[1]+2>=capPedCli) aumentarSubCapCli(pedCli,capPedCli);
    pedCli[pedCli[1]+2]=numPed;
    pedCli[1]++;
    char codigo[8];
    int posLibro,*auxStock;
    while(true){
        arch>>codigo;
        if(ndPedLib==capPedLib) aumentarSubCapPed(pedLib,pedAten,ndPedLib,capPedLib);
        pedLib[ndPedLib-1]=new char[strlen(codigo)+1]{};
        strcpy(pedLib[ndPedLib-1],codigo);
        posLibro=buscarLibro(libros,codigo);
        if(posLibro!=NO_ENCONTRADO){
            auxStock=stock[posLibro];
            if(auxStock[0]>0){
                pedAten[ndPedLib-1]=true;
                auxStock[0]--;
            }
            else{
                pedAten[ndPedLib-1]=false;
                auxStock[1]++;
            }
        }
        ndPedLib++;
        if(arch.get()=='\n') break;
    }
}

int buscarLibro(char ***libros,char *codigo){
    char **aux;
    for(int i=0;libros[i];i++){
        aux=libros[i];
        if(strcmp(aux[0],codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}
void aumentarSubCapCli(int *&pedCli,int &cap){
    int *aux;
    cap+=INCREMENTO;
    if(pedCli[1]==0){
        aux=new int[cap]{};
        for(int i=0;i<2;i++){
            aux[i]=pedCli[i];
        }
        delete pedCli;
        pedCli=aux;
    }
    else{
        aux=new int[cap]{};
        for(int i=0;i<pedCli[1]+2;i++){
            aux[i]=pedCli[i];
        }
        delete pedCli;
        pedCli=aux;
    }
}

void aumentarSubCapPed(char **&pedLib,bool *&pedAten,int &nd,int &cap){
    cap+=INCREMENTO;
    char **auxPedLib=new char*[cap]{};
    bool *auxPedAten=new bool[cap]{};
    if(nd==0) nd=1;
    else{
        for(int i=0;i<nd;i++){
            auxPedLib[i]=pedLib[i];
            auxPedAten[i]=pedAten[i];
        }
        delete pedAten;
        delete pedLib;
    }
    pedAten=auxPedAten;
    pedLib=auxPedLib;
}

void leerDniNumPed(ifstream &arch,int &dni,int &numPed){
    arch>>numPed;
    if(arch.eof()) return;
    arch.get();
    arch>>dni;
}

void aumentarCapCli(int **&pedCli,int &nd,int &cap){
    cap+=INCREMENTO;
    int **auxPedCli=new int*[cap]{};
    if(nd==0) nd=1;
    else{
        for(int i=0;i<nd;i++) auxPedCli[i]=pedCli[i];
        delete pedCli;
    }
    pedCli=auxPedCli;
}

void aumentarCapPed(char ***&pedLib,bool **&pedAten,int numPed,int &capPed){
    char ***auxPedLib;
    bool **auxPedAten;
    if(capPed==0){
        capPed=numPed+INCREMENTO;
        pedLib=new char**[capPed]{};
        pedAten=new bool*[capPed]{};
    }
    else if(numPed>capPed){
        auxPedLib=new char**[numPed+INCREMENTO]{};
        auxPedAten=new bool*[numPed+INCREMENTO]{};
        for(int i=0;i<numPed;i++){
            auxPedLib[i]=pedLib[i];
            auxPedAten[i]=pedAten[i];
        }
        delete pedLib;
        delete pedAten;
        capPed=numPed+INCREMENTO;
        pedLib=auxPedLib;
        pedAten=auxPedAten;
    }
}

int buscarDni(int **pedCli,int dni){
    int *aux;
    for(int i=0;pedCli[i];i++){
        aux=pedCli[i];
        if(dni==aux[0]) return i;
    }
    return NO_ENCONTRADO;
}

void agregarCliente(int *&pedCli,int dni){
    /*momentaneo*/
    pedCli=new int[2]{};
    pedCli[0]=dni;
    pedCli[1]=0; /*num ped.*/
}

void ordenarPedidosClientes (int **pedidosClientes){
    int numCli=0;
    while(pedidosClientes[numCli]) numCli++;
    qSort(pedidosClientes,0,numCli-1);
}

void qSort(int **pedCli,int izq,int der){
    int limite=izq,pos=(izq+der)/2;
    if(izq>=der) return;
    cambiar(pedCli[izq],pedCli[pos]);
    int *auxIzq,*auxI;
    for(int i=izq+1;i<=der;i++){
        auxIzq=pedCli[izq];
        auxI=pedCli[i];
        if(auxIzq[1]<auxI[1]){
            limite++;
            cambiar(pedCli[limite],pedCli[i]);
        }
    }
    cambiar(pedCli[limite],pedCli[izq]);
    qSort(pedCli,izq,limite-1);
    qSort(pedCli,limite+1,der);
}

void cambiar(int *&dato1,int *&dato2){
    int *aux=dato1;
    dato1=dato2;
    dato2=aux;
}

void reporteDeEntregaDePedidos (const char *nombArch,int **pedidosClientes,
        char ***pedidosLibros,bool **pedidosAtendidos){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    int *auxPedCli;
    arch<<setw(33)<<' '<<"REPORTE TOP 5"<<endl<<setw(30)<<' '<<"ATENCION DE PEDIDOS"<<endl;
    for(int i=0;i<5;i++){
        auxPedCli=pedidosClientes[i];
        imprimirLinea(arch,TAM_LINEA,'=');
        arch<<"CLIENTE:"<<setw(12)<<auxPedCli[0]<<setw(20)<<' '<<
                "CANTIDAD PEDIDOS: "<<auxPedCli[1]<<endl;
        imprimirLinea(arch,TAM_LINEA,'=');
        imprimirPedidos(arch,auxPedCli,pedidosLibros,pedidosAtendidos);
    }
}

void imprimirPedidos(ofstream &arch,int *pedCli,char ***pedidosLibros,
        bool **pedidosAtendidos){
    int posPed;
    char **auxPedLib;
    bool *auxPedAten;
    for(int i=0;i<pedCli[1];i++){
        arch<<setw(10)<<' '<<"Pedido No."<<setw(6)<<' '<<"Codigo del libro"<<
                setw(5)<<' '<<"Observacion"<<endl;
        imprimirLinea(arch,TAM_LINEA,'-');
        arch<<setw(12)<<' '<<setfill('0')<<setw(6)<<pedCli[i+2]<<setfill(' ');
        posPed=pedCli[i+2]-1;
        auxPedLib=pedidosLibros[posPed];
        auxPedAten=pedidosAtendidos[posPed];
        for(int j=0;auxPedLib[j];j++){
            if(j==0) arch<<setw(12)<<' '<<auxPedLib[j];
            else arch<<setw(30)<<' '<<auxPedLib[j];
            if(auxPedAten[j]) arch<<setw(10)<<' '<<"ATENDIDO"<<endl;
            else arch<<setw(10)<<' '<<"NO ATENDIDO"<<endl;
        }
        if(i!=pedCli[1]-1) imprimirLinea(arch,TAM_LINEA,'-');
    }
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}