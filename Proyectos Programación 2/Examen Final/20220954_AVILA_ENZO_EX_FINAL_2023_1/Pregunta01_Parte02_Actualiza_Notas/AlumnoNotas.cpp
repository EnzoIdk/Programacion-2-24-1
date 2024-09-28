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
#include "Nota.h"

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

//elimina los cursos repetidos
void AlumnoNotas::actualizar(){
    char cod1[10],cod2[10];
    for(vector<Nota>::iterator i=notas.begin();i!=notas.end();i++){
        (*i).GetCodigo_curso(cod1);
        for(vector<Nota>::iterator j=i;j!=notas.end();j++){
            if(j!=i){
                (*j).GetCodigo_curso(cod2);
                if(strcmp(cod1,cod2)==0){
                    vector<Nota>::iterator k;
                    k=j;
                    j--;
                    (*i).SetCiclo((*k).GetCiclo());
                    (*i).SetCalificacion((*k).GetCalificacion());
                    (*i).SetVez((*i).GetVez()+1);
                    notas.erase(k);
                }
            }
        }
    }
}

void AlumnoNotas::totalizar(){
    double totalCred=0,sumaPond=0;
    for(int i=0;i<notas.size();i++){
        sumaPond+=notas[i].GetCalificacion()*notas[i].GetCreditos();
        totalCred+=notas[i].GetCreditos();
    }
    alumno.SetPromedio(sumaPond/totalCred);
}