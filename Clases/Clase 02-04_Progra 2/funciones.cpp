/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#include "funciones.h"
#define NO_ENCONTRADO -1

void cargarAlumnos(int *&codigo,char **&nombre,const char *nombArch){
    int buffCod[50]{},cod,numDatos=0;
    char *buffNomb[50]{};
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        buffCod[numDatos]=cod;
        buffNomb[numDatos]=leeCadena(arch);
        numDatos++;
    }
    codigo=new int[numDatos+1]{};
    nombre=new char*[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        codigo[i]=buffCod[i];
        nombre[i]=buffNomb[i];
    }
}


char *leeCadena(ifstream &arch){
    char buffer[50],*ptr;
    arch.getline(buffer,50);
//    if(arch.eof()) return nullptr;
    ptr= new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}

/*los codigos ya fueron leidos, entonces no se pasan por referencia*/
void cargarCursos(int *codigo,char ***&cursos,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numDat=0,nd[50]{},cod,pos; //inicializando
    char aux[60];
    /*nd es el arreglo auxiliar que te indica cuantos alumnos tiene por curso*/
    
    //Inicializar cursos
    while(codigo[numDat]) numDat++;
    cursos=new char**[numDat+1]{}; /*siempre inicializar en 0 por precaucion*/
    for(int i=0;i<numDat;i++) cursos[i]=new char*[50]{}; /*es como declarar un estático*/
    
    //Colocamos los cursos
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get(); /*quita la coma*/
        pos=buscarAlumno(cod,codigo);
        if(pos!=NO_ENCONTRADO){
            colocarCurso(arch,cursos[pos],nd[pos]);
        }
        else arch.getline(aux,60);
    }
    
    //pasamos los cursos a arreglos exactos
    for(int i=0;cursos[i];i++) espaciosExactos(cursos[i],nd[i]);
    /*funciona porque el último es cero*/
}

int buscarAlumno(int cod,int *codigo){
    for(int i=0;codigo[i];i++){
        if(cod==codigo[i]) return i;
    }
    return NO_ENCONTRADO;
}

/*imagina que se trabaja en un arreglo normal de cadenas*/
void colocarCurso(ifstream &arch,char **cursos,int &nd){
    char *cod;
    cod=leeCadena(arch);
    cursos[nd]=cod;
    nd++;
}

void espaciosExactos(char **&cursos,int nd){
    char **cursosAux;
    if(nd!=0){
        cursosAux=new char*[nd+1]{};
        for(int i=0;i<nd;i++) cursosAux[i]=cursos[i];
        delete cursos;
        cursos=cursosAux;
    }
    else{
        delete cursos;
        cursos=nullptr;
    }
}

void reporte(int *codigo,char **nombre,char ***cursos){
    for(int i=0;codigo[i];i++){
        cout<<left<<setw(10)<<codigo[i]<<nombre[i]<<endl;
        if(cursos[i]) reporteCursos(cursos[i]); /**colocarlo para no tener problemas
                                                 cuando no haya cursos y apunte al nullptr*/
        else cout<<"NO TIENE CURSOS"<<endl;
    }
}

void reporteCursos(char **cursos){
    for(int i=0;cursos[i];i++){
        cout<<cursos[i]<<setw(3)<<' ';
    }
    cout<<endl;
}