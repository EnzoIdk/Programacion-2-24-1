/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstdlib>
#include <cstring>

using namespace std;

#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistros.h"
enum Nodo{DATO,SGTE};
enum Lista{CABEZA,COLA};
#define TAM_LINEA 120

void *leeregistro(ifstream &arch){
    void **registro=new void*[3];
    int *fecha=new int;
    int *licencia=new int,*infraccion=new int,dd,mm,aa;
    char cadena[8],car;
    arch>>*licencia;
    if(arch.eof()) return nullptr;
    arch.get();
    arch.getline(cadena,8,',');
    arch>>dd>>car>>mm>>car>>aa>>car>>*infraccion;
    *fecha=aa*10000+mm*100+dd;
    registro[0]=licencia;
    registro[1]=infraccion;
    registro[2]=fecha;
    return registro;
}

int cmpregistro(const void *reg1,const void *reg2){
    void **registro1=(void**)reg1,**registro2=(void**)reg2;
    int *fecha1=(int*)registro1[2],*fecha2=(int*)registro2[2];
    return *fecha1-*fecha2;
}

void imprimeregistro(ofstream &arch,void *reg,void *&cabeceraFecha){
    void **registro=(void**)reg;
    int *licencia=(int*)registro[0],*infraccion=(int*)registro[1],
            *fecha=(int*)registro[2],*fechaAnt,dd,mm,aa;
    if(cabeceraFecha==nullptr){
        fechaAnt=new int{0};
        cabeceraFecha=fechaAnt;
    }
    else{
        fechaAnt=(int*)cabeceraFecha;
        (*fechaAnt)/=100;
    }
    descomponerFecha(*fecha,dd,mm,aa);
    if(*fechaAnt!=(*fecha)/100){
        if(*fechaAnt!=0) imprimirLinea(arch,TAM_LINEA,'=');
        arch<<"Año: "<<aa<<" Mes: "<<setfill('0')<<setw(2)<<mm<<
                setfill(' ')<<endl<<endl;
        arch<<"FECHA"<<setw(20)<<"LICENCIA"<<setw(5)<<' '<<"NOMBRE"<<setw(60)
                <<' '<<"FALTA"<<endl;
        imprimirLinea(arch,TAM_LINEA,'=');
    }
    cabeceraFecha=fecha; /*para que tome el valor anterior en las siguientes iteraciones*/
    arch<<setfill('0')<<setw(4)<<aa<<"/"<<setw(2)<<mm<<"/"<<setw(2)<<dd<<setfill(' ')<<
            setw(15)<<*licencia<<setw(5)<<" ";
    buscarImprimirNombre(arch,*licencia);
    arch<<setw(5)<<" "<<setw(15)<<*infraccion<<endl;
}

void buscarImprimirNombre(ofstream &arch,int licencia){
    ifstream archConductores("Conductores.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores"<<endl;
        exit(1);
    }
    int comparar;
    char *cadena;
    while(true){
        archConductores>>comparar;
        if(arch.eof()) break;
        if(comparar!=licencia){
            while(archConductores.get()!='\n');
        }  
        else{
            archConductores.get();
            cadena=leerCadena(archConductores);
            arch<<left<<setw(50)<<cadena<<right;
            return;
        }
    }
}

char *leerCadena(ifstream &arch){
    char cadena[60],*ptr;
    arch.getline(cadena,60);
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void descomponerFecha(int fecha,int &dd,int &mm,int &aa){
    aa=fecha/10000;
    mm=(fecha/100)%100;
    dd=fecha%100;
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}