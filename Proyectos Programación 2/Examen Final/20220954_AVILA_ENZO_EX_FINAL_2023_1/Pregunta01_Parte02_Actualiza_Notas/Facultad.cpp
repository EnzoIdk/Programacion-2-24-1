/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Facultad.cpp
 * Author: Enzo
 * 
 * Created on 25 de junio de 2024, 01:08 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
using namespace std;
#include "Facultad.h"
#include "AlumnoNotas.h"
#include "Nota.h"
Facultad::Facultad() {
}

//Facultad::Facultad(const Facultad& orig) {
//}
//
//Facultad::~Facultad() {
//}
//

void Facultad::leerAlumnosNotas(const char *nombArchAlu, const char *nombArchNot){
    ifstream archAlu,archNotas;
    AperturaDeUnArchivoDeTextosParaLeer(archAlu,nombArchAlu);
    AperturaDeUnArchivoDeTextosParaLeer(archNotas,nombArchNot);
    leerAlumnos(archAlu);
    leerNotas(archNotas);
}

void Facultad::imprimirAlumnosNotas(const char *nombArch){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    arch<<setprecision(2)<<fixed;
    imprimirAlumnos(arch);
}

void Facultad::leerAlumnos(ifstream &arch){
    while(true){
        class AlumnoNotas auxAlu;
        auxAlu.leerAluNotas(arch);
        if(arch.eof()) break;
        alumnosxNotas.insertar(auxAlu);
    }
}

void Facultad::imprimirAlumnos(ofstream& arch){
    alumnosxNotas.imprimirLista(arch);
}

void Facultad::leerNotas(ifstream& arch){
    int ciclo,cod;
    while(true){
        arch>>ciclo;
        if(arch.eof()) break;
        arch.get();
        arch>>cod;
        arch.get();
        while(true){
            class Nota nota;
            arch>>nota;
            nota.asignarCiclo(ciclo);
            alumnosxNotas.cargarNota(nota,cod);
            if(arch.get()=='\n') break;
        }
    }
}

void Facultad::actualizaNotas(){
    alumnosxNotas.actualizar();
    alumnosxNotas.totalizar();
}