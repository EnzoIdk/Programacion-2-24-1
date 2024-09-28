/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstring>

using namespace std;

#include "AperturaDeArchivos.h"
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#define INCREMENTO 5

void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,double *escalas,
        const char *nombCur,const char *nombEsc){
    ifstream archCur,archEsc;
    AperturaDeUnArchivoDeTextosParaLeer(archCur,nombCur);
    AperturaDeUnArchivoDeTextosParaLeer(archEsc,nombEsc);
    cargarEscalas(archEsc,escalas);
    int cap=0,num=0;
    double cred;
    char **datosCur;
    while(true){
        leerDatos(archCur,datosCur,cred);
        if(archCur.eof()) break;
        if(num==cap) aumentarCap(cursos,cursos_cred,num,cap);
        cursos[num-1]=datosCur;
        cursos_cred[num-1]=cred;
        num++;
    }
}

void cargarEscalas(ifstream &arch,double *escalas){
    char car;
    int num;
    for(int i=0;i<5;i++){
        arch>>car>>num>>car;
        arch>>escalas[num-1];
    }
}

void leerDatos(ifstream &arch,char **&datosCur,double &cred){
    int dato;
    char car;
    datosCur=new char*[3]{};
    datosCur[0]=leerCadena(arch,',');
    if(arch.eof()) return;
    datosCur[1]=leerCadena(arch,',');
    arch>>cred>>car>>dato>>car;
    datosCur[2]=leerCadena(arch,'\n');
}

char *leerCadena(ifstream &arch,char delim){
    char cadena[60],*ptr;
    arch.getline(cadena,60,delim);
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void aumentarCap(char ***&cursos,double *&cursos_cred,int &num,int &cap){
    cap+=INCREMENTO;
    char ***auxCursos=new char**[cap]{};
    double *auxCred=new double[cap]{};
    if(num==0) num=1;
    else{
        for(int i=0;i<num;i++){
            auxCursos[i]=cursos[i];
            auxCred[i]=cursos_cred[i];
        }
        delete cursos;
        delete cursos_cred;
    }
    cursos=auxCursos;
    cursos_cred=auxCred;
}

void pruebaDeCargaDeCursos(char ***cursos,double *cursos_cred,const char *nombArch){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    char **auxCur;
    arch<<setprecision(2)<<fixed;
    for(int i=0;cursos[i];i++){
        auxCur=cursos[i];
        arch<<auxCur[0]<<setw(3)<<' '<<left<<setw(55)<<auxCur[1]<<left<<
                setw(40)<<auxCur[2]<<right<<setw(10)<<cursos_cred[i]<<endl;
    }
}

void cargarAlumnos(int *&alumnos_cod,int **&alumnos,char ***&alumnos_nom_mod,const char *nombArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    int cod,escala,porc,num=0,cap=0;
    char *nombre,mod;
    while(true){
        leerDatosAlu(arch,cod,escala,porc,nombre,mod);
        if(arch.eof()) break;
        if(num==cap) aumentarCapAlu(alumnos_cod,alumnos,alumnos_nom_mod,num,cap);
        alumnos_cod[num-1]=cod;
        alumnos[num-1]=insertarDatAlu(cod,escala,porc);
        alumnos_nom_mod[num-1]=insertarNomMod(nombre,mod);
        num++;
    }
}

void leerDatosAlu(ifstream &arch,int &cod,int &escala,int &porc,char *&nombre,char &mod){
    char car;
    porc=0;
    arch>>cod;
    if(arch.eof()) return;
    arch.get();
    nombre=leerCadena(arch,',');
    mod=arch.get();
    if(mod=='G'){
        mod='P';
        arch>>escala;
    }
    else if(mod=='V') arch>>car>>car>>escala;
    else arch>>car>>porc>>car>>car>>escala;
}

void aumentarCapAlu(int *&arr1,int **&arr2,char ***&arr3,int &num,int &cap){
    cap+=INCREMENTO;
    int *arrAux1=new int[cap]{},**arrAux2=new int*[cap]{};
    char ***arrAux3=new char**[cap]{};
    if(num==0) num=1;
    else{
        for(int i=0;i<num;i++){
            arrAux1[i]=arr1[i];
            arrAux2[i]=arr2[i];
            arrAux3[i]=arr3[i];
        }
        delete arr1;
        delete arr2;
        delete arr3;
    }
    arr1=arrAux1;
    arr2=arrAux2;
    arr3=arrAux3;
}

int *insertarDatAlu(int cod,int esc,int porc){
    int *registro;
    /*si porcentaje es 0, es porque no es semipresencial*/
    if(porc==0){
        registro=new int[2]{};
        registro[0]=cod;
        registro[1]=esc;
    } 
    else{
        registro=new int[3]{};
        registro[0]=cod;
        registro[1]=esc;
        registro[2]=porc;
    }
    return registro;
}

char **insertarNomMod(char *nombre,char mod){
    char **registro=new char*[2]{};
    char *modalidad=new char{mod};
    registro[0]=nombre;
    registro[1]=modalidad;
    return registro;
}

void pruebaDeCargaDeAlumnos(int *alumnos_cod,int **alumnos,char ***alumnos_nom_mod,const char *nombArch){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    int *auxAlu;
    char **auxNomMod;
    for(int i=0;alumnos_cod[i];i++){
        auxAlu=alumnos[i];
        auxNomMod=alumnos_nom_mod[i];
        arch<<auxAlu[0]<<' '<<auxAlu[1];
        if(*auxNomMod[1]=='S') arch<<setw(4)<<auxAlu[2]<<' ';
        else arch<<setw(5)<<' ';
        arch<<left<<setw(50)<<auxNomMod[0]<<right<<setw(3)<<*auxNomMod[1]<<endl;
    }
}