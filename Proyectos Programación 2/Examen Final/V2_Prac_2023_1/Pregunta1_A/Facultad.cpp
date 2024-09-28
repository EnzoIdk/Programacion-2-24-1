/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Facultad.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 06:55 PM
 */

#include "Facultad.h"

Facultad::Facultad() {
}

//Facultad::Facultad(const Facultad& orig) {
//}

Facultad::~Facultad() {
}

void Facultad::leerAlumnosNotas(const char* arch1, const char* arch2) {
    ifstream in1(arch1,ios::in);
    if(!in1){
        cout<<"No se pudo abrir el archivo "<<arch1<<endl;
        exit(1);
    }
    
    ifstream in2(arch2,ios::in);
    if(!in2){
        cout<<"No se pudo abrir el archivo "<<arch2<<endl;
        exit(1);
    }
    
    cargarAlumnos(in1);
    cargarNotas(in2);
}

void Facultad::cargarAlumnos(ifstream& in) {
    while(true){
        Alumno al;
        in>>al;
        if(in.eof())break;
        alumnosxNotas.insertarLista(al);
    }
}

void Facultad::cargarNotas(ifstream& in) {
    int semestre;
    int cod;
    while(true){
        in>>semestre;
        if(in.eof())break;
        in.get();
        in>>cod;
        while(in.get()!='\n'){
            Nota nota;
            in>>nota;
            nota.setCiclo(semestre);
            nota.setVez(1);
            alumnosxNotas.insertarNota(nota,cod);
        }
    }
}

void Facultad::imprimirAlumnosNotas(const char* arch) {
    ofstream out(arch,ios::out);
    if(!out){
        cout<<"No se pudo abrir el archivo "<<arch<<endl;
        exit(1);
    }
    out.precision(2);
    out<<fixed;
    out<<left;
    out<<"REPORTE DE ALUMNOS"<<endl;
    for(int i=0;i<120;i++)out<<"=";
    out<<endl;
    out<<setw(15)<<"CODIGO"<<setw(50)<<"NOMBRE"<<setw(10)<<"PROMEDIO"<<endl;
    for(int i=0;i<120;i++)out<<"=";
    out<<endl;
    alumnosxNotas.imprimeLista(out);
}

void Facultad::actualizaNotas() {
    alumnosxNotas.actualizarNotas();
    alumnosxNotas.totalizar();
}
