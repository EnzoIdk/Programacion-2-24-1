/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>        

#include "Pregunta01Examen01PunterosMultiples.h"
#include "Pregunta02Examen01PunterosGenericos.h"

#include "ColaConProductos.h"
#include "ColaGenerica.h"

using namespace std;

#define NO_ENCONTRADO -1
enum Cola{INI,FIN,CANT};
enum Nodo{DATO,SGTE};

void procesarPedidos(int **fechaCliCant,char **codProd,void *&prod){
    void **productos=(void**)prod;
    void **auxProd,**datos;
    int *aux,*stock;
    int posProd;
    for(int i=0;fechaCliCant[i];i++){
        posProd=buscarProd(codProd[i],prod);
        if(posProd!=NO_ENCONTRADO){
            aux=fechaCliCant[i];
            auxProd=(void**)productos[posProd];
            datos=(void**)auxProd[0];
            stock=(int*)datos[3];
            if(*stock>=aux[2]){
                *stock-=aux[2];
                crearColaPedido(auxProd[1],fechaCliCant[i]);
            }
        }
    }
}

void crearColaPedido(void *&cola,int *pedido){
    if(cola==nullptr) generacola(cola);
    encola(cola,pedido);
    void **regCola=(void**)cola;
    int *cantPed=(int*)regCola[CANT];
    *cantPed+=pedido[2];
}

int buscarProd(char *cod,void *prod){
    void **productos=(void**)prod;
    void **auxProd,**datos;
    char *codigo;
    for(int i=0;productos[i];i++){
        auxProd=(void**)productos[i];
        datos=(void**)auxProd[0];
        codigo=(char*)datos[0];
        if(strcmp(cod,codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

void reporteDePedidos(void *prod,const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **productos=(void**)prod;
    void **auxProd;
    for(int i=0;productos[i];i++){
        auxProd=(void**)productos[i];
        imprimirDatosProductos(arch,auxProd[0],i+1);
        if(auxProd[1]!=nullptr){
            arch<<"Pedidos aceptados: "<<endl;
            arch<<"Fechas"<<setw(6)<<' '<<"DNI"<<setw(10)<<' '<<"Cantidad"<<endl;
            imprimirColaPedidos(arch,auxProd[1]);
            arch<<endl;
        }
    }
}

void imprimirColaPedidos(ofstream &arch,void *cola){
    void **auxCola=(void**)cola;
    void **ini=(void**)auxCola[INI];
    while(!colavacia(ini)){
        imprimirPedido(arch,desencola(cola));
        auxCola=(void**)cola;
        ini=(void**)auxCola[INI];
    }
}

void imprimirPedido(ofstream &arch,void *ped){
    int *pedido=(int*)ped;
    imprimirFecha(arch,pedido[0]);
    arch<<setw(2)<<' '<<pedido[1]<<setw(10)<<pedido[2]<<endl;
}
