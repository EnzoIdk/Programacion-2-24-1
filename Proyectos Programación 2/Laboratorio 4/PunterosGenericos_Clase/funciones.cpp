/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream> 
#include <cstring>
#include <cmath>

using namespace std;

#include "funciones.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1
enum Reg{COD,NOM,NOT,PRO};
    
void cargarAlumnos(void *&al,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **alumnos,*reg;
    int nd=0,cap=0;
    alumnos=nullptr;
    while(true){
        reg=leerRegistro(arch);
        if(arch.eof()) break;
        if(nd==cap) aumentarCap(alumnos,nd,cap);
        alumnos[nd-1]=reg;
        nd++;
    }
    al=alumnos;
}

/*leemos y guardamos todo sin importar el tipo de dato omg*/
void *leerRegistro(ifstream &arch){
    void **registro=new void*[4]{};
    int *codigo=new int,cod;
    char *nombre;
    arch>>cod;
    if(arch.eof()) return nullptr;
    *codigo=cod;
    arch.get();
    nombre=leerCadena(arch,'\n');
    registro[COD]=codigo;
    registro[NOM]=nombre;
    return registro;
}

char *leerCadena(ifstream &arch,char delim){
    char cadena[60],*ptr;
    arch.getline(cadena,60,delim);
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void aumentarCap(void **&alumnos,int &nd,int &cap){
    cap+=INCREMENTO;
    void **aux=new void*[cap]{};
    if(nd==0) nd=1;
    else{
        for(int i=0;i<nd;i++) aux[i]=alumnos[i];
        delete alumnos;
    }
    alumnos=aux;
}

/*ya no es necesario pasarlo por referencia, ya se asignó el espacio*/
void cargarNotas(void *al,const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **alumnos=(void**)al;
    int nd[50]{},cap[50]{},cod,pos;
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        pos=buscarPos(cod,alumnos);
        if(pos!=NO_ENCONTRADO){
            colocarCurso(arch,alumnos[pos],nd[pos],cap[pos]);
        }
        else while(arch.get()!='\n');
    }
}

int buscarPos(int cod,void **alumnos){
    for(int i=0;alumnos[i];i++){
        if(sonIguales(cod,alumnos[i])) return i;
    }
    return NO_ENCONTRADO;
}

bool sonIguales(int cod,void *al){
    /*casteo*/
    void **alumno=(void**)al;
    int *codigo=(int*)alumno[COD]; 
    return cod==*codigo;
}

void colocarCurso(ifstream &arch,void *al,int &nd,int &cap){
    void **alumno=(void**)al;
    void *cur;
    cur=leerCurso(arch);
    if(nd==cap) aumentarCap(alumno[NOT],nd,cap);
    agregarCurso(cur,alumno[NOT],nd);
    nd++;
}

void aumentarCap(void *&al,int &nd,int &cap){
    cap+=INCREMENTO;
    void **alumnos=(void**)al,**aux=new void*[cap]{};
    if(nd==0) nd=1;
    else{
        for(int i=0;i<nd;i++) aux[i]=alumnos[i];
        delete alumnos;
    }
    alumnos=aux;
    al=alumnos;
}

void *leerCurso(ifstream &arch){
    void **registro=new void*[2]{};
    char *codigo;
    int *nota=new int;
    codigo=leerCadena(arch,',');
    arch>>*nota;
    registro[0]=codigo;
    registro[1]=nota;
    return registro;
}

void agregarCurso(void *cur,void *alNota,int nd){
    void **alumnoNota=(void**)alNota;
    alumnoNota[nd-1]=cur;
}

void calcularPromedios(void *al){
    void **alumnos=(void**)al;
    for(int i=0;alumnos[i];i++) promedioDelAlumno(alumnos[i]);
}

void promedioDelAlumno(void *al){
    void **alumno=(void**)al;
    if(alumno[NOT]) alumno[PRO]=promedio(alumno[NOT]);
}

/*se calcula el promedio de un alumno*/
void *promedio(void *al){
    void **cursos=(void**)al;
    int suma=0,numDat=0;
    double *prom=new double;
    for(int i=0;cursos[i];i++){
        suma+=obtenerNota(cursos[i]);
        numDat++;
    }
    *prom=(double)suma/numDat;
    return prom;
}

int obtenerNota(void *cur){
    void **curso=(void**)cur;
    int *nota=(int*)curso[1];
    return *nota;
}

void probarCarga(void *al){
    void **alumnos=(void**)al;
    for(int i=0;alumnos[i];i++){
        imprimirAlumno(alumnos[i]);
    }
}

void imprimirAlumno(void *al){
    void **alumno=(void**)al;
    int *codigo;
    char *nombre;
    /*para acceder*/
    codigo=(int*)alumno[COD];
    nombre=(char*)alumno[NOM];
    /*si se imprime como *nombre, solo aparece la primera letra*/
    cout<<left<<setw(10)<<*codigo<<setw(50)<<nombre<<endl;
    if(alumno[NOT]) imprimirCursos(alumno[NOT]);
    imprimirPromedio(alumno[PRO]);
}

void imprimirCursos(void *cur){
    void **cursos=(void**)cur;
    for(int i=0;cursos[i];i++){
        imprimirCurso(cursos[i]);
    }
}

void imprimirCurso(void *cur){
    void **curso=(void**)cur;
    char *codigo=(char*)(curso[0]);
    int *nota=(int*)(curso[1]);
    cout<<right<<setw(10)<<codigo<<setw(3)<<' '<<setfill('0')<<setw(2)<<*nota<<
            setfill(' ')<<endl;
}

void imprimirPromedio(void *pro){
    double *promedio=(double*)pro;
    cout<<setprecision(2)<<fixed;
    cout<<"Promedio = "<<setw(5)<<*promedio<<endl<<endl;
}

void ordenar(void *al){
    void **alumnos=(void**)al;
    int numDat=0;
    for(;alumnos[numDat];numDat++) ordenarCursos(alumnos[numDat]);
    qsort(alumnos,0,numDat-1);
}

void qsort(void **alumnos,int izq,int der){
    int limite=izq,pos=(der+izq)/2;
    if(izq>=der) return;
    cambiar(alumnos[izq],alumnos[pos]);
    for(int i=izq+1;i<=der;i++)
        if(estanEnDesorden(alumnos[i],alumnos[izq]))
            cambiar(alumnos[++limite],alumnos[i]);
    cambiar(alumnos[izq],alumnos[limite]);
    qsort(alumnos,izq,limite-1);
    qsort(alumnos,limite+1,der);
}

void cambiar(void *&al1,void *&al2){
    void *aux=al1;
    al1=al2;
    al2=aux;
}

bool estanEnDesorden(void *alI,void *alIzq){
    void **alumnoI=(void**)alI,**alumnoIzq=(void**)alIzq;
    char *nombreI=(char*)alumnoI[NOM],*nombreIzq=(char*)alumnoIzq[NOM];
    return strcmp(nombreI,nombreIzq)<0; /*si nombreI es menor, devuelve true*/
}

void ordenarCursos(void *alu){
    void **alumno=(void**)alu;
    void **notas=(void**)alumno[NOT];
    int nd=0;
    for(;notas[nd];nd++); /*obtenemos el numero de datos (nd)*/
    qsort2(notas,0,nd-1);
}

void qsort2(void **notas,int izq,int der){
    int limite=izq,pos=(der+izq)/2;
    if(izq>=der) return;
    cambiar(notas[izq],notas[pos]);
    for(int i=izq+1;i<=der;i++)
        if(estanEnDesorden2(notas[i],notas[izq]))
            cambiar(notas[++limite],notas[i]);
    cambiar(notas[izq],notas[limite]);
    qsort2(notas,izq,limite-1);
    qsort2(notas,limite+1,der);
}

bool estanEnDesorden2(void *notI,void *notIzq){
    void **notaI=(void**)notI,**notaIzq=(void**)notIzq;
    char *nombreI=(char*)notaI[0],*nombreIzq=(char*)notaIzq[0];
    return strcmp(nombreI,nombreIzq)<0; 
}

void eliminarDatos(void *al){
    void **alumnos=(void**)al;
    for(int i=0;alumnos[i];i++){
        eliminarAlumno(alumnos[i]);
    }
    delete alumnos;
}

void eliminarAlumno(void *al){
    void **alumno=(void**)al;
    int *codigo=(int*)alumno[COD];
    char *nombre=(char*)alumno[NOM];
    double *promedio=(double*)alumno[PRO];
    delete codigo;
    delete nombre;
    if(promedio!=nullptr){
        delete promedio;
        eliminarCursos(alumno[NOT]);
    }
    delete alumno;
}

void eliminarCursos(void *cur){
    void **curso=(void**)cur;
    for(int i=0;curso[i];i++)
        eliminarCodNota(curso[i]);
}

void eliminarCodNota(void *cur){
    void **curso=(void**)cur;
    char *codigo=(char*)curso[0];
    int *nota=(int*)curso[1];
    delete codigo;
    delete nota;
    delete curso;
}