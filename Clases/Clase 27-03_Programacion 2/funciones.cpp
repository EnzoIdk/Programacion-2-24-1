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

/*se tienen que pasar por referencia obligatoriamente porque los estamos leyendo*/
void cargarAlumnos(int *&codigo,char **&nombre,char ***&cursos,const char *nombArch){
    /*se necesita un buffer por cada dato que se va a recibir*/
    int buffCodigo[50]{},numDatos=0,cod; /*se le coloca un asterisco menos al buffer respectivo*/
    char *buffNombre[50]{},**buffCursos[50]{};
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    numDatos=0;
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get(); /*se saca la coma*/
        buffCodigo[numDatos]=cod;
        buffNombre[numDatos]=leerCadenaNombre(arch);
        buffCursos[numDatos]=leerCursos(arch);
        numDatos++;
    }
    /*todos deben tener el +1*/
    codigo=new int[numDatos+1]{};
    nombre=new char *[numDatos+1]{};
    cursos=new char **[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        codigo[i]=buffCodigo[i];
        nombre[i]=buffNombre[i];
        cursos[i]=buffCursos[i];
    }
}

char *leerCadenaNombre(ifstream &arch){
    char cadena[60],*ptrCadena;
    arch.getline(cadena,60,',');
    if(arch.eof()) return nullptr;
    ptrCadena=new char [strlen(cadena)+1];
    strcpy(ptrCadena,cadena);
    return ptrCadena;
}

char **leerCursos(ifstream &arch){
    char *buffCursos[20]{},**cursos;
    int numCursos=0;
    while(true){
        buffCursos[numCursos]=leerCadena(arch);
        numCursos++;
        if(arch.get()=='\n') break;
    }
    cursos=new char *[numCursos+1]{};
    for(int i=0;i<numCursos;i++){
        cursos[i]=buffCursos[i];
    }
    return cursos;
}

char *leerCadena(ifstream &arch){
    char *ptr;
    ptr=new char [7];
    arch.get(ptr,7);
    return ptr;
}

void reporteAlumnos(int *codigo,char **nombre,char ***cursos,const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for(int i=0;codigo[i];i++){
        archReporte<<left<<setw(10)<<codigo[i]<<nombre[i]<<right<<endl;
        reporteCursos(archReporte,cursos[i]);
    }
}

void reporteCursos(ofstream &archReporte,char **cursos){
    for(int i=0;cursos[i];i++){
        archReporte<<cursos[i]<<setw(10);
    }
    archReporte<<endl;
}