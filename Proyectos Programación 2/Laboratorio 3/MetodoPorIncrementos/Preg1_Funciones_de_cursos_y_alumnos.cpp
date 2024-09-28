/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>      
#include <cstring>
#include <valarray>

using namespace std;

#include "AperturaDeArchivos.h"
#include "FuncionesAuxiliares.h"
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#define INCREMENTO 5
enum regCur{COD,CUR,PRO};

void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,double *escalas,
        const char *nombArchCursos,const char *nombArchEsc){
    ifstream archCursos,archEscalas;
    AperturaDeUnArchivoDeTextosParaLeer(archCursos,nombArchCursos);
    AperturaDeUnArchivoDeTextosParaLeer(archEscalas,nombArchEsc);
    leerEscalas(archEscalas,escalas);
    leerCursos(archCursos,cursos,cursos_cred);
}

void leerEscalas(ifstream &arch,double *escalas){
    int numEscalas=0,num;
    char car;
    while(true){
        arch>>car;
        if(arch.eof()) break;
        arch>>num>>car;
        arch>>escalas[numEscalas];
        numEscalas++;
        arch.get();
    }
}

void leerCursos(ifstream &arch,char ***&cursos,double *&cursos_cred){
    int cap=0,numDat=0;
    double cred;
    char **registro;
    cursos=nullptr;
    cursos_cred=nullptr;
    while(true){
        registro=leerRegistro(arch,cred);
        if(arch.eof()) break;
        if(numDat==cap) aumentarCap(cursos,cursos_cred,numDat,cap);
        cursos[numDat-1]=registro;
//        cursos[numDat]=nullptr;
        cursos_cred[numDat-1]=cred;
//        cursos_cred[numDat]=-1;
        numDat++;
    }
}

void aumentarCap(char ***&cursos,double *&cursos_cred,int &numDat,int &cap){
    char ***auxCur;
    double *auxCred;
    cap+=INCREMENTO;
    if(cursos==nullptr){
        cursos=new char**[cap]{};
        cursos_cred=new double[cap]{};
        numDat=1;
    }
    else{
        auxCur=new char**[cap]{};
        auxCred=new double[cap]{};
        for(int i=0;i<numDat;i++){
            auxCur[i]=cursos[i];
            auxCred[i]=cursos_cred[i];
        }
        delete cursos;
        delete cursos_cred;
        cursos=auxCur;
        cursos_cred=auxCred;
    }
}

/*SND: Sin número de datos*/
void aumentarEspaciosSND(char ***&cursos,double *&cursos_cred,int &numDat,int &cap){
    char ***auxCur;
    double *auxCred;
    cap+=INCREMENTO;
    if(cursos==nullptr){
        cursos=new char**[cap]{};
        cursos_cred=new double[cap]{};
        cursos[0]=nullptr;
        cursos_cred[0]=-1;
        numDat=1;
    }
    else{
        auxCur=new char**[cap]{};
        auxCred=new double[cap]{};
        for(int i=0;i<numDat;i++){
            auxCur[i]=cursos[i];
            auxCred[i]=cursos_cred[i];
        }
        delete cursos;
        delete cursos_cred;
        cursos=auxCur;
        cursos_cred=auxCred;
    }
}

char **leerRegistro(ifstream &arch,double &cred){
    char **registro,*codCur,*nombCur,*nombProfe;
    int codProfe;
    codCur=leerCadena(arch,',');
    if(arch.eof()) return nullptr;
    nombCur=leerCadena(arch,',');
    arch>>cred;
    arch.get();
    arch>>codProfe;
    arch.get();
    nombProfe=leerCadena(arch,'\n');
    registro=new char*[3]{};
    registro[COD]=codCur;
    registro[CUR]=nombCur;
    registro[PRO]=nombProfe;
    return registro;
}

char *leerCadena(ifstream &arch,char delim){
    char cadena[100],*ptr;
    arch.getline(cadena,100,delim);
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void pruebaDeCargaDeCursos(char ***cursos,double *cursos_cred,const char *nombArch){
    ofstream arch;
    char **auxCursos;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    for(int i=0;cursos[i];i++){
        auxCursos=cursos[i];
        arch<<setw(10)<<auxCursos[0]<<setw(65)<<auxCursos[1]<<setw(40)<<
                auxCursos[2]<<setw(10)<<cursos_cred[i]<<endl;
    }
}

void cargarAlumnos(int *&alumnos_cod,int **&alumnos,char ***&alumnos_nom_mod,const char *nombArch){
    
}

void pruebaDeCargaDeAlumnos(int *alumnos_cod,int **alumnos,char ***alumnos_nom_mod,const char *nombArch){
    
}