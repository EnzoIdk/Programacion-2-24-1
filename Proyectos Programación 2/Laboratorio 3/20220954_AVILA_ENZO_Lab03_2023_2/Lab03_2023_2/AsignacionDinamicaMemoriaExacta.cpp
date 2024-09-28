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
#define NO_ENCONTRADO -1
#define INCREMENTO 5
#define TAM_LINEA 130

void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,
        double *&precios){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char **auxProd;
    int sto,numDat=0,cap=0;
    double precio;
    while(true){
        auxProd=leerAuxProd(arch);
        if(arch.eof()) break;
        arch>>precio;
        arch.get();
        arch>>sto;
        arch.get();
        if(numDat==cap) aumentarCap(productos,stock,precios,numDat,cap);
        productos[numDat-1]=auxProd;
        stock[numDat-1]=sto;
        precios[numDat-1]=precio;
        numDat++;
    }
}

void aumentarCap(char ***&productos,int *&stock,double *&precios,int &numDat,int &cap){
    cap+=INCREMENTO;
    char ***auxProd=new char**[cap]{};
    int *auxStock=new int[cap]{};
    double *auxPrecios=new double[cap]{};
    if(numDat==0) numDat=1;
    else{
        for(int i=0;i<numDat;i++){
            auxProd[i]=productos[i];
            auxStock[i]=stock[i];
            auxPrecios[i]=precios[i];
        }
        delete productos;
        delete stock;
        delete precios;
    }
    productos=auxProd;
    stock=auxStock;
    precios=auxPrecios;
}

char **leerAuxProd(ifstream &arch){
    char **aux;
    aux=new char*[2]{};
    aux[0]=leerCadena(arch);
    if(arch.eof()) return nullptr;
    aux[1]=leerCadena(arch);
    return aux;
}

char *leerCadena(ifstream &arch){
    char cadena[60],*ptr;
    arch.getline(cadena,60,',');
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,
        int *stock,double *precios){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char **auxProd;
    archRep<<setprecision(2)<<fixed;
    for(int i = 0;productos[i];i++){
        auxProd=productos[i];
        archRep<<setw(11)<<auxProd[0]<<setw(4)<<' '<<left;
        archRep<<setw(60)<<auxProd[1]<<right;
        archRep<<setw(6)<<stock[i]<<setw(16)<<precios[i]<<endl;
    }
}

void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char *codProd;
    int dni,cant,fecha,posFecha,numDat=0,cap=0;
    int *arrND,*arrCap;
    while(true){
        codProd=leerCadena(arch);
        if(arch.eof()) break;
        leerDatosPed(arch,dni,cant,fecha);
        posFecha=buscarFecha(fechaPedidos,fecha,numDat);
        if(posFecha==NO_ENCONTRADO){
            if(numDat==cap) aumentarCapFecha(fechaPedidos,
                    codigoPedidos,dniCantPedidos,arrND,arrCap,numDat,cap);
            posFecha=numDat-1;
            fechaPedidos[posFecha]=fecha;
            numDat++;
        }
        insertarDatosDeFecha(arrND[posFecha],arrCap[posFecha],dniCantPedidos[posFecha],
                codigoPedidos[posFecha],dni,cant,codProd);
    }
}

void aumentarCapFecha(int *&fechaPedidos,char ***&codPed,int ***&dniCant,
        int *&arrND,int *&arrCap,int &numDat,int &cap){
    cap+=INCREMENTO;
    int *auxFecha=new int[cap]{},***auxDniCant=new int**[cap]{};
    int *auxND=new int[cap]{},*auxCap=new int[cap]{};
    char ***auxCodPed=new char**[cap]{};
    if(numDat==0) numDat=1;
    else{
        for(int i=0;i<numDat;i++){
            auxFecha[i]=fechaPedidos[i];
            auxDniCant[i]=dniCant[i];
            auxCodPed[i]=codPed[i];
            auxND[i]=arrND[i];
            auxCap[i]=arrCap[i];
        }
        delete fechaPedidos;
        delete dniCant;
        delete codPed;
        delete arrND;
        delete arrCap;
    }
    fechaPedidos=auxFecha;
    dniCant=auxDniCant;
    codPed=auxCodPed;
    arrND=auxND;
    arrCap=auxCap;
}

void insertarDatosDeFecha(int &numDatos,int &cap,int **&dniCant,char **&codPed,
        int dni,int cant,char *codProd){
    if(numDatos==cap) aumentarCapDatosFecha(dniCant,codPed,numDatos,cap);
    dniCant[numDatos-1]=insertarDniCant(dni,cant);
    codPed[numDatos-1]=codProd;
    numDatos++;
}

void aumentarCapDatosFecha(int **&dniCant,char **&codPed,int &numDatos,int &cap){
    cap+=INCREMENTO;
    int **auxDniCant=new int*[cap]{};
    char **auxCodPed=new char*[cap]{};
    if(numDatos==0) numDatos=1;
    else{
        for(int i=0;i<numDatos;i++){
            auxCodPed[i]=codPed[i];
            auxDniCant[i]=dniCant[i];
        }
        delete codPed;
        delete dniCant;
    }
    codPed=auxCodPed;
    dniCant=auxDniCant;
}

int *insertarDniCant(int dni,int cant){
    int *aux;
    aux=new int[2]{};
    aux[0]=dni;
    aux[1]=cant;
    return aux;
}

int leerDatosPed(ifstream &arch,int &dni,int &cant,int &fecha){
    int dd,mm,aa;
    char car;
    arch>>dni>>car>>cant>>car>>dd>>car>>mm>>car>>aa;
    arch.get();
    fecha=aa*10000+mm*100+dd;
}

int buscarFecha(int *fechas,int dato,int numDat){
    for(int i=0;i<numDat;i++){
        if(dato==fechas[i]) return i;
    }
    return NO_ENCONTRADO;
}

void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,
        char ***codigoPedidos,int ***dniCantPedidos){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archRep<<setprecision(2)<<fixed;
    for(int i=0;fechaPedidos[i];i++){
        imprimirFecha(archRep,fechaPedidos[i]);
        imprimirDatosPedidos(archRep,codigoPedidos[i],dniCantPedidos[i]);
    }
}

void imprimirDatosPedidos(ofstream &arch,char **codPed,int **dniCant){
    int *auxDniCant;
    arch<<"CODIGO"<<setw(5)<<' '<<"DNI"<<setw(5)<<' '<<"CANTIDAD"<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    for(int i=0;codPed[i];i++){
        auxDniCant=dniCant[i];
        arch<<codPed[i]<<setw(10)<<auxDniCant[0]<<setw(5)<<auxDniCant[1]<<endl;
    }
}

void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,int *stock,
        double *precios,int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numFechas=0;
    while(fechaPedidos[numFechas]) numFechas++;
    qSort(fechaPedidos,codigoPedidos,dniCantPedidos,0,numFechas-1);
    double ingresoFinal=0,perdidaFinal=0,ingresoParcial,perdidaParcial;
    arch<<setprecision(2)<<fixed;
    arch<<setw(40)<<' '<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    for(int i=0;fechaPedidos[i];i++){
        imprimirFecha(arch,fechaPedidos[i]);
        imprimirEncabezado(arch);
        imprimirDatosPedFecha(arch,productos,stock,precios,codigoPedidos[i],
                dniCantPedidos[i],ingresoParcial,perdidaParcial);
        imprimirLinea(arch,TAM_LINEA,'-');
        arch<<"Total ingresado: "<<setw(40)<<ingresoParcial<<endl;
        arch<<"Total perdido por falta de stock: "<<setw(30)<<perdidaParcial<<endl;
        ingresoFinal+=ingresoParcial;
        perdidaFinal+=perdidaParcial;
    }
    imprimirLinea(arch,TAM_LINEA,'=');
    arch<<"Resumen de ingresos: "<<endl;
    arch<<"Total de ingresos en el periodo: "<<setw(40)<<ingresoFinal<<endl;
    arch<<"Total perdido por falta de stock: "<<setw(39)<<perdidaFinal<<endl;
    imprimirLinea(arch,TAM_LINEA,'=');
}

void qSort(int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos,int izq,int der){
    int limite=izq,pos=(izq+der)/2;
    if(izq>=der) return;
    cambiarF(fechaPedidos[izq],fechaPedidos[pos]);
    cambiarC(codigoPedidos[izq],codigoPedidos[pos]);
    cambiarD(dniCantPedidos[izq],dniCantPedidos[pos]);
    for(int i=izq+1;i<=der;i++){
        if(fechaPedidos[i]<fechaPedidos[izq]){
            limite++;
            cambiarF(fechaPedidos[limite],fechaPedidos[i]);
            cambiarC(codigoPedidos[limite],codigoPedidos[i]);
            cambiarD(dniCantPedidos[limite],dniCantPedidos[i]);
        }
    }
    cambiarF(fechaPedidos[limite],fechaPedidos[izq]);
    cambiarC(codigoPedidos[limite],codigoPedidos[izq]);
    cambiarD(dniCantPedidos[limite],dniCantPedidos[izq]);
    qSort(fechaPedidos,codigoPedidos,dniCantPedidos,izq,limite-1);
    qSort(fechaPedidos,codigoPedidos,dniCantPedidos,limite+1,der);
}

void cambiarF(int &dato1,int &dato2){
    int aux=dato1;
    dato1=dato2;
    dato2=aux;
}

void cambiarC(char **&dato1,char **&dato2){
    char **aux=dato1;
    dato1=dato2;
    dato2=aux;
}

void cambiarD(int **&dato1,int **&dato2){
    int **aux=dato1;
    dato1=dato2;
    dato2=aux;
}

void imprimirDatosPedFecha(ofstream &arch,char ***productos,int *stock,double *precios,
        char **codPed,int **dniCant,double &ingresos,double &perdidas){
    int *auxDniCant,posProd;
    char **auxProd;
    ingresos=perdidas=0;
    for(int i=0;codPed[i];i++){
        auxDniCant=dniCant[i];
        arch<<setw(3)<<i+1<<')'<<setw(2)<<' '<<auxDniCant[0]<<setw(8)<<' '<<
                codPed[i]<<setw(3)<<' '<<left<<setw(60);
        posProd=buscarProd(productos,codPed[i]);
        if(posProd!=NO_ENCONTRADO){
            auxProd=productos[posProd];
            arch<<auxProd[1]<<right<<setw(4)<<auxDniCant[1]<<setw(20)<<
                    precios[posProd]<<setw(30);
            if(stock[posProd]>=auxDniCant[1]){
                arch<<precios[posProd]*auxDniCant[1]<<endl;
                ingresos+=precios[posProd]*auxDniCant[1];
                stock[posProd]-=auxDniCant[1];
            }
            else{
                arch<<"SIN STOCK"<<endl;
                perdidas+=precios[posProd]*auxDniCant[1];
            }
        }
    }
}

int buscarProd(char ***productos,char *codigo){
    char **auxProd;
    for(int i=0;productos[i];i++){
        auxProd=productos[i];
        if(strcmp(auxProd[0],codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

void imprimirFecha(ofstream &arch,int fecha){
    int dd,mm,aa;
    aa=fecha/10000;
    mm=(fecha/100)%100;
    dd=fecha%100;
    imprimirLinea(arch,TAM_LINEA,'=');
    arch<<"FECHA:"<<setw(3)<<' '<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<
            mm<<'/'<<setw(4)<<aa<<setfill(' ')<<endl;
    imprimirLinea(arch,TAM_LINEA,'=');
}

void imprimirEncabezado(ofstream &arch){
    arch<<"No. "<<setw(4)<<' '<<"DNI"<<setw(20)<<' '<<"Producto"<<setw(20)<<' '<<
            "Cantidad"<<setw(10)<<' '<<"Precio"<<setw(5)<<' '<<"Total de ingresos"<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}