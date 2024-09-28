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
#include "Preg2_Funciones_de_historia_de_notas.h"
#define NO_ENCONTRADO -1
#define TAM_LINEA 80

void cargarNotas(char ***&cursos_cod,int ***&cursos_nota_sem_veces,double **&costos,
        int **alumnos,char ***alumnos_nom_mod,double *escalas,char ***cursos,
        double *cursos_cred,const char *nombArch){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    int numAlu;
    for(numAlu=0;alumnos[numAlu];numAlu++);
    int codAlu,ciclo,nota,**bufferNotSemVec[numAlu+1]{},nd[numAlu+1]{},posAlu,posCur;
    char *codCurso,**bufferCurCod[numAlu+1]{};
    double *bufferCostos[numAlu+1]{};
    inicializarSubBuffers(bufferNotSemVec,bufferCurCod,bufferCostos,numAlu);
    while(true){
        leerDatosNotas(arch,codAlu,ciclo,nota,codCurso);
        if(arch.eof()) break;
        posAlu=buscarAlu(alumnos,codAlu);
        posCur=buscarCur(cursos,codCurso);
        if(posAlu!=NO_ENCONTRADO and posCur!=NO_ENCONTRADO){
            agregarCurso(nd[posAlu],bufferCurCod[posAlu],codCurso,bufferNotSemVec[posAlu],
                    nota,ciclo,bufferCostos[posAlu],alumnos[posAlu],alumnos_nom_mod[posAlu],
                    escalas,cursos_cred[posCur]);
        }
    }
    asignarArreglos(cursos_cod,cursos_nota_sem_veces,costos,bufferCurCod,
            bufferNotSemVec,bufferCostos,nd,numAlu);
}

void asignarArreglos(char ***&arr1,int ***&arr2,double **&arr3,char ***arrAux1,
        int ***arrAux2,double **arrAux3,int *nd,int numAlu){
    arr1=new char**[numAlu+1]{};
    arr2=new int**[numAlu+1]{};
    arr3=new double*[numAlu+1]{};
    for(int i=0;i<numAlu;i++) 
        memoriaExacta(arr1[i],arr2[i],arr3[i],arrAux1[i],arrAux2[i],arrAux3[i],nd[i]);
}

void memoriaExacta(char **&arr1,int **&arr2,double *&arr3,char **arrAux1,int **arrAux2,
        double *arrAux3,int nd){
    arr1=new char*[nd+1]{};
    arr2=new int*[nd+1]{};
    arr3=new double[nd+1]{};
    for(int i=0;i<=nd;i++){
        arr1[i]=arrAux1[i];
        arr2[i]=arrAux2[i];
        arr3[i]=arrAux3[i];
    }
}

void agregarCurso(int &nd,char **cursosCod,char *codigo,int **cursosNotSemVec,int nota,int ciclo,
        double *costos,int *datosAlumno,char **aluNomMod,double *escalas,double cred){
    int *auxCurNotSemVec;
    int posCursoCod=buscarCursoCod(cursosCod,codigo,nd);
    double costoCurso=calcularCosto(datosAlumno,aluNomMod,escalas,cred);
    if(posCursoCod==NO_ENCONTRADO){
        cursosCod[nd]=codigo;
        auxCurNotSemVec=new int[3]{}; 
        auxCurNotSemVec[0]=nota;
        auxCurNotSemVec[1]=ciclo;
        auxCurNotSemVec[2]=1;
        cursosNotSemVec[nd]=auxCurNotSemVec;
        costos[nd+1]=costos[nd]+costoCurso;
        costos[nd]=costoCurso;
        nd++;
    }
    else{
        auxCurNotSemVec=cursosNotSemVec[posCursoCod];
        if(ciclo>auxCurNotSemVec[1]){
            auxCurNotSemVec[0]=nota;
            auxCurNotSemVec[1]=ciclo;
        }
        auxCurNotSemVec[2]++;
        cursosNotSemVec[posCursoCod]=auxCurNotSemVec;
        costos[posCursoCod]+=costoCurso;
        costos[nd]+=costoCurso;
    }
}

int buscarCursoCod(char **cursosCod,char *cod,int nd){
    for(int i=0;i<nd;i++){
        if(strcmp(cursosCod[i],cod)==0) return i;
    }
    return NO_ENCONTRADO;
}

double calcularCosto(int *datosAlu,char **aluNomMod,double *escalas,double cred){
    double costo;
    char mod=*aluNomMod[1];
    costo=cred*escalas[datosAlu[1]-1];
    if(mod=='S'){
        costo*=(1-(double)datosAlu[2]/100);
    }
    return costo;
}

void inicializarSubBuffers(int ***buffer1,char ***buffer2,double **buffer3,int num){
    for(int i=0;i<num;i++){
        buffer1[i]=new int*[10]{};
        buffer2[i]=new char*[10]{};
        buffer3[i]=new double[10]{};
    }
}

void leerDatosNotas(ifstream &arch,int &codAlu,int &ciclo,int &nota,char *&codCurso){
    char car;
    arch>>codAlu;
    if(arch.eof()) return;
    arch.get();
    codCurso=leerCadena(arch,',');
    arch>>ciclo>>car>>nota;
}

int buscarAlu(int **alumnos,int cod){
    int *aux;
    for(int i=0;alumnos[i];i++){
        aux=alumnos[i];
        if(aux[0]==cod) return i;
    }
    return NO_ENCONTRADO;
}

int buscarCur(char ***cursos,char *cod){
    char **datos,*codCur;
    for(int i=0;cursos[i];i++){
        datos=cursos[i];
        codCur=datos[0];
        if(strcmp(codCur,cod)==0) return i;
    }
    return NO_ENCONTRADO;
}

void pruebaDeCargaDeNotas(char ***cursos_cod,int ***cursos_nota_sem_veces,
        double **costos,int **alumnos,char ***alumnos_nom_mod,const char *nombArch){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    arch<<setprecision(2)<<fixed;
    for(int i=0;alumnos[i];i++){
        imprimirLinea(arch,TAM_LINEA,'=');
        imprimirAlumnos(arch,alumnos[i],alumnos_nom_mod[i],cursos_cod[i],
                cursos_nota_sem_veces[i],costos[i]);
    }
}

void imprimirAlumnos(ofstream &arch,int *datosAlu,char **aluNomMod,char **codCurAlu,
        int **datosCurAlu,double *costos){
    int i,*auxDatosCurso;
    arch<<"CODIGO: "<<datosAlu[0]<<' '<<"NOMBRE: "<<aluNomMod[0]<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    arch<<"CURSOS QUE LLEVO: "<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    arch<<"COD_CUR"<<setw(2)<<' '<<"ULTIMA NOTA"<<setw(2)<<' '<<"ULTIMO CICLO"<<
            setw(2)<<' '<<"VECES"<<setw(4)<<' '<<"COSTO"<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    for(i=0;codCurAlu[i];i++){
        auxDatosCurso=datosCurAlu[i];
        arch<<codCurAlu[i]<<setw(10)<<auxDatosCurso[0]<<setw(15)<<auxDatosCurso[1]<<
                setw(8)<<auxDatosCurso[2]<<setw(12)<<costos[i]<<endl;
    }
    imprimirLinea(arch,TAM_LINEA,'-');
    if(i==0) arch<<"NO HA LLEVADO CURSOS"<<endl;
    else arch<<"TOTAL GASTADO: "<<setw(36)<<costos[i]<<endl;
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}