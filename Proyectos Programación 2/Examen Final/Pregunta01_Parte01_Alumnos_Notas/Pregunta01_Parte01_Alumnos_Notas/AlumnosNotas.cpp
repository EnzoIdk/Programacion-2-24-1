/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlumnosNotas.cpp
 * Author: margo
 * 
 * Created on 8 de julio de 2024, 18:47
 */

#include "AlumnosNotas.h"

AlumnosNotas::AlumnosNotas() {
}

AlumnosNotas::AlumnosNotas(const AlumnosNotas& orig) {
}

AlumnosNotas::~AlumnosNotas() {
}

void AlumnosNotas::agregarAlumno(Alumno&al) {
    alumno.SetCodigo_alumno(al.GetCodigo_alumno());
    char nombre[100]{};
    al.GetNombre(nombre);
    alumno.SetNombre(nombre);
    alumno.SetPromedio(0);
}

int AlumnosNotas::codigoAlumno() {
    return alumno.GetCodigo_alumno();
}

void AlumnosNotas::impresion(ofstream&arch) {
    arch<<alumno;
    arch<<endl;
    for(auto x: notas){
        arch<<x;
        arch<<endl;
    }
}

void AlumnosNotas::agregarNotas(vector<Nota>& nottas) {
    for(int i=0;i<nottas.size();i++){
        Nota nota=nottas[i];
        notas.push_back(nota);
   
    }
    
   
}
