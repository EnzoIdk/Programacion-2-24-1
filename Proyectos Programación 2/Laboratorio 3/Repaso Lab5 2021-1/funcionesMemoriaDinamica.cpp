/* 
 * File:   funcionesMemoriaDinamica.cpp
 * Author: Lucas
 *
 * Created on 18 de abril de 2024, 17:30
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include <ratio>
#include <algorithm>

#include "funcionesMemoriaDinamica.h"

#define NOTFOUND -1
#define MAXLINEA 120
#define INCREMENTO 5

enum Categoria{LEVE, GRAVE, MUY_GRAVE};

void cargarConductores(const char* nombArch, int * &licencia, 
        char ** &conductor){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    //53853385,SOLIS NARVAEZ MARIA MADELEINE
    int nd=0, cap=0, dni;
    char * nombre;
    while(true){
        leerConductor(arch, dni, nombre);
        if(arch.eof()) break;
        if(nd==cap) incrementarEspacios(licencia, conductor, nd, cap);
        licencia[nd-1]=dni;
        conductor[nd-1]=nombre;
        nd++;
    }
}

void leerConductor(ifstream &arch, int &dni, char * &nombre){
    arch>>dni;
    if(arch.eof()) return;
    arch.get(); //,
    nombre=leerCadena(arch, '\n');
}

char * leerCadena(ifstream &arch, char delim){
    char aux[100]{}, * cad;
    arch.getline(aux, 100, delim);
    if(arch.eof()) return nullptr;
    cad=new char[strlen(aux)+1]{};
    strcpy(cad, aux);
    return cad;
}

void incrementarEspacios(int * &licencia, char ** &conductor, int &nd, 
        int &cap){
    int * auxLic;
    char ** auxCond;
    cap+=INCREMENTO;
    if(nd==0){
        licencia=new int[cap]{};
        conductor=new char*[cap]{};
        nd=1; //ESPACIO PARA EL 0
    }
    else{
        auxLic=new int[cap]{};
        auxCond=new char*[cap]{};
        for(int i=0; i<nd; i++){
            auxCond[i]=conductor[i];
            auxLic[i]=licencia[i];
        }
        delete conductor;
        delete licencia;
        licencia=auxLic;
        conductor=auxCond;
    }
}

void reporteConductores(const char* nombArch, int * licencia, 
        char ** conductor){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    arch<<"DNI"<<setw(20)<<"NOMBRE"<<endl;
    for(int i=0; licencia[i]; i++){
        arch<<licencia[i]<<" - "<<conductor[i]<<endl;
    }
}

void cargarFaltas(const char* nombArch, int * licencia, char *** &placa, 
        int ** &falta){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    int dni, infraccion, numCond=0, pos, numFaltasPorCond[200]{}, 
            capFaltasPorCond[200]{};
    char * cod;
    //INICIALIZACION
    for(numCond=0; licencia[numCond]; numCond++);
    placa=new char**[numCond+1]{};
    falta=new int*[numCond+1]{};
    //15029228,J0Q-121,22/04/2020,328
    while(true){
        leerFalta(arch, dni, cod, infraccion);
        if(arch.eof()) break;
        pos=buscarConductor(dni, licencia);
        if(pos!=NOTFOUND){
            if(capFaltasPorCond[pos]==numFaltasPorCond[pos])
                incrementarEspacios(placa[pos], falta[pos], 
                        capFaltasPorCond[pos], numFaltasPorCond[pos]);
            agregarFalta(cod, infraccion, placa[pos], falta[pos], 
                    numFaltasPorCond[pos]);
        }
    }
}

void leerFalta(ifstream &arch, int &dni, char * &cod, int &infraccion){
    arch>>dni;
    if(arch.eof()) return;
    arch.get(); //,
    cod=leerCadena(arch, ',');
    while(arch.get()!=','); //NO NOS IMPORTA LA FECHA
    arch>>infraccion;
}

int buscarConductor(int dni, int * licencia){
    for(int i=0; licencia[i]; i++){
        if(dni==licencia[i]) return i;
    }
    return NOTFOUND;
}

void incrementarEspacios(char ** &placa, int * &falta, int &capFaltasPorCond, 
        int &numFaltasPorCond){
    char ** auxPlaca;
    int * auxFalta;
    capFaltasPorCond+=INCREMENTO;
    if(numFaltasPorCond==0){
        placa=new char*[capFaltasPorCond]{};
        falta=new int[capFaltasPorCond]{};
        numFaltasPorCond=1;
    }
    else{
        auxPlaca=new char*[capFaltasPorCond]{};
        auxFalta=new int[capFaltasPorCond]{};
        for(int i=0; i<numFaltasPorCond; i++){
            auxFalta[i]=falta[i];
            auxPlaca[i]=placa[i];
        }
        delete falta;
        delete placa;
        falta=auxFalta;
        placa=auxPlaca;
    }
}

void agregarFalta(char * cod, int infraccion, char ** placa, int * falta, 
        int &numFaltasPorCond){
    placa[numFaltasPorCond-1]=cod;
    falta[numFaltasPorCond-1]=infraccion;
    numFaltasPorCond++;
}

void reporteFaltas(const char* nombArch, int * licencia, char ** conductor, 
        char *** placa, int ** falta){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    for(int i=0; licencia[i]; i++){
        arch<<"DNI:"<<setw(10)<<licencia[i]<<" - "<<conductor[i]<<endl;
        arch<<"LISTA DE FALTAS: "<<endl;
        if(falta[i]){
            imprimirFaltas(arch, placa[i], falta[i]);
        }
        else arch<<"NO TIENE FALTAS"<<endl;
        imprimirLinea(arch, MAXLINEA, '=');
    }
}

void imprimirFaltas(ofstream &arch, char ** placa, int * falta){
    arch<<"PLACA"<<setw(18)<<"INFRACCION"<<endl;
    for(int i=0; falta[i]; i++){
        arch<<placa[i]<<setw(10)<<falta[i]<<endl;
    }
}

void imprimirLinea(ofstream &arch, int largo, char car){
    for(int i=0; i<largo; i++) arch<<car;
    arch<<endl;
}

void resumenMultas(const char* nombArch, int * licencia, int ** falta, 
        double ** &multa){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    int numConductores=0, infraccion, categoria, * regInf, * regCat, nd=0, 
            cap=0;
    double * regCosto, costo;
    //INICIALIZACION
    for(numConductores=0; licencia[numConductores]; numConductores++);
    multa=new double*[numConductores+1]{};
    //LECTURA
    while(true){
        leerMulta(arch, infraccion, categoria, costo);
        if(arch.eof()) break;
        if(nd==cap) incrementarEspacios(regInf, regCat, regCosto, nd, cap);
        regInf[nd-1]=infraccion;
        regCat[nd-1]=categoria;
        regCosto[nd-1]=costo;
        nd++;
    }
    //ACTUALIZACION
    agregarMultas(regCat, regCosto, regInf, licencia, falta, multa);
}

void leerMulta(ifstream &arch, int &infraccion, int &categoria, double &costo){
    char * categ;
    //103,Detener el vehículo bruscamente sin motivo.,Grave,316.00
    arch>>infraccion;
    if(arch.eof()) return;
    arch.get();//,
    while(arch.get()!=','); //NO USAMOS LA DESCRIPCION
    categ=leerCadena(arch, ',');
    arch>>costo;
    //CASO
    switch(categ[0]){
        case 'L':
            categoria=LEVE;
            break;
        case 'G':
            categoria=GRAVE;
            break;
        default:
            categoria=MUY_GRAVE;
            break;
    }
    delete categ;
}

void incrementarEspacios(int * &regInf, int * &regCat, double * &regCosto, 
        int &nd, int &cap){
    int * auxInf, * auxCat;
    double * auxCosto;
    cap+=INCREMENTO;
    if(nd==0){
        regCat=new int[cap]{};
        regInf=new int[cap]{};
        regCosto=new double[cap]{};
        nd=1;
    }
    else{
        auxCat=new int[cap]{};
        auxInf=new int[cap]{};
        auxCosto=new double[cap]{};
        for(int i=0; i<nd; i++){
            auxCat[i]=regCat[i];
            auxCosto[i]=regCosto[i];
            auxInf[i]=regInf[i];
        }
        delete regCat;
        delete regCosto;
        delete regInf;
        regCat=auxCat;
        regCosto=auxCosto;
        regInf=auxInf;
    }
}

void agregarMultas(int * regCat, double * regCosto, int * regInf, 
        int * licencia, int ** falta, double ** multa){
    for(int i=0; licencia[i]; i++){
        if(falta[i]){
            multa[i]=new double[3]{};
            actualizarMultas(regCat, regCosto, regInf, falta[i], multa[i]);
        }
    }
}

void actualizarMultas(int * regCat, double * regCosto, int * regInf, 
        int * falta, double * multa){
    int pos;
    for(int i=0; falta[i]; i++){
        pos=buscarFalta(falta[i], regInf);
        if(pos!=NOTFOUND) multa[regCat[pos]]+=regCosto[pos];
    }
}

int buscarFalta(int falta, int * regInf){
    for(int i=0; regInf[i]; i++){
        if(falta==regInf[i]) return i;
    }
    return NOTFOUND;
}

void reporteMultas(const char* nombArch, int * licencia, char ** conductor, 
        double ** multa){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    double * auxMul;
    arch<<fixed<<setprecision(2);
    for(int i=0; licencia[i]; i++){
        arch<<"DNI:"<<setw(10)<<licencia[i]<<" - "<<conductor[i]<<endl;
        arch<<"MONTOS A PAGAR: "<<endl;
        imprimirLinea(arch, MAXLINEA/2, '-');
        if(multa[i]){
            auxMul=multa[i];
            arch<<left<<setw(15)<<"LEVES:"<<right<<setw(10)<<auxMul[LEVE]<<endl;
            arch<<left<<setw(15)<<"GRAVES:"<<right<<setw(10)<<auxMul[GRAVE]<<
                    endl;
            arch<<left<<setw(15)<<"MUY GRAVES:"<<right<<setw(10)<<
                    auxMul[MUY_GRAVE]<<endl;
        }
        else arch<<"NO TIENE FALTAS"<<endl;
        imprimirLinea(arch, MAXLINEA/2, '=');
    }
}