/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 06:45 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include "Librerias.h"


class Alumno {
public:
    Alumno();
//    Alumno(const Alumno& orig);
    virtual ~Alumno();
    
    void setCodigoAlumno(int c);
    void setNombre(char *cad);
    void setPromedio(double p);
    int getCodigoAlumno()const;
    void getNombre(char *cad)const;
    double getPromedio()const;
    
    void imprimeAlumno(ofstream &out);
private:
    int codigo_alumno;
    char *nombre;
    double promedio;
};
void operator>>(ifstream &in,Alumno &al);
#endif /* ALUMNO_H */

