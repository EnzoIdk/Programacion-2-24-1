/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Registro.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 08:26 PM
 */

#include "Registro.h"

Registro::Registro() {
}

//Registro::Registro(const Registro& orig) {
//}

Registro::~Registro() {
}

void Registro::carga() {
    ifstream in("registronotas.csv",ios::in);
    if(!in){
        cout<<"No se pudo abrir el archivo Notas"<<endl;
        exit(1);
    }
    
    while(true){
        Nota nota;
        nota.leer(in);
        if(in.eof())break;
        vregistro.push_back(nota);
    }
}

void Registro::procesa() {
    sort(vregistro.begin(),vregistro.end());
    char cod1[20],cod2[20];
    for(vector<Nota>::iterator i = vregistro.begin();i!=vregistro.end();i++){
        i->getCurso(cod1);
        for(vector<Nota>::iterator j = i;j!=vregistro.end();j++){
            if(j == i)continue;
            vector<Nota>::iterator k;
            j->getCurso(cod2);
            if(strcmp(cod1,cod2) != 0 or i->getCodigo() != j->getCodigo())break;
            i->actualizar(*j);
            k = j;
            j--;
            vregistro.erase(k);
        }
    }
}

void Registro::muestra() {
    ofstream out("Reporte.txt",ios::out);
    if(!out){
        cout<<"No se pudo abrir el archivo Reporte"<<endl;
        exit(1);
    }
    out.precision(2);
    out<<fixed;
    out<<left;
    out<<"REPORTE DE NOTAS"<<endl;
    for(int i=0;i<120;i++)out<<"=";
    out<<endl;
    out<<setw(15)<<"CODIGO"<<setw(10)<<"CURSO"<<setw(10)<<"CICLO"<<setw(10)<<"NOTA"<<setw(10)<<"VEZ"
            <<setw(10)<<"CREDITOS"<<setw(10)<<"COD.ACCESO/CRED./PORCENTAJE"<<endl;
    for(int i=0;i<120;i++)out<<"=";
    out<<endl;
    for(vector<Nota>::iterator i = vregistro.begin();i!=vregistro.end();i++){
        i->imprimir(out);
    }
}
