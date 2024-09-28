#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstring>
#include <cstdlib>

using namespace std;

#include "funciones.h"
#define TAM_LINEA 120
#define NO_ENCONTRADO -1
enum Ventas{FECHA,RUC,COD,CANT};
enum Prod{CODPROD,NOMBRE,PRECIO};

void leeVentas(void *&vent){
    void *buffV[500],**ventas,*reg;
    int numV=0;
    ifstream arch("ventas.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ventas.csv"<<endl;
        exit(1);
    }
    while(true){
        reg=leerRegVenta(arch);
        if(arch.eof()) break;
        buffV[numV]=reg;
        numV++;
    }
    ventas=new void*[numV+1]{};
    for(int i=0;i<numV;i++) ventas[i]=buffV[i];
    vent=ventas;
}

void *leerRegVenta(ifstream &arch){
    int fec,*fecha,*ruc,*cant;
    char *codProd;
    void **reg;
    arch>>fec;
    if(arch.eof()) return nullptr;
    arch.get();
    fecha=new int;
    *fecha=fec;
    ruc=new int;
    arch>>*ruc;
    arch.get();
    codProd=leerCadena(arch,',');
    cant=new int;
    arch>>*cant;
    reg=new void*[4]{};
    reg[FECHA]=fecha;
    reg[RUC]=ruc;
    reg[COD]=codProd;
    reg[CANT]=cant;
    return reg;
}

char *leerCadena(ifstream &arch,char delim){
    char cadena[60],*ptr;
    arch.getline(cadena,60,delim);
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void imprimeVentas(void *vent){
    void **ventas=(void**)vent;
    ofstream arch("RepVentas.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir RepVentas.txt"<<endl;
        exit(1);
    }
    arch<<setw(9)<<"Fecha"<<setw(8)<<"RUC"<<setw(13)<<"Codigo"<<setw(8)<<
            "Cant"<<endl;
    for(int i=0;ventas[i];i++){
        imprimeVenta(ventas[i],arch);
    }
}

void imprimeVenta(void *registro,ofstream &arch){
    int *fecha,*ruc,*cant;
    char *codProd;
    void **reg=(void**)registro;
    fecha=(int*)(reg[FECHA]);
    ruc=(int*)(reg[RUC]);
    codProd=(char*)(reg[COD]);
    cant=(int*)(reg[CANT]);
    arch<<setw(10)<<*fecha<<setw(10)<<*ruc<<setw(10)<<codProd<<setw(7)<<
            *cant<<endl;
}

void leeProductos(void *&prod){
    ifstream arch("productos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo productos.txt"<<endl;
        exit(1);
    }
    void *buffP[200],**productos,*reg;
    int numP=0;
    while(true){
        reg=leerRegProd(arch);
        if(arch.eof()) break;
        buffP[numP]=reg;
        numP++;
    }
    productos=new void*[numP+1]{};
    for(int i=0;i<numP;i++) productos[i]=buffP[i];
    prod=productos;
}

void *leerRegProd(ifstream &arch){
    void **reg=new void*[3]{};
    char *codigo,*nombre;
    double *precio=new double;
    codigo=leerCadena(arch,',');
    if(arch.eof()) return nullptr;
    nombre=leerCadena(arch,',');
    arch>>*precio;
    arch.get();
    reg[CODPROD]=codigo;
    reg[NOMBRE]=nombre;
    reg[PRECIO]=precio;
    return reg;
}

void imprimeProductos(void *prod){
    void **productos=(void**)prod;
    ofstream arch("RepProductos.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RepProductos.txt"<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    arch<<setw(4)<<' '<<"CODIGO"<<setw(4)<<' '<<"NOMBRE"<<setw(45)<<"PRECIO"<<endl;
    for(int i=0;productos[i];i++){
        imprimirProducto(arch,productos[i]);
    }
}

void imprimirProducto(ofstream &arch,void *prod){
    void **producto=(void**)prod;
    char *codigo=(char*)producto[CODPROD],*nombre=(char*)producto[NOMBRE];
    double *precio=(double*)producto[PRECIO];
    arch<<setw(3)<<' '<<codigo<<setw(4)<<' '<<left<<setw(60)<<nombre<<
            right<<setw(8)<<*precio<<endl;
}

void leeClientes(void *&cli){
    void **clientes,*bufferCli[200]{},*reg;
    int numDat=0;
    ifstream arch("clientes.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo clientes.csv"<<endl;
        exit(1);
    }
    while(true){
        reg=leerRegCli(arch);
        if(arch.eof()) break;
        bufferCli[numDat]=reg;
        numDat++;
    }
    clientes=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) clientes[i]=bufferCli[i];
    cli=clientes;
}

void *leerRegCli(ifstream &arch){
    void **cliente;
    int *ruc=new int;
    char *nombre;
    arch>>*ruc;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre=leerCadena(arch,'\n');
    cliente=new void*[2]{};
    cliente[0]=ruc;
    cliente[1]=nombre;
    return cliente;
}

void imprimeClientes(void *cli){
    ofstream arch("RepClientes.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RepClientes.txt"<<endl;
        exit(1);
    }
    void **clientes=(void**)cli;
    arch<<setw(2)<<' '<<"RUC"<<setw(8)<<' '<<"NOMBRE"<<endl;
    for(int i=0;clientes[i];i++){
        imprimeCliente(arch,clientes[i]);
    }
}

void imprimeCliente(ofstream &arch,void *cli){
    void **cliente=(void**)cli;
    int *ruc=(int*)cliente[0];
    char *nombre=(char*)cliente[1];
    arch<<setw(2)<<' '<<*ruc<<setw(3)<<' '<<nombre<<endl;
}

void liquidaVentas(void *cli,void *vent,void *prod){
    char rucSt[15],mesSt[5],nombArch[20];
    int ruc,mes;
    void *liquidacion;
    ifstream arch("ingreso.txt",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ingreso.txt"<<endl;
        exit(1);
    }
    while(true){
        arch>>rucSt>>mesSt;
        if(arch.eof()) break;
        /*atoi convierte una cadena a entero*/
        ruc=atoi(rucSt);
        mes=atoi(mesSt);
        strcpy(nombArch,rucSt);
        if(mes<10) strcat(nombArch,"0");
        strcat(nombArch,mesSt);
        strcat(nombArch,".txt");
        liquidacion=nullptr;
        generarLiquidacion(liquidacion,ruc,mes,vent,prod);
        reporteLiquidacion(nombArch,ruc,liquidacion,prod,cli);
        eliminaLiquidacion(liquidacion);
    }
}

void generarLiquidacion(void *&liquid,int ruc,int mes,void *vent,void *productos){
    void *buffLiq[200]{},**liquidacion;
    int numLiq=0;
    void **ventas=(void**)vent;
    for(int i=0;ventas[i];i++){
        liquidar(ruc,mes,ventas[i],productos,buffLiq,numLiq);
    }
    liquidacion=new void*[numLiq+1]{};
    for(int i=0;i<numLiq;i++) liquidacion[i]=buffLiq[i];
    liquid=liquidacion;
}

void liquidar(int ruc,int mes,void *ven,void *prod,void **buffLiq,int &numLiq){
    void **venta=(void**)ven,**productos=(void**)prod,**regAux;
    char *codProd=(char*)venta[COD];
    int *nRuc=(int*)venta[RUC],*fecha=(int*)venta[FECHA],*cant=(int*)venta[CANT];
    int mesV=((*fecha)/100)%100 , posProd;
    double *precio;
    if(ruc==*nRuc and mes==mesV){
        posProd=buscarProd(codProd,productos);
        if(posProd!=NO_ENCONTRADO){
            regAux=(void**)(productos[posProd]);
            precio=(double*)regAux[PRECIO];
            agregarVenta(codProd,(*cant)*(*precio),buffLiq,numLiq);
        }
    }
}

int buscarProd(char *codProd,void **productos){
    for(int i=0;productos[i];i++){
        if(esProducto(codProd,productos[i])) return i; 
    }
    return NO_ENCONTRADO;
}

bool esProducto(char *codProd,void *prod){
    void **producto=(void**)prod;
    char *cod=(char*)producto[CODPROD];
    return strcmp(codProd,cod)==0;
}

void agregarVenta(char *codProd,double monto,void **buffLiq,int &numLiq){
    void **regAux;
    double *montAux;
    int posLiq;
    posLiq=buscarLiq(codProd,buffLiq);
    if(posLiq!=NO_ENCONTRADO){
        regAux=(void**)buffLiq[posLiq];
        montAux=(double*)regAux[1];
        (*montAux)+=monto; /*estamos cambiando el valor en la dirección de memoria*/
    }
    else{
        regAux=new void*[2]{};
        montAux=new double;
        *montAux=monto;
        regAux[0]=codProd;
        regAux[1]=montAux;
        buffLiq[numLiq]=regAux;
        numLiq++;
    }
}

int buscarLiq(char *codProd,void **bufferLiq){
    for(int i=0;bufferLiq[i];i++){
        if(esLiq(codProd,bufferLiq[i])) return i;
    }
    return NO_ENCONTRADO;
}

bool esLiq(char *codProd,void *liq){
    void **liquidacion=(void**)liq;
    char *cod=(char*)liquidacion[0];
    return strcmp(codProd,cod)==0;
}

void reporteLiquidacion(const char *nombArch,int ruc,void *liquid,void *prod,
        void *cli){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **liquidacion=(void**)liquid,**clientes=(void**)cli,**auxCli;
    char *nombreCli=nullptr;
//    int rucA;
    int posCli=buscarCliente(ruc,clientes),nDat=0;
    if(posCli!=NO_ENCONTRADO){
        auxCli=(void**)clientes[posCli];
        nombreCli=(char*)auxCli[1];
//        rucA=*(int*)auxCli[0]; compila así
    }
    if(nombreCli!=nullptr){
        arch<<setprecision(2)<<fixed;
        arch<<setw(20)<<' '<<"Liquidacion: "<<nombreCli<<endl;
        imprimirLinea(arch,TAM_LINEA,'=');
        arch<<setw(2)<<' '<<"CODIGO"<<setw(5)<<' '<<"NOMBRE DEL PRODUCTO"<<
            setw(50)<<' '<<"IMPORTE"<<endl;
        imprimirLinea(arch,TAM_LINEA,'=');
        for(int i=0;liquidacion[i];i++){
            imprimirLiquidacion(arch,liquidacion[i],prod);
            nDat++;
        }
        if(nDat==0) arch<<setw(20)<<' '<<"NO HAY PRODUCTOS LIQUIDADOS PARA MOSTRAR"<<endl;
        imprimirLinea(arch,TAM_LINEA,'=');
    }
}

int buscarCliente(int ruc,void **clientes){
    for(int i=0;clientes[i];i++){
        if(esCliente(ruc,clientes[i])) return i;
    }
    return NO_ENCONTRADO;
}

bool esCliente(int ruc,void *cli){
    void **cliente=(void**)cli;
    int *rucCli=(int*)cliente[0];
    return ruc==*rucCli;
}

void imprimirLiquidacion(ofstream &arch,void *liq,void *prod){
    void **liquidacion=(void**)liq,**productos=(void**)prod,**regAuxProd;
    char *codigo=(char*)liquidacion[0],*nombProd;
    double *monto=(double*)liquidacion[1];
    int posProd;
    posProd=buscarProd(codigo,productos);
    if(posProd!=NO_ENCONTRADO){
        regAuxProd=(void**)productos[posProd];
        nombProd=(char*)regAuxProd[NOMBRE];
    }
    arch<<setw(2)<<' '<<codigo<<setw(5)<<' '<<left<<setw(60)<<nombProd<<
            right<<setw(10)<<*monto<<endl;
}

void eliminaLiquidacion(void *liq){
    void **liquidaciones=(void**)liq;
    for(int i=0;liquidaciones[i];i++) eliminaRegLiq(liquidaciones[i]);
    delete liquidaciones;
}

void eliminaRegLiq(void *liq){
    void **liquidacion=(void**)liq;
    char *codigo=(char*)liquidacion[0];
    double *monto=(double*)liquidacion[1];
    delete codigo;
    delete monto;
    delete liquidacion;
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}