/* 
 * File:   Tesoreria.cpp
 * Author: ramir
 * 
 * Created on 5 de junio de 2024, 02:49 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <valarray>
using namespace std;
#include "Tesoreria.h"
#define MAX_LINEA 100

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
}

Tesoreria::~Tesoreria() {
}
/*
5,666.90
4,556.70
*/
void Tesoreria::cargaescalas(){
    ifstream archEsc("escalas.csv",ios::in);
    if(not archEsc.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo escalas.csv"<<endl;
        exit(1);
    }
    int numEsc;
    double costoXCred;
    while(1){
        archEsc>>numEsc;
        if(archEsc.eof()) break;
        archEsc.get();
        archEsc>>costoXCred;
        lescala[numEsc-1].SetCodigo(numEsc);
        lescala[numEsc-1].SetPrecio(costoXCred);
    }
}

void Tesoreria::cargaalumnos(){
    ifstream archBol("Alumnos.csv",ios::in);
    if(not archBol.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    int i=0;
    while(1){
        lboleta[i].leealumno(archBol);
        if(archBol.eof()) break;
        i++;
    }
}

void Tesoreria::actualizaboleta(){
    int numEsc;
    double costoXCred;
    for(int i=0;lboleta[i].existe();i++){
        numEsc = lboleta[i].GetEscala();
        costoXCred = lescala[numEsc-1].GetPrecio();
        lboleta[i].actualizaboleta(costoXCred);
    }
}
    
void Tesoreria::imprimeboleta(){
    ofstream archRep("Reporte.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    archRep<<left<<setw(18)<<"Codigo"<<setw(38)<<"Nombre"<<setw(12)<<"Escala"
           <<setw(9)<<"Cred."<<setw(14)<<"Licencia"<<"Total"<<endl;
    imprimirLinea(archRep,'=');
    for(int i=0;lboleta[i].existe();i++)
        lboleta[i].imprimealumno(archRep);
}

void Tesoreria::imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}