/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Facultad.cpp
 * Author: margo
 * 
 * Created on 8 de julio de 2024, 18:48
 */

#include "Facultad.h"
#include "AperturaDeArchivos.h"
#include "Nota.h"
Facultad::Facultad() {
}

Facultad::Facultad(const Facultad& orig) {
}

Facultad::~Facultad() {
}

void Facultad::leerAlumnosNotas(const char*nombAl, const char*nombNo) {
    ifstream archA;
    ifstream archN;
    AperturaDeUnArchivoDeTextosParaLeer(archA, nombAl);
    AperturaDeUnArchivoDeTextosParaLeer(archN, nombNo);
//    Nodo*ptr=nullptr;
    Alumno al;
    while(true){
        archA>>al;
        if (archA.eof()) break;
        alumnoxNotas.insertarNodo(al);
    }
    Nota notita;
    int codigo, semestre;
    while(true){
        archN>>semestre;
        if(archN.eof()) break;
        archN.get();
        archN>>codigo;
        archN.get();
        vector<Nota>aux;
        while(true){
            archN>>notita;     
            notita.SetCiclo(semestre);
              char cod[10]{};
            notita.GetCodigo_curso(cod);
            cout<<cod<<' ';
            aux.push_back(notita);//constructor copia
            if (archN.get()=='\n')break;
        }
        insertarEnLista(codigo, aux);
    }
}

void Facultad::insertarEnLista(int codigo, vector<Nota>&notas) {
    alumnoxNotas.agregarNotas(codigo, notas);
}

void Facultad::ImprimeAlumnosNotas(const char* nombarch) {
    ofstream arch(nombarch, ios::out);
    if(not arch.is_open()){
        cout<<"error con la impresion"<<endl;
    }
    alumnoxNotas.impresion(arch);
    
}
