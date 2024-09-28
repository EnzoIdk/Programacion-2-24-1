/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>      
#include <cstring>

using namespace std;

#include "AsignacionDinamicaMemoriaExacta.h"
#define MAX_DATOS 200
#define TAM_LINEA 140
#define CODIGO 7
#define NO_ENCONTRADO -1

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
        double *&precios){
    char **bufferProd[MAX_DATOS]{};
    int bufferStock[MAX_DATOS]{},numDatos=0;
    double bufferPrecios[MAX_DATOS]{};
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(true){
        bufferProd[numDatos]=leerDatosProd(arch);
        if(arch.eof()) break;
        arch>>bufferPrecios[numDatos];
        arch.get();
        arch>>bufferStock[numDatos];
        arch.get();
        numDatos++;
    }
    productos=new char **[numDatos+1]{};
    stock=new int[numDatos+1]{};
    precios=new double[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        productos[i]=bufferProd[i];
        stock[i]=bufferStock[i];
        precios[i]=bufferPrecios[i];
    }
}

char **leerDatosProd(ifstream &arch){
    char *bufferDatos[2]{},**productos;
    int numDatos=0;
    while(numDatos<2){
        bufferDatos[numDatos]=leerCadena(arch);
        if(arch.eof()) break;
        numDatos++;
    }
    productos=new char *[numDatos+1]{};
    for(int i=0;i<numDatos;i++) productos[i]=bufferDatos[i];
    return productos;
}

char *leerCadena(ifstream &arch){
    char buffer[100],*ptrCadena;
    arch.getline(buffer,100,',');
    if(arch.eof()) return nullptr;
    ptrCadena=new char[strlen(buffer)+1];
    strcpy(ptrCadena,buffer);
    return ptrCadena;
}

void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,int *stock,
        double *precios){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archReporte<<setprecision(2)<<fixed;
    archReporte<<"CODIGO"<<setw(5)<<' '<<"NOMBRE PRODUCTO"<<setw(44)<<' '<<
            "PRECIO"<<setw(4)<<' '<<"STOCK"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'=');
    for(int i=0;productos[i];i++){
        reporteProductos(archReporte,productos[i],stock[i],precios[i]);
    }
}

void reporteProductos(ofstream &archReporte,char **productos,int stock,double precio){
    /*si hubiesen varios datos del producto*/
//    for(int i=0;productos[i];i++){
//        archReporte<<productos[i]<<setw(3)<<' ';
//    }
    archReporte<<productos[0]<<setw(4)<<' '<<left<<setw(55)<<productos[1]<<right<<
            setw(10)<<precio<<setw(8)<<stock<<endl;
}

void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos){
    char **bufferCodPedidos[300]{};
    int **bufferDniCant[300]{};
    for(int i=0;i<300;i++){
        bufferCodPedidos[i]=new char*[100]{};
        bufferDniCant[i]=new int*[100]{};
    }
    int bufferFecha[300]{},numDatos=0;
    int nd[300]{};
    int dd,mm,aa,dni,cantidad,fecha,posFecha;
    char *codigo,car;
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
    }
    while(true){
        codigo=leerCadena(arch);
        if(arch.eof()) break;
        arch>>dni>>car>>cantidad>>car>>dd>>car>>mm>>car>>aa;
        arch.get(); /*se come el salto de linea*/
        fecha=dd+mm*100+aa*10000;
        posFecha=buscarFecha(fecha,bufferFecha);
        if(posFecha==NO_ENCONTRADO){
            bufferFecha[numDatos]=fecha;
            colocarCodDni(nd[numDatos],bufferCodPedidos[numDatos],codigo,bufferDniCant[numDatos],
                    dni,cantidad);
            numDatos++;
        }
        else{
            colocarCodDni(nd[posFecha],bufferCodPedidos[posFecha],codigo,bufferDniCant[posFecha],
                    dni,cantidad);
        }
    }
    fechaPedidos=new int[numDatos+1]{};
    codigoPedidos=new char**[numDatos+1]{};
    dniCantPedidos=new int**[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        fechaPedidos[i]=bufferFecha[i];
        espaciosExactosCodPed(codigoPedidos[i],bufferCodPedidos[i],nd[i]);
        espaciosExactosDniCant(dniCantPedidos[i],bufferDniCant[i],nd[i]);
    }
}

void espaciosExactosCodPed(char **&codPed,char **&bufferCodPed,int nd){
    char **codPedAux;
    if(nd!=0){
        codPedAux=new char*[nd+1]{};
        for(int i=0;i<nd;i++) codPedAux[i]=bufferCodPed[i];
        delete bufferCodPed; /*se borra para liberar espacio*/
        codPed=codPedAux;
    }
    else{
        delete bufferCodPed;
        codPed=nullptr;
    }
}

void espaciosExactosDniCant(int **&dniCantPed,int **&bufferDniCant,int nd){
    int **dniCantPedAux;
    if(nd!=0){
        dniCantPedAux=new int*[nd+1]{};
        for(int i=0;i<nd;i++) dniCantPedAux[i]=bufferDniCant[i];
        delete bufferDniCant;
        dniCantPed=dniCantPedAux;
    }
    else{
        delete bufferDniCant;
        dniCantPed=nullptr;
    }
}

void colocarCodDni(int &numDatos,char **&bufferCodPedidos,char *codigo,int **&bufferDniCant,
        int dni,int cantidad){
    bufferCodPedidos[numDatos]=codigo;
    bufferDniCant[numDatos]=new int[2+1]{};
    agregarDniCant(bufferDniCant[numDatos],dni,cantidad);
    numDatos++;
}

void agregarDniCant(int *dniCant,int dni,int cantidad){
    dniCant[0]=dni;
    dniCant[1]=cantidad;
}

int buscarFecha(int fecha,int *buffer){
    for(int i=0;buffer[i];i++){
        if(buffer[i]==fecha) return i;
    }
    return NO_ENCONTRADO;
}

void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archReporte<<"Reporte de pedidos"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'=');
    for(int i=0;fechaPedidos[i];i++){
        imprimirFecha(archReporte,fechaPedidos[i]);
        imprimirCodPedDni(archReporte,codigoPedidos[i],dniCantPedidos[i]);
    }
}

void imprimirCodPedDni(ofstream &archReporte,char **codPed,int **dniCantPed){
    archReporte<<"DNI"<<setw(10)<<' '<<"CODIGO"<<setw(10)<<' '<<"CANTIDAD PEDIDA"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'-');
    for(int i=0;codPed[i];i++){
        imprimirDatosFecha(archReporte,codPed[i],dniCantPed[i]);
    }
    imprimirLinea(archReporte,TAM_LINEA,'=');
}

void imprimirDatosFecha(ofstream &archReporte,char *codPed,int *dniCantPed){
    archReporte<<dniCantPed[0]<<setw(5)<<' '<<codPed<<setw(20)<<dniCantPed[1]<<endl;
}

void imprimirFecha(ofstream &archReporte,int fecha){
    int dd,mm,aa;
    aa=fecha/10000;
    mm=(fecha/100)%100;
    dd=fecha%100;
    archReporte<<"FECHA: "<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<
            setw(4)<<aa<<setfill(' ')<<endl;
}

void imprimirLinea(ofstream &archReporte,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) archReporte.put(simbolo);
    archReporte<<endl;
}

void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,int *stock,
        double *precios,int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    double totalIngresos,totalPerdido,finalIngresos=0,finalPerdidos=0;
    archReporte<<setprecision(2)<<fixed;
    archReporte<<setw(30)<<' '<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    for(int i=0;fechaPedidos[i];i++){
        imprimirLinea(archReporte,TAM_LINEA,'=');
        imprimirFecha(archReporte,fechaPedidos[i]);
        imprimirLinea(archReporte,TAM_LINEA,'=');
        archReporte<<"No."<<setw(4)<<' '<<"DNI"<<setw(20)<<' '<<"Producto"<<
                setw(54)<<' '<<"Cantidad"<<setw(5)<<' '<<"Precio"<<
                setw(5)<<' '<<"Total de ingresos"<<endl;
        imprimirLinea(archReporte,TAM_LINEA,'-');
        totalIngresos=totalPerdido=0;
        imprimirDatosPedidos(archReporte,productos,stock,precios,codigoPedidos[i],
                dniCantPedidos[i],totalIngresos,totalPerdido);
        imprimirLinea(archReporte,TAM_LINEA,'-');
        archReporte<<"Total ingresado: "<<setw(117)<<totalIngresos<<endl;
        archReporte<<"Total perdido por falta de stock: "<<setw(100)<<totalPerdido<<endl;
        finalIngresos+=totalIngresos;
        finalPerdidos+=totalPerdido;
    }
    imprimirLinea(archReporte,TAM_LINEA,'=');
    archReporte<<"Resumen de ingresos: "<<endl;
    archReporte<<"Total de ingresos en el periodo: "<<setw(101)<<finalIngresos<<endl;
    archReporte<<"Total perdido por falta de stock: "<<setw(100)<<finalPerdidos<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'=');
}

void imprimirDatosPedidos(ofstream &archReporte,char ***productos,int *stock,
        double *precios,char **codigoPedido,int **dniCant,double &totalIngresos,
        double &totalPerdido){
    int posProducto,nro=0;
    for(int i=0;codigoPedido[i];i++){
        posProducto=buscarProducto(productos,codigoPedido[i]);
        if(posProducto!=NO_ENCONTRADO){
            imprimirDatosPedidoProducto(archReporte,productos[posProducto],
                    stock[posProducto],precios[posProducto],codigoPedido[i],
                    dniCant[i],totalIngresos,totalPerdido,nro);
        }
    }
}

int buscarProducto(char ***productos,char *codPed){
    for(int i=0;productos[i];i++){
        if(esProducto(productos[i],codPed)) return i;
    }
    return NO_ENCONTRADO;
}

int esProducto(char **producto,char *codPed){
    if(strcmp(producto[0],codPed)==0) return 1;
    return 0;
}

void imprimirDatosPedidoProducto(ofstream &archReporte,char **producto,int &stock,
        double precio,char *codPedido,int *dniCant,double &totalIngresos,double &totalPerdido,int &nro){
    nro++;
    archReporte<<setw(2)<<nro<<')'<<setw(3)<<' '<<dniCant[0]<<setw(10)<<' '<<
            producto[0]<<setw(4)<<' '<<left<<setw(57)<<producto[1]<<right<<
            setw(5)<<dniCant[1]<<setw(17)<<precio;
    if(stock>=dniCant[1]){
        archReporte<<setw(20)<<dniCant[1]*precio<<endl;
        stock-=dniCant[1];
        totalIngresos+=dniCant[1]*precio;
    }
//    else if(stock>0){ /*esto sería si se pudiese entregar el stock disponible
//                       *  pero el problema dice que es todo o nada*/
//        archReporte<<setw(20)<<stock*precio<<endl;
//        totalIngresos+=stock*precio;
//        stock=0;
//    } 
    else{
        archReporte<<setw(20)<<"SIN STOCK"<<endl;
        totalPerdido+=dniCant[1]*precio;
    }
}