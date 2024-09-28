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
#define MAX_DATOS 200
#define TAM_LINEA 140
#define CODIGO 7
#define NO_ENCONTRADO -1

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
        double *&precios){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char **bufferProductos[200]{};
    int bufferStock[200]{},numDatos=0;
    double bufferPrecios[200]{};
    while(true){
        bufferProductos[numDatos]=leerProductos(arch);
        if(arch.eof()) break;
        arch>>bufferPrecios[numDatos];
        arch.get();
        arch>>bufferStock[numDatos];
        arch.get();
        numDatos++;
    }   
    llenarPunteros(productos,stock,precios,bufferPrecios,bufferProductos,
            bufferStock,numDatos);
}

void llenarPunteros(char ***&productos,int *&stock,double *&precios,
        double *bufferPrecios,char ***bufferProductos,int *bufferStock,int numDatos){
    productos=new char**[numDatos+1]{};
    stock=new int[numDatos+1]{};
    precios=new double[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        productos[i]=bufferProductos[i];
        stock[i]=bufferStock[i];
        precios[i]=bufferPrecios[i];
    }
}

char **leerProductos(ifstream &arch){
    char **productos,*codigo,*nombre;
    codigo=leerCadena(arch);
    if(arch.eof()) return nullptr;
    nombre=leerCadena(arch);
    productos=new char*[2]{};
    productos[0]=codigo;
    productos[1]=nombre;
    return productos;
}

char *leerCadena(ifstream &arch){
    char cadena[60],*ptr;
    arch.getline(cadena,60,',');
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,int *stock,
        double *precios){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    arch<<"INFORMACION DE PRODUCTOS"<<endl;
    arch<<"CODIGO"<<setw(3)<<' '<<"NOMBRE"<<setw(30)<<' '<<"STOCK"<<setw(4)<<' '<<
            "PRECIOS"<<endl;
    for(int i=0;productos[i];i++){
        imprimirProductos(arch,productos[i],stock[i],precios[i]);
    }
}

void imprimirProductos(ofstream &arch,char **productos,int stock,double precio){
    arch<<productos[0]<<setw(3)<<' '<<left<<setw(40)<<productos[1]<<right<<
            setw(4)<<stock<<setw(10)<<precio<<endl;
}

void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int bufferFechas[300]{},**bufferDniCantPed[300]{},nd[300]{};
    char *codigo,car,**bufferCodPed[300]{};
    for(int i=0;i<300;i++){
        bufferCodPed[i]=new char*[100]{};
        bufferDniCantPed[i]=new int*[100]{};
    }
    int dni,cant,dd,mm,aa,fecha,numDatos=0,posFecha;
    while(true){
        codigo=leerCadena(arch);
        if(arch.eof()) break;
        arch>>dni>>car>>cant>>car>>dd>>car>>mm>>car>>aa;
        arch.get(); /*salto de linea*/
        fecha=aa*10000+mm*100+dd;
        posFecha=buscarFecha(bufferFechas,fecha);
        if(posFecha==NO_ENCONTRADO){
            bufferFechas[numDatos]=fecha;
            agregarDatos(bufferDniCantPed[numDatos],bufferCodPed[numDatos],
                    dni,cant,codigo,nd[numDatos]);
            numDatos++;
        }
        else{
            agregarDatos(bufferDniCantPed[posFecha],bufferCodPed[posFecha],
                    dni,cant,codigo,nd[posFecha]);
        }
    }
    llenarPunterosPedidos(fechaPedidos,codigoPedidos,dniCantPedidos,bufferFechas,
            bufferCodPed,bufferDniCantPed,nd,numDatos);
}

void llenarPunterosPedidos(int *&fechaPedidos,char ***&codigoPedidos,int ***&dniCantPedidos,
        int *bufferFechas,char ***bufferCodPed,int ***bufferDniCantPed,int *nd,int numDatos){
    fechaPedidos=new int[numDatos+1]{};
    codigoPedidos=new char**[numDatos+1]{};
    dniCantPedidos=new int**[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        fechaPedidos[i]=bufferFechas[i];
        espacioExactoCodPed(codigoPedidos[i],bufferCodPed[i],nd[i]);
        espacioExactoDniCant(dniCantPedidos[i],bufferDniCantPed[i],nd[i]);
    }
}

void espacioExactoCodPed(char **&codigoPedido,char **&bufferCodPed,int nd){
    char **codPedAux;
    if(nd!=0){
        codPedAux=new char*[nd+1]{};
        for(int i=0;i<nd;i++) codPedAux[i]=bufferCodPed[i];
        delete bufferCodPed;
        codigoPedido=codPedAux;
    }
    else{
        delete bufferCodPed;
        codigoPedido=nullptr;
    }
}

void espacioExactoDniCant(int **&dniCant,int **&bufferDniCant,int nd){
    int **dniCantAux;
    if(nd!=0){
        dniCantAux=new int*[nd+1]{};
        for(int i=0;i<nd;i++) dniCantAux[i]=bufferDniCant[i];
        delete bufferDniCant;
        dniCant=dniCantAux;
    }
    else{
        delete bufferDniCant;
        dniCant=nullptr;
    }
}

void agregarDatos(int **&bufferDniCantPed,char **&bufferCodPed,int dni,int cant,
        char *codigo,int &nd){
    bufferCodPed[nd]=codigo;
    bufferDniCantPed[nd]=new int[2]{};
    agregarDniCantPed(bufferDniCantPed[nd],dni,cant);
    nd++;
}

void agregarDniCantPed(int *dniCantPed,int dni,int cant){
    dniCantPed[0]=dni;
    dniCantPed[1]=cant;
}

int buscarFecha(int *fechas,int fecha){
    for(int i=0;fechas[i];i++){
        if(fechas[i]==fecha) return i;
    }
    return NO_ENCONTRADO;
}

void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for(int i=0;fechaPedidos[i];i++){
        imprimirLinea(arch,TAM_LINEA,'=');
        imprimirFecha(arch,fechaPedidos[i]);
        arch<<"CODIGO"<<setw(2)<<' '<<"DNI"<<setw(2)<<' '<<"CANTIDAD"<<endl;
        imprimirDatosFecha(arch,codigoPedidos[i],dniCantPedidos[i]);
    }
}

void imprimirDatosFecha(ofstream &arch,char **codPedidos,int **dniCantPedidos){
    for(int i=0;codPedidos[i];i++){
        imprimirCodDniCant(arch,codPedidos[i],dniCantPedidos[i]);
    }
}

void imprimirCodDniCant(ofstream &arch,char *codPedido,int *dniCant){
    arch<<codPedido<<setw(2)<<' '<<dniCant[0]<<setw(2)<<' '<<dniCant[1]<<endl;
}

void imprimirFecha(ofstream &arch,int fecha){
    int dd,mm,aa;
    dd=fecha%100;
    mm=(fecha/100)%100;
    aa=fecha/10000;
    arch<<"FECHA: "<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<
            aa<<setfill(' ')<<endl;
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
}

void imprimirDatosPedidos(ofstream &archReporte,char ***productos,int *stock,
        double *precios,char **codigoPedido,int **dniCant,double &totalIngresos,
        double &totalPerdido){
    int posProducto,nro=0;
//    char **aux;
//    int *auxInt;
    for(int i=0;codigoPedido[i];i++){
        posProducto=buscarProducto(productos,codigoPedido[i]);
        if(posProducto!=NO_ENCONTRADO){
//            nro++;
//            aux=productos[posProducto];
//            archReporte<<setw(2)<<nro<<')'<<setw(3)<<' '<<dniCant[i]<<setw(10)<<' '<<
//            producto[0]<<setw(4)<<' '<<left<<setw(57)<<producto[1]<<right<<
//            setw(5)<<dniCant[1]<<setw(17)<<precio;
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

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
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