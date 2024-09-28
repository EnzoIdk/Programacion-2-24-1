#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "FuncionesAux.h"
void lecturaAlumnos(const char*nomb,int *&alumno_Codigo,char **&alumno_Nombre,
        char *&alumno_Modalidad,int *&alumno_Porcentaje,int *&alumno_Escala){
    ifstream Arch(nomb,ios::in);
    if(not Arch.is_open()){
        cout<<"Error no se pudo abrir el archivo  "<<nomb<<endl;
        exit(1);
    }
    //aux y buffers
    int cod,escala,numdat=0,bufferCodigo[100]{},porcent,bufferPorcent[100]{}
            ,bufferEscala[100]{};
    char *bufferNombre[100]{},bufferModalidad[100]{},modalidad;
    
    while(true){
        Arch>>cod;
        if(Arch.eof())break;
        Arch.get();
        bufferNombre[numdat]=leerCadena(Arch);
        Arch>>modalidad;
        EvalModalidad(modalidad,escala,porcent,Arch);
        bufferEscala[numdat]=escala;
        bufferCodigo[numdat]=cod;
        bufferModalidad[numdat]=modalidad;
        bufferPorcent[numdat]=porcent;
//        cout<<bufferEscala[numdat]<<endl;
        numdat++;
    }
    LlenarExacto(alumno_Codigo,alumno_Nombre,alumno_Modalidad,alumno_Porcentaje
        ,alumno_Escala,bufferCodigo,bufferEscala,bufferModalidad,bufferNombre
        ,bufferPorcent,numdat);
}
char * leerCadena(ifstream &Arch){
    char *ptr,cadena[100];
    Arch.getline(cadena,100,',');
    ptr=new char[strlen(cadena)+1]{};
    strcpy(ptr,cadena);
    return ptr;
}
void EvalModalidad(char &modalidad,int &escala,int &porcent,ifstream &Arch){
    char w;
    if(modalidad=='S'){
        Arch>>w>>porcent>>w>>escala;
    }
    else if(modalidad=='V'){
        Arch>>w>>escala;
        porcent=0;
    }
    else{
        escala=modalidad-'0';
        porcent=0;
        modalidad='P';
    }
}
void LlenarExacto(int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
        int *&alumno_Porcentaje,int *&alumno_Escala,int *bufferCodigo,int *bufferEscala
        ,char *bufferModalidad,char **bufferNombre,int *bufferPorcent,int numdat){
    alumno_Codigo=new int[numdat+1]{};
    alumno_Escala=new int[numdat+1]{};
    alumno_Modalidad=new char[numdat+1]{};
    alumno_Nombre=new char*[numdat+1]{};
    alumno_Porcentaje=new int[numdat+1]{};
    for(int i=0;i<numdat;i++){
        alumno_Codigo[i]=bufferCodigo[i];
        alumno_Escala[i]=bufferEscala[i];
        alumno_Modalidad[i]=bufferModalidad[i];
        alumno_Nombre[i]=bufferNombre[i];
        alumno_Porcentaje[i]=bufferPorcent[i];
//        cout<<alumno_Escala[i]<<endl;
    }
}
void pruebaLecturaAlumnos(const char*nomb,int *alumno_Codigo,char **alumno_Nombre,
            char *alumno_Modalidad,int *alumno_Porcentaje,int *alumno_Escala){
    ofstream Arch(nomb,ios::out);
    if(not Arch.is_open()){
        cout<<"Error no se pudo abrir el archivo  "<<nomb<<endl;
        exit(1);
    }
    for(int i=0;alumno_Nombre[i];i++){
        Arch<<setw(10)<<alumno_Codigo[i]<<" "<<left<<setw(60)<<alumno_Nombre[i]
                <<right<<setw(5)<<alumno_Modalidad[i]<<setw(6)<<alumno_Porcentaje[i]
                <<setw(5)<<alumno_Escala[i]<<endl;
        
    }
}
void lecturaCursos(const char*nomb,int *alumno_Codigo,int *alumno_Escala,char **&curso_Nombre
            ,double *&curso_Credito,int **&cursos_Alumnos){
    ifstream Arch(nomb,ios::in);
    if(not Arch.is_open()){
        cout<<"Error no se pudo abrir el archivo  "<<nomb<<endl;
        exit(1);
    }
    //8072,Aplicaciones de las Ciencias de la Computacion,3.5
    int codAlumno,numdat=0,pos;
    double cred,bufferCred[150]{};
    char *NombreCurso,*bufferNombreCurso[150]{};
    int *bufferCursos_Alumnos[150]{};
    while(true){
        Arch>>codAlumno;
        if(Arch.eof())break;
        Arch.get();
        NombreCurso=leerCadena(Arch);
        Arch>>cred;
        pos=buscarCurso(NombreCurso,bufferNombreCurso);
        if(pos!=-1){
            agregarAlumnos(bufferCursos_Alumnos[pos],codAlumno,alumno_Escala,alumno_Codigo);
           
        }
        else{
            bufferNombreCurso[numdat]=NombreCurso;
            bufferCred[numdat]=cred;
            agregarAlumnos(bufferCursos_Alumnos[numdat],codAlumno,alumno_Escala,alumno_Codigo);
            numdat++;
        }
    }
    recortarBufferAlum(bufferCursos_Alumnos);
    LlenarPunteros(curso_Credito,curso_Nombre,cursos_Alumnos,numdat,bufferCred,
            bufferCursos_Alumnos,bufferNombreCurso);
}
int buscarCurso(char *NombreCurso,char **bufferNombreCurso){
    for(int i=0;bufferNombreCurso[i];i++){
        if(comparar(bufferNombreCurso[i],NombreCurso))return i;
    }
    return -1;
}
bool comparar(char *bufferNombreCurso,char *NombreCurso){
    if(strcmp(bufferNombreCurso,NombreCurso)==0){
        return true;
    }
    else{
        return false;
    }
}
void agregarAlumnos(int *&bufferCursos_Alumnos,int codAlumno,int *alumno_Escala,
            int *alumno_Codigo){
    int pos;
    pos=buscarAlumnos(codAlumno,alumno_Codigo);
    
    if(bufferCursos_Alumnos){
        int cant=0;
        while(bufferCursos_Alumnos[cant])cant++;
        bufferCursos_Alumnos[cant]=alumno_Codigo[pos];
        bufferCursos_Alumnos[cant+1]=alumno_Escala[pos];
    }
    else{
        bufferCursos_Alumnos=new int[600]{};
        bufferCursos_Alumnos[0]=alumno_Codigo[pos];
        bufferCursos_Alumnos[1]=alumno_Escala[pos];
    }
    
}
int buscarAlumnos(int codAlumno,int *alumno_Codigo){
    for(int i=0;alumno_Codigo[i]!=0;i++){
        if(codAlumno==alumno_Codigo[i])return i;
    }
    return -1;
}
void recortarBufferAlum(int **bufferCursos_Alumnos){
    for(int i=0;bufferCursos_Alumnos[i];i++){
        recortarAlum(bufferCursos_Alumnos[i]);
    }
}
void recortarAlum(int *&bufferCursos_Alumnos){
    int dat=0;
    for(dat=0;bufferCursos_Alumnos[dat];dat++);
    int *ptr=new int[dat+1]{};
    for(int i=0;i<dat;i++){
        ptr[i]=bufferCursos_Alumnos[i];
    }
    delete bufferCursos_Alumnos;
    bufferCursos_Alumnos=ptr;
}
void LlenarPunteros(double *&curso_Credito,char **&curso_Nombre,int **&cursos_Alumnos,
        int numdat,double *bufferCred,int **bufferCursos_Alumnos,char **bufferNombreCurso){
    curso_Credito=new double[numdat+1];
    cursos_Alumnos=new int*[numdat+1];
    curso_Nombre=new char*[numdat+1];
    for(int i=0;i<numdat;i++){
        curso_Credito[i]=bufferCred[i];
        cursos_Alumnos[i]=bufferCursos_Alumnos[i];
        curso_Nombre[i]=bufferNombreCurso[i];
    }
}
void ProbarCursos(const char*nomb,double *curso_Credito,char **curso_Nombre,int **cursos_Alumnos){
    ofstream Arch(nomb,ios::out);
    if(not Arch.is_open()){
        cout<<"Error no se pudo abrir el archivo  "<<nomb<<endl;
        exit(1);
    }
    for(int i=0;curso_Nombre[i];i++){
        Arch<<left<<setw(60)<<curso_Nombre[i]<<right<<setw(10)<<curso_Credito[i]<<endl;
        Arch<<"MATRICULADOS : "<<endl;
        ImprimeCursos(Arch,cursos_Alumnos[i]);
    }
}
void ImprimeCursos(ofstream &Arch,int *cursos_Alumnos){
    for(int i=0;cursos_Alumnos[i];i+=2){
        Arch<<setw(10)<<cursos_Alumnos[i]<<setw(5)<<cursos_Alumnos[i+1]<<endl;
    }
}