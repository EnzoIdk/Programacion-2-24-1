/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "ClientesPreg1.h"
#include "FuncionesExamen01Pregunta01.h"
#define NO_ENCONTRADO -1
#define INCREMENTO 5

void CargarProductosPedidos(int **&proInfo,char **&proDesc,int **&pedTodo,
        const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int *bufferInfo[100]{},*bufferPed[150]{},ndProd=0,numPed=0;
    int codigo,descuento,precio,stock,fecha,cantPed,dni,posProd;
    char *bufferDesc[100]{},*descripcion;
    while(true){
        leerDatos(arch,codigo,descripcion,descuento,precio,cantPed,stock,dni,fecha);
        if(arch.eof()) break;
        posProd=buscarProd(bufferInfo,codigo);
        if(posProd==NO_ENCONTRADO){
            agregarInfoProd(bufferInfo[ndProd],codigo,descuento,precio,stock);
            bufferDesc[ndProd]=descripcion;
            ndProd++;
        }
        agregarPed(bufferPed[numPed],dni,fecha,cantPed,codigo);
        numPed++;
    }
    asignarBuffers(proInfo,proDesc,pedTodo,ndProd,numPed,bufferInfo,bufferDesc,bufferPed);
}

void leerDatos(ifstream &arch,int &codigo,char *&descripcion,int &descuento,int &precio,
        int &cantPed,int &stock,int &dni,int &fecha){
    int dd,mm,aa;
    double descD,cantD,precioD,stockD;
    char car;
    arch>>codigo;
    if(arch.eof()) return;
    arch.get();
    descripcion=leerCadena(arch);
    arch>>descD;
    if(arch.get()!='%'){
        cantD=descD;
        descD=0;
    }
    else arch>>car>>cantD>>car;
    arch>>precioD>>car>>stockD>>car>>dni>>car>>dd>>car>>mm>>car>>aa;
    descuento=(int)(descD*100);
    precio=(int)(precioD*100);
    cantPed=(int)(cantD*100);
    stock=(int)(stockD*100);
    fecha=aa*10000+mm*100+dd;
}

char *leerCadena(ifstream &arch){
    char cadena[100],*ptr;
    arch.getline(cadena,100,',');
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

int buscarProd(int **bufferProd,int cod){
    int *aux;
    for(int i=0;bufferProd[i];i++){
        aux=bufferProd[i];
        if(aux[0]==cod) return i;
    }
    return NO_ENCONTRADO;
}

void agregarInfoProd(int *&infoProd,int codigo,int descuento,int precio,int stock){
    infoProd=new int[4]{};
    infoProd[0]=codigo;
    infoProd[1]=descuento;
    infoProd[2]=precio;
    infoProd[3]=stock;
}

void agregarPed(int *&pedido,int dni,int fecha,int cant,int cod){
    pedido=new int[4]{};
    pedido[0]=dni;
    pedido[1]=fecha;
    pedido[2]=cant;
    pedido[3]=cod;
}

void asignarBuffers(int **&proInfo,char **&proDesc,int **&pedTodo,int nd,
        int numPed,int **bufferInfo,char **bufferDesc,int **bufferPed){
    proInfo=new int*[nd+1]{};
    proDesc=new char*[nd+1]{};
    pedTodo=new int*[numPed+1]{};
    for(int i=0;i<nd;i++){
        proInfo[i]=bufferInfo[i];
        proDesc[i]=bufferDesc[i];
    }
    for(int i=0;i<numPed;i++) pedTodo[i]=bufferPed[i];
}

void PruebaProductosPedidos(int **proInfo,char **proDesc,int **pedTodo,const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<"CODIGO"<<setw(3)<<' '<<"DESCRIPCION"<<setw(32)<<' '<<"DESCUENTO"<<
            setw(13)<<' '<<"PRECIO"<<setw(14)<<' '<<"STOCK"<<endl;
    int *auxInfo,*auxPed;
    for(int i=0;proInfo[i];i++){
        auxInfo=proInfo[i];
        arch<<auxInfo[0]<<setw(3)<<' '<<left<<setw(40)<<proDesc[i]<<right<<
                setw(10)<<auxInfo[1]<<setw(20)<<auxInfo[2]<<setw(20)<<auxInfo[3]<<endl;
    }
    arch<<endl<<"DNI"<<setw(7)<<' '<<"FECHA"<<setw(7)<<' '<<"CANTIDAD"<<
            setw(3)<<' '<<"CODIGO"<<endl;
    for(int i=0;pedTodo[i];i++){
        auxPed=pedTodo[i];
        arch<<auxPed[0]<<setw(10)<<auxPed[1]<<setw(10)<<auxPed[2]<<setw(11)<<auxPed[3]<<endl;
    }
}

void ordenarPedidos(int **pedTodo){
    int numPed=0;
    while(pedTodo[numPed]) numPed++;
    qSort(pedTodo,0,numPed-1);
}

void qSort(int **pedTodo,int ini,int fin){
    int limite=ini,med=(ini+fin)/2;
    if(ini>=fin) return;
    cambiar(pedTodo[ini],pedTodo[med]);
    for(int i=ini+1;i<=fin;i++){
        if(compara(pedTodo[ini],pedTodo[i])) 
            cambiar(pedTodo[++limite],pedTodo[i]);
    }
    cambiar(pedTodo[ini],pedTodo[limite]);
    qSort(pedTodo,ini,limite-1);
    qSort(pedTodo,limite+1,fin);
}

void cambiar(int *&dato1,int *&dato2){
    int *aux=dato1;
    dato1=dato2;
    dato2=aux;
}

bool compara(int *pedido1,int *pedido2){
    if(pedido1[1]>pedido2[1] or (pedido1[1]==pedido2[1] and
            pedido1[0]>pedido2[0])) return true;
    else return false;
}

void asignarPedidos(int ***cli_DniTelPed,int **prodInfo,int **pedTodo){
    int posProd,posCli,*auxPed,**auxCli,*auxProd,numCli;
    for(numCli=0;cli_DniTelPed[numCli];numCli++); /*sacando el numero de clientes*/
    int arrNDPed[numCli]{},arrCapPed[numCli]{};
    for(int i=0;pedTodo[i];i++){
        auxPed=pedTodo[i];
        posCli=buscarCli(cli_DniTelPed,auxPed[0]);
        posProd=buscarProd(prodInfo,auxPed[3]);
        if(posCli!=NO_ENCONTRADO and posProd!=NO_ENCONTRADO){
            auxCli=cli_DniTelPed[posCli];
            auxProd=prodInfo[posProd];
            if(auxProd[3]>=auxPed[2]) agregarPedidosCli(auxCli[2],auxProd[3],
                    auxPed[1],auxPed[2],auxPed[3],arrNDPed[posCli],arrCapPed[posCli]);
        }
    }
}

int buscarCli(int ***dniTelPed,int dni){
    int **aux;
    for(int i=0;dniTelPed[i];i++){
        aux=dniTelPed[i];
        if(dni==*aux[0]) return i;
    }
    return NO_ENCONTRADO;
}

void agregarPedidosCli(int *&lista,int &stock,int fecha,int cant,int codigo,
        int &numPed,int &cap){
    /*como se agrupan de 3 en 3 los datos*/
    if((numPed+1)*3>=cap) aumentarCap(lista,numPed,cap);
    /*lo del código y cantidad debe estar al revés en el enunciado*/
    lista[(numPed-1)*3]=fecha;
    lista[(numPed-1)*3+1]=codigo;
    lista[(numPed-1)*3+2]=cant;
    stock-=cant;
    numPed++;
}

void aumentarCap(int *&lista,int &numPed,int &cap){
    cap+=INCREMENTO;
    int *auxLista=new int[cap]{};
    if(numPed==0) numPed=1;
    else{
        for(int i=0;i<(numPed-1)*3;i++) auxLista[i]=lista[i];
        delete lista;
    }
    lista=auxLista;
}