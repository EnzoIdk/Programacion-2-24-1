/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Registro.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 04:40 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Registro.h"
#include "Nota.h"
//Registro::Registro() {
//}
//
//Registro::Registro(const Registro& orig) {
//}
//
//Registro::~Registro() {
//}

void Registro::carga(){
    ifstream arch("registronotas.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo registronotas.csv"<<endl;
        exit(1);
    }
    class Nota auxNota;
    while(true){
        auxNota.leeNota(arch);
        if(arch.eof()) break;
        vregistro.push_back(auxNota);
    }
}

void Registro::procesa(){
    sort(vregistro.begin(),vregistro.end());
    int i;
    for(i=0;i<vregistro.size();i++){
        cout<<i<<' ';
        vregistro[i].muestraNota();
    }
    cout<<i<<endl;
    char cod1[10],cod2[10];
    for(vector<Nota>::iterator i=vregistro.begin();i!=vregistro.end();i++){
        (*i).GetCodCur(cod1);
        for(vector<Nota>::iterator j=i;j!=vregistro.end();j++){
            if(j!=i){
                (*j).GetCodCur(cod2);
                if(strcmp(cod1,cod2)==0 and (*i).GetCodigo()==(*j).GetCodigo()){
                    (*i).actualizar(*j);
                    vector<Nota>::iterator k=j;
                    j--;
                    vregistro.erase(k);
                }
                else break;
            }
        }
    }
}

void Registro::muestra(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    arch<<"Registro de notas"<<endl;
    for(int i=0;i<120;i++) arch.put('=');
    arch<<endl<<"Codigo"<<setw(4)<<' '<<"Curso"<<setw(3)<<' '<<"Ciclo"<<
            setw(4)<<' '<<"Nota"<<setw(6)<<' '<<"Vez"<<setw(3)<<' '<<"Creditos"<<
            setw(2)<<' '<<"Codigo de Acceso"<<endl;
    for(int i=0;i<120;i++) arch.put('=');arch<<endl;
    for(int i=0;i<vregistro.size();i++){
        vregistro[i].imprimeNota(arch);
    }
}