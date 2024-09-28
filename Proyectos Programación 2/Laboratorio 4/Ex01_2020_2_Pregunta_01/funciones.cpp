/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "funciones.h"
using namespace std;

#define NO_ENCONTRADO -1
#define TAM_LINEA 120

enum Ped{FECHA,RUC,COD,NOMB,CANT_SOL,CANT_AT};
enum Stock{COD_ST,STOCK_DISP};

void leerDatos(void *&pedidos,void *&stock){
    ifstream archP = abrirArchL("pedidos.csv");
    ifstream archS = abrirArchL("stock.csv");
    ofstream archR1 = abrirArchE("ReportePedidos1.txt");
    ofstream archR2 = abrirArchE("ReporteStock1.txt");
    leerPedidos(pedidos,archP);
    leerStock(stock,archS);
    imprimirPed(pedidos,archR1);
    imprimirSto(stock,archR2);
}

ifstream abrirArchL(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    return arch;
}

ofstream abrirArchE(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    return arch;
}

void leerPedidos(void *&ped,ifstream &arch){
    void *bufferP[100]{},**pedidos;
    int numDat=0,ruc;
    while(true){
        leerRuc(arch,ruc);
        if(arch.eof()) break;
        llenarBufferP(arch,bufferP,numDat,ruc);
    }
    pedidos=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) pedidos[i]=bufferP[i];
    ped=pedidos;
}

void leerRuc(ifstream &arch,int &ruc){
    char cadena[60],car;
    arch>>ruc;
    if(arch.eof()) return;
    arch.get();
    arch.getline(cadena,60,',');
}

void llenarBufferP(ifstream &arch,void **buffer,int &numDat,int ruc){
    void *reg;
    while(true){
        reg=leerRegPed(arch,ruc);
        buffer[numDat]=reg;
        numDat++;
        if(arch.get()=='\n') return;
    }
}

void *leerRegPed(ifstream &arch,int ruc){
    void **registro=new void*[6]{};
    int *fecha=new int,*nroRuc=new int,*cod=new int,*cantSol=new int,*cantAten=new int;
    char *nombre,car;
    int dd,mm,aa;
    arch>>aa>>car>>mm>>car>>dd>>car>>*cod>>car;
    nombre=leerCadena(arch);
    arch>>*cantSol;
    *fecha=aa*10000+mm*100+dd;
    *nroRuc=ruc;
    *cantAten=0;
    registro[FECHA]=fecha;
    registro[RUC]=nroRuc;
    registro[COD]=cod;
    registro[NOMB]=nombre;
    registro[CANT_SOL]=cantSol;
    registro[CANT_AT]=cantAten;
    return registro;
}

char *leerCadena(ifstream &arch){
    char cadena[60],*ptr;
    arch.getline(cadena,60,',');
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void leerStock(void *&sto,ifstream &arch){
    void **stock,*bufferStock[20]{},*reg;
    int numDat=0;
    while(true){
        reg=leerRegStock(arch);
        if(arch.eof()) break;
        bufferStock[numDat]=reg;
        numDat++;
    }
    stock=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) stock[i]=bufferStock[i];
    sto=stock;
}

void *leerRegStock(ifstream &arch){
    void **registro=new void*[2]{};
    int *cod=new int,*stock=new int;
    arch>>*cod;
    if(arch.eof()) return nullptr;
    arch.get();
    arch>>*stock;
    registro[COD_ST]=cod;
    registro[STOCK_DISP]=stock;
    return registro;
}

void imprimirPed(void *ped,ofstream &arch){
    void **pedidos=(void**)ped;
    arch<<"FECHA"<<setw(6)<<' '<<"RUC"<<setw(10)<<' '<<"CODIGO"<<setw(3)<<' '<<
            "NOMBRE"<<setw(43)<<' '<<"CANT. SOLICITADA"<<setw(2)<<' '<<"CANT. "
            "ATENDIDA"<<endl;
    for(int i=0;pedidos[i];i++){
        imprimirPedido(arch,pedidos[i]);
    }
}

void imprimirPedido(ofstream &arch,void *ped){
    void **pedido=(void**)ped;
    int *fecha=(int*)pedido[FECHA],*ruc=(int*)pedido[RUC],*cod=(int*)pedido[COD];
    int *cantS=(int*)pedido[CANT_SOL],*cantA=(int*)pedido[CANT_AT];
    char *nombre=(char*)pedido[NOMB];
    arch<<*fecha<<setw(3)<<' '<<*ruc<<setw(6)<<' '<<setfill('0')<<setw(4)<<*cod
            <<setfill(' ')<<setw(4)<<' '<<left<<setw(50)<<nombre<<right<<
            setw(10)<<*cantS<<setw(13)<<*cantA<<endl;
}

void imprimirSto(void *sto,ofstream &arch){
    void **stocks=(void**)sto;
    arch<<setw(2)<<' '<<"CANTIDAD"<<setw(4)<<' '<<"STOCK"<<endl;
    for(int i=0;stocks[i];i++){
        imprimirStock(arch,stocks[i]);
    }
}

void imprimirStock(ofstream &arch,void *sto){
    void **stock=(void**)sto;
    int *cod=(int*)stock[COD_ST];
    int *stockDisp=(int*)stock[STOCK_DISP];
    arch<<setw(4)<<' '<<setfill('0')<<setw(4)<<*cod<<setfill(' ')<<
            setw(10)<<*stockDisp<<endl;
}

void atiende(void *ped,void *sto){
    ofstream archR1=abrirArchE("ReportePedidos2.txt");
    ofstream archR2=abrirArchE("ReporteStock2.txt");
    ordenarPedidos(ped,0); /*se atiende en orden de fechas*/
    void **pedidos=(void**)ped;
    for(int i=0;pedidos[i];i++){
        atenderPedido(pedidos[i],sto);
    }
    imprimirPed(ped,archR1);
    imprimirSto(sto,archR2);
}

void ordenarPedidos(void *ped,int opcion){
    int numDat;
    void **pedidos=(void**)ped;
    for(numDat=0;pedidos[numDat];numDat++);
    qSort(pedidos,0,numDat-1,opcion);
}

void qSort(void **pedidos,int izq,int der,int opcion){
    int limite=izq;
    if(izq>=der) return;
    cambiar(pedidos[izq],pedidos[(izq+der)/2]);
    for(int i=izq+1;i<=der;i++){
        if(esMenor(pedidos[i],pedidos[izq],opcion)){
            cambiar(pedidos[i],pedidos[++limite]);
        }
    }
    cambiar(pedidos[izq],pedidos[limite]);
    qSort(pedidos,izq,limite-1,opcion);
    qSort(pedidos,limite+1,der,opcion);
}

bool esMenor(void *pedI,void *pedIzq,int opcion){
    void **pedidoI=(void**)pedI;
    void **pedidoIzq=(void**)pedIzq;
    if(opcion==0){
        int *fechaI=(int*)pedidoI[FECHA];
        int *fechaIzq=(int*)pedidoIzq[FECHA];
        return (*fechaI)<(*fechaIzq);
    }
    else{
        int *rucI=(int*)pedidoI[RUC];
        int *rucIzq=(int*)pedidoIzq[RUC];
        return (*rucI)<(*rucIzq);
    }
}

void cambiar(void *&dato1,void *&dato2){
    void *aux=dato1;
    dato1=dato2;
    dato2=aux;
}

void atenderPedido(void *pedido,void *sto){
    void **auxPed=(void**)pedido;
    void **stock=(void**)sto;
    void **auxStock;
    int *codigo=(int*)auxPed[COD],*cantS=(int*)auxPed[CANT_SOL],
            *cantA=(int*)auxPed[CANT_AT];
    int posProd,*stockDisp;
    posProd=buscarProd(*codigo,stock);
    if(posProd!=NO_ENCONTRADO){
        auxStock=(void**)stock[posProd];
        stockDisp=(int*)auxStock[STOCK_DISP];
        if(*stockDisp>*cantS){
            (*stockDisp)-=(*cantS);
            (*cantA)+=(*cantS);
        }
        else if(*stockDisp>0){
            (*cantA)+=(*stockDisp); /*entrega lo que haya*/
            *stockDisp=0;
        }
    }
}

int buscarProd(int codigo,void **stock){
    for(int i=0;stock[i];i++){
        if(esProducto(codigo,stock[i])) return i;
    }
    return NO_ENCONTRADO;
}

bool esProducto(int codigo,void *sto){
    void **auxSto=(void**)sto;
    int *cod=(int*)auxSto[COD_ST];
    return codigo==*cod;
}

void imprimirDatos(void *ped){
    ofstream arch("ReporteDeAtencion.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteDeAtencion.txt"<<endl;
        exit(1);
    }
    ordenarPedidos(ped,1);
    void **pedidos=(void**)ped;
    int ruc=0;
    arch<<setw(50)<<' '<<"REPORTE DE ATENCION"<<endl;
    for(int i=0;pedidos[i];i++){
        imprimirPedFinal(arch,pedidos[i],ruc);
    }
}

void imprimirPedFinal(ofstream &arch,void *ped,int &rucBase){
    void **pedido=(void**)ped;
    int *ruc=(int*)pedido[RUC],*fecha=(int*)pedido[FECHA],*codProd=(int*)pedido[COD];
    int *cantA=(int*)pedido[CANT_AT],*cantS=(int*)pedido[CANT_SOL];
    char *nombre=(char*)pedido[NOMB];
    if(rucBase<*ruc){
        rucBase=*ruc;
        imprimirLinea(arch,TAM_LINEA,'=');
        arch<<"RUC: "<<rucBase<<endl;
        imprimirLinea(arch,TAM_LINEA,'=');
        arch<<"FECHA"<<setw(7)<<' '<<"CODIGO"<<setw(3)<<' '<<"NOMBRE"<<setw(43)
            <<' '<<"CANT. SOLICITADA"<<setw(2)<<' '<<"CANT. ATENDIDA"<<endl;
        imprimirLinea(arch,TAM_LINEA,'=');
    }
    imprimirFecha(arch,*fecha);
    arch<<setfill('0')<<setw(4)<<*codProd<<setfill(' ')<<setw(4)<<' '<<left<<
            setw(50)<<nombre<<right<<setw(10)<<*cantS<<setw(13)<<*cantA<<endl;
}

void imprimirFecha(ofstream &arch,int fecha){
    int dd,mm,aa;
    aa=fecha/10000;
    mm=(fecha/100)%100;
    dd=fecha%100;
    arch<<setfill('0')<<setw(4)<<aa<<'/'<<setw(2)<<mm<<'/'<<setw(2)<<dd<<
            setfill(' ')<<setw(3)<<' ';
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}