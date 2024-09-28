/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include "Funciones.h"
#include "Alumno.h"
#include "AlumnoNota.h"
#include "Nota.h"

using namespace std;

#define NO_ENCONTRADO -1

void cargaralumnos(class Alumno *arrAlumnos){
    ifstream archAlu("Alumnos.csv",ios::in);
    if(not archAlu.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    int num=0;
    while(true){
        archAlu>>arrAlumnos[num];
        if(archAlu.eof()) break;
        num++;
    }
}

void carganotas(class AlumnoNota *arrAluNotas){
    ifstream archNot("Notas.csv",ios::in);
    if(not archNot.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Notas.csv"<<endl;
        exit(1);
    }
    int num=0;
    while(true){
        archNot>>arrAluNotas[num];
        if(archNot.eof()) break;
//        cout<<arrAluNotas[num].GetNota()<<endl;
        num++;
    }
}

void actualizanotas(class Alumno *arrAlumnos,class AlumnoNota *arrAluNotas){
    class Nota auxNota;
    int posAlu,numAprob,vez1,vez2,vez3;
    for(int i=0;arrAluNotas[i].GetCodigo();i++){
        posAlu=buscarAlu(arrAluNotas[i].GetCodigo(),arrAlumnos);
        if(posAlu!=NO_ENCONTRADO){
            arrAluNotas[i]&auxNota;
            arrAlumnos[posAlu]+=auxNota;
        }
    }
    for(int i=0;arrAlumnos[i].GetCodigo();i++){
        arrAlumnos[i].ObtenerDatos();    
    }
}

int buscarAlu(int cod,class Alumno *arr){
    for(int i=0;arr[i].GetCodigo();i++){
        if(arr[i].GetCodigo()==cod) return i;
    }
    return NO_ENCONTRADO;
}

void imprimealumnos(class Alumno *arrAlumnos){
    ofstream archRep("ReporteFinal.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteFinal.txt"<<endl;
        exit(1);
    }
    for(int i=0;arrAlumnos[i].GetCodigo();i++){
        archRep<<arrAlumnos[i];
    }
}