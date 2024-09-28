/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlumnoNotas.cpp
 * Author: Jeremy Lopez Galindo
 * 
 * Created on 4 de diciembre de 2023, 06:52 PM
 */

#include "AlumnoNotas.h"

AlumnoNotas::AlumnoNotas() {
}

//AlumnoNotas::AlumnoNotas(const AlumnoNotas& orig) {
//}

AlumnoNotas::~AlumnoNotas() {
}

void AlumnoNotas::setAlumno(Alumno al) {
    char nomb[200];
    al.getNombre(nomb);
    alumno.setCodigoAlumno(al.getCodigoAlumno());
    alumno.setPromedio(al.getPromedio());
    alumno.setNombre(nomb);
}

bool AlumnoNotas::comparar(Alumno otro) {
    char nomb1[200],nomb2[200];
    alumno.getNombre(nomb1);
    otro.getNombre(nomb2);
    if(alumno.getCodigoAlumno()> otro.getCodigoAlumno())return true;
    else if(alumno.getCodigoAlumno()== otro.getCodigoAlumno() and strcmp(nomb1,nomb2) > 0)return true;
    else return false;
}

int AlumnoNotas::getCodigo() {
    return alumno.getCodigoAlumno();
}

void AlumnoNotas::insertarNota(Nota nota) {
    notas.push_back(nota);
}

void AlumnoNotas::imprimir(ofstream& out) {
    alumno.imprimeAlumno(out);
    for(int i=0;i<120;i++)out<<"-";
    out<<endl;
    out<<setw(10)<<"CICLO"<<setw(10)<<"CODIGO"<<setw(10)<<"CREDITOS"<<setw(15)<<"CALIFICACION"<<setw(10)<<"VEZ"<<endl;
    for(int i=0;i<120;i++)out<<"-";
    out<<endl;
    for(Nota n:notas){
        n.imprimeNota(out);
    }
    for(int i=0;i<120;i++)out<<"-";
    out<<endl;
}

void AlumnoNotas::actualizar() {
    char cod1[50],cod2[50];
    for(vector<Nota>::iterator i = notas.begin(); i!=notas.end();i++){
        i->getCodigoCurso(cod1);
        for(vector<Nota>::iterator j = i; j!=notas.end();j++){
            if(i == j)continue;
            j->getCodigoCurso(cod2);
            if(strcmp(cod1,cod2) == 0){
                vector<Nota>::iterator k;
                k = j;
                j--;
                i->setCiclo(k->getCiclo());
                i->setCalificacion(k->getCalificacion());
                i->setVez(i->getVez()+1);
                notas.erase(k);
            }
        }
    }
}

void AlumnoNotas::totalizar() {
    double total = 0;
    int cont = 0;
    for(Nota n:notas){
        total += n.getCalificacion();
        cont++;
    }
    alumno.setPromedio(total/cont);
}
