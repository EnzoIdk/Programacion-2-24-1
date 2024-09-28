/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   AlumnoNotas.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 01:04 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
#include "AlumnoNotas.h"

AlumnoNotas::AlumnoNotas() {
}

AlumnoNotas::AlumnoNotas(const AlumnoNotas& orig) {
}

AlumnoNotas::~AlumnoNotas() {
}

void AlumnoNotas::leerAluNotas(ifstream& arch){
    arch>>alumno;
}

void AlumnoNotas::imprimeAluNotas(ofstream& arch){
    alumno.imprimeAlumno(arch);
    arch<<"Lista de notas: "<<endl;
    for(int i=0;i<notas.size();i++){
        notas[i].imprimeNota(arch);
    }
    arch<<endl;
}

void AlumnoNotas::operator =(const class AlumnoNotas& orig){
    alumno.SetCodigo_alumno(orig.alumno.GetCodigo_alumno());
    char cad[60];
    orig.alumno.GetNombre(cad);
    alumno.SetNombre(cad);
    alumno.SetPromedio(orig.alumno.GetPromedio());
}

void AlumnoNotas::insertarNota(class Nota& nota){
    notas.push_back(nota);
}

int AlumnoNotas::obtenerCodigo() const{
    return alumno.GetCodigo_alumno();
}