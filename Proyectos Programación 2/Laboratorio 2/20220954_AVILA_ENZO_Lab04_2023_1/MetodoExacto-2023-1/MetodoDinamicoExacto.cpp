/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>      
#include <cstring>

using namespace std;

#include "MetodoDinamicoExacto.h"
#define TAM_LINEA 120
#define NO_ENCONTRADO -1

void lecturaAlumnos(const char *nombArch,int *&alumno_Codigo,char **&alumno_Nombre,
        char *&alumno_Modalidad,int *&alumno_Porcentaje,int *&alumno_Escala){
    char *bufferAluNomb[100]{},bufferAluMod[100]{};
    int bufferAluCod[100]{},bufferAluPorc[100]{},bufferAluEsc[100]{},numDatos=0,cod;
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        bufferAluCod[numDatos]=cod;
        bufferAluNomb[numDatos]=leerCadena(arch);
        leerOtrosDatos(arch,bufferAluMod[numDatos],bufferAluPorc[numDatos],
                bufferAluEsc[numDatos]);
//        cout<<bufferAluPorc[numDatos]<<' '<<bufferAluEsc[numDatos]<<endl;
        numDatos++;
    }
    alumno_Codigo=new int[numDatos+1]{};
    alumno_Nombre=new char*[numDatos+1]{};
    alumno_Modalidad=new char[numDatos+1]{};
    alumno_Porcentaje=new int[numDatos+1]{};
    alumno_Escala=new int[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        alumno_Codigo[i]=bufferAluCod[i];
        alumno_Nombre[i]=bufferAluNomb[i];
        alumno_Modalidad[i]=bufferAluMod[i];
        alumno_Porcentaje[i]=bufferAluPorc[i];
        alumno_Escala[i]=bufferAluEsc[i];
    }
}

void leerOtrosDatos(ifstream &arch,char &aluMod,int &aluPorc,int &aluEsc){
    int escala;
    char car;
    aluMod='P';
    aluPorc=0;
    arch>>escala;
    if(arch.fail()){
        arch.clear();
        arch>>aluMod>>car;
    }
    if(aluMod=='V'){
        arch>>escala;
    }
    else if(aluMod=='S'){
        arch>>aluPorc>>car>>escala;
    }
    aluEsc=escala;
}

char *leerCadena(ifstream &arch){
    char cadena[100],*ptr;
    arch.getline(cadena,100,',');
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void pruebaLecturaAlumnos(const char *nombArch,int *alumno_Codigo,char **alumno_Nombre,
        char *alumno_Modalidad,int *alumno_Porcentaje,int *alumno_Escala){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archReporte<<setprecision(2)<<fixed;
    archReporte<<"CODIGO"<<setw(8)<<' '<<"NOMBRE"<<setw(30)<<' '<<"MODALIDAD"<<
            setw(2)<<' '<<"PORCENTAJE"<<setw(2)<<' '<<"ESCALA"<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'=');
    for(int i=0;alumno_Codigo[i];i++){
        archReporte<<alumno_Codigo[i]<<setw(7)<<' '<<left<<setw(40)<<alumno_Nombre[i]<<
                right<<setw(4)<<alumno_Modalidad[i]<<setw(11)<<alumno_Porcentaje[i]<<
                setw(9)<<alumno_Escala[i]<<endl;
    }
}

void lecturaCursos(const char *nombArch,int *alumno_Codigo,int *alumno_Escala,
        char **&curso_Nombre,double *&curso_Credito,int **&curso_Alumnos){
    char *bufferCurNomb[100]{},*nombCur;
    double bufferCurCred[100]{},creditos;
    int *bufferCurAlu[100]{},nd[100]{},codAlu,posAlu,numCursos=0,posCur;
    for(int i=0;i<100;i++){
        bufferCurAlu[i]=new int[100]{}; /*cada curso puede tener hasta 50 alumnos por decir*/
    }
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    while(true){
        arch>>codAlu;
        if(arch.eof()) break;
        arch.get();
        posAlu=buscarAlumno(alumno_Codigo,codAlu);
        if(posAlu!=NO_ENCONTRADO){
            nombCur=leerCadena(arch);
            arch>>creditos;
            posCur=buscarCurso(bufferCurNomb,nombCur);
            if(posCur==NO_ENCONTRADO){
                bufferCurNomb[numCursos]=nombCur;
                bufferCurCred[numCursos]=creditos;
                agregarDatosAlu(bufferCurAlu[numCursos],nd[numCursos],alumno_Codigo[posAlu],
                        alumno_Escala[posAlu]);
                numCursos++;
            }
            else{
                agregarDatosAlu(bufferCurAlu[posCur],nd[posCur],alumno_Codigo[posAlu],
                        alumno_Escala[posAlu]);
            }
        }
        else while(arch.get()!='\n');
    }
    llenarPunteros(curso_Nombre,curso_Credito,curso_Alumnos,bufferCurNomb,
            bufferCurCred,bufferCurAlu,numCursos,nd);
}

void llenarPunteros(char **&curso_Nombre,double *&curso_Creditos,int **&curso_Alumnos,
        char **bufferCurNomb,double *bufferCurCred,int **bufferCurAlu,int numCursos,int *nd){
    curso_Nombre=new char*[numCursos+1]{};
    curso_Alumnos=new int *[numCursos+1]{};
    curso_Creditos=new double[numCursos+1]{};
    for(int i=0;i<numCursos;i++){
        curso_Nombre[i]=bufferCurNomb[i];
        curso_Creditos[i]=bufferCurCred[i];
        espaciosExactos(curso_Alumnos[i],bufferCurAlu[i],nd[i]);
    }
}

void espaciosExactos(int *&curso_Alumno,int *&bufferCurAlu,int nd){
    int *cur_Alu_Aux;
    if(nd!=0){
        cur_Alu_Aux=new int[nd+1]{};
        for(int i=0;bufferCurAlu[i];i++) cur_Alu_Aux[i]=bufferCurAlu[i];
        delete bufferCurAlu;
        curso_Alumno=cur_Alu_Aux;
    }
    else{
        delete bufferCurAlu;
        curso_Alumno=nullptr;
    }
}
/*se añaden los datos por grupos de dos en dos, 
    se va añadiendo el número de alumnos en dos cada vez*/
void agregarDatosAlu(int *&bufferCurAlu,int &numAlumnos,int cod,int escala){
    bufferCurAlu[numAlumnos]=cod;
    bufferCurAlu[numAlumnos+1]=escala;
    numAlumnos+=2;
}

int buscarAlumno(int *alumnos,int cod){
    for(int i=0;alumnos[i];i++){
        if(cod==alumnos[i]) return i;
    }
    return NO_ENCONTRADO;
}

int buscarCurso(char **cursos,char *nombre){
    for(int i=0;cursos[i];i++){
        if(strcmp(cursos[i],nombre)==0) return i;
    }
    return NO_ENCONTRADO;
}

void pruebaDeLecturaCursos(const char *nombArch,char **curso_Nombre,
        double *curso_Credito,int **curso_Alumnos){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    archReporte<<setprecision(2)<<fixed;
    for(int i=0;curso_Nombre[i];i++){
        archReporte<<setw(3)<<i+1<<')'<<setw(3)<<' '<<"CURSO: "<<
                left<<setw(40)<<curso_Nombre[i]<<right<<setw(4)<<' '<<
                "Creditos: "<<setw(6)<<curso_Credito[i]<<endl;
        imprimirLinea(archReporte,TAM_LINEA,'-');
        archReporte<<setw(4)<<' '<<"ALUMNOS MATRICULADOS: "<<endl;
        archReporte<<setw(4)<<' '<<"Codigo"<<setw(5)<<' '<<"Escala"<<endl;
        imprimirLinea(archReporte,TAM_LINEA,'-');
        imprimirAlumnos(archReporte,curso_Alumnos[i]);
        imprimirLinea(archReporte,TAM_LINEA,'=');
    }
}

void imprimirAlumnos(ofstream &archReporte,int *cursosAlumnos){
    for(int i=0;cursosAlumnos[i];i+=2){
        archReporte<<setw(5)<<' '<<cursosAlumnos[i]<<setw(10)<<cursosAlumnos[i+1]<<endl;
    }
}

void reporteDeRecaudacionPorModalidad(const char *nombArch,int *alumno_Codigo,
        char *alumno_Modalidad,int *alumno_Porcentaje,char **alumno_Nombre,char **curso_Nombre,
        double *curso_Credito,int **curso_Alumnos){
    ofstream archReporte(nombArch,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    /*dicen que no se puede leer otra vez ni crear arreglos auxiliares, pero no sé que hacer dx*/
    double arrCostoCred[10]{},totalP,totalS,totalV,finalP=0,finalS=0,finalV=0;
    llenarArreglo("escalas.csv",arrCostoCred);
    archReporte<<setprecision(2)<<fixed;
    imprimirEncabezado(archReporte);
    for(int i=0;curso_Nombre[i];i++){
        archReporte<<setfill('0')<<setw(2)<<i+1<<')'<<setfill(' ')<<
                setw(3)<<' '<<"CURSO: "<<left<<setw(50)<<curso_Nombre[i]<<
                right<<setw(4)<<' '<<"Creditos: "<<setw(6)<<curso_Credito[i]<<endl;
        imprimirLinea(archReporte,TAM_LINEA,'-');
        archReporte<<setw(4)<<' '<<"ALUMNOS MATRICULADOS: "<<endl;
        imprimirLinea(archReporte,TAM_LINEA,'-');
        archReporte<<setw(80)<<' '<<"PAGOS"<<endl<<setw(3)<<' '<<"CODIGO"<<
                setw(4)<<' '<<"NOMBRE"<<setw(36)<<' '<<"ESCALA"<<setw(5)<<' '<<
                "PRESENCIAL"<<setw(3)<<' '<<"SEMI PRESENCIAL"<<setw(5)<<' '<<
                "VIRTUAL"<<endl;
        imprimirReporteAlumnos(archReporte,alumno_Codigo,alumno_Modalidad,
                alumno_Porcentaje,alumno_Nombre,curso_Alumnos[i],arrCostoCred,
                curso_Credito[i],totalP,totalS,totalV);
        imprimirLinea(archReporte,TAM_LINEA,'=');
        archReporte<<"RECAUDACION POR MODALIDAD DE ESTUDIO"<<setw(39)<<
                totalP<<setw(15)<<totalS<<setw(16)<<totalV<<endl;
        imprimirLinea(archReporte,TAM_LINEA,'-');
        archReporte<<"TOTAL RECAUDADO"<<setw(91)<<totalP+totalS+totalV<<endl;
        imprimirLinea(archReporte,TAM_LINEA,'=');
        finalP+=totalP;
        finalS+=totalS;
        finalV+=totalV;
    }
    archReporte<<"RECAUDACION TOTAL POR MODALIDAD DE ESTUDIO"<<setw(33)<<
            finalP<<setw(15)<<finalS<<setw(16)<<finalV<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'-');
    archReporte<<"TOTAL GENERAL RECAUDADO: "<<setw(81)<<finalP+finalS+finalV<<endl;
    imprimirLinea(archReporte,TAM_LINEA,'=');
}

void imprimirReporteAlumnos(ofstream &archReporte,int *aluCod,char *aluMod,int *aluPorc,
        char **aluNomb,int *curso_Alumnos,double *arrCostoCred,double creditos,
        double &totalP,double &totalS,double &totalV){
    int num=0,posAlu;
    double pago;
    totalP=totalS=totalV=0;
    for(int i=0;curso_Alumnos[i];i+=2){
        posAlu=buscarAlumno(aluCod,curso_Alumnos[i]);
        if(posAlu!=NO_ENCONTRADO){
            num++;
            archReporte<<setfill('0')<<setw(2)<<num<<')'<<setfill(' ')<<setw(2)<<' '<<
                aluCod[posAlu]<<setw(3)<<' '<<left<<setw(40)<<aluNomb[posAlu]<<
                    right<<setw(7)<<curso_Alumnos[i+1]<<setw(3)<<' ';
            pago=arrCostoCred[curso_Alumnos[i+1]]*creditos;
            pago*=(1-(double)aluPorc[posAlu]/100);
            if(aluMod[posAlu]=='P'){
                archReporte<<setw(13)<<pago<<endl;
                totalP+=pago;
            }
            else if(aluMod[posAlu]=='S'){
                archReporte<<setw(28)<<pago<<endl;
                totalS+=pago;
            }
            else{
                archReporte<<setw(44)<<pago<<endl;
                totalV+=pago;
            }
        }
    }
}

void llenarArreglo(const char *nombArch,double *arrCostoCred){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int escala,num=0;
    char car;
    while(true){
        arch>>car;
        if(arch.eof()) break;
        arch>>escala>>car>>arrCostoCred[5-num];
        arch.get();
        num++;
    }
//    cout<<arrCostoCred[1]<<' '<<arrCostoCred[5]<<' '<<endl;
}

void imprimirEncabezado(ofstream &arch){
    arch<<setw(40)<<' '<<"ENTIDAD EDUCATIVA LP1"<<endl<<setw(43)<<' '<<
            "LISTADO DE CLASE"<<endl;
    imprimirLinea(arch,TAM_LINEA,'=');
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}