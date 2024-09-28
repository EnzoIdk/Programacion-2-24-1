/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 04:25 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include "AlumnoNota.h"
#include "Nota.h"
using namespace std;

class Alumno {
private:
    int codigo;
    char *nombre;
    int numcursos;
    int numaprobados;
    int numprimera;
    int numsegunda;
    int numtercera;
    AlumnoNota lnotas[20];
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetNumtercera(int numtercera);
    int GetNumtercera() const;
    void SetNumsegunda(int numsegunda);
    int GetNumsegunda() const;
    void SetNumprimera(int numprimera);
    int GetNumprimera() const;
    void SetNumaprobados(int numaprobados);
    int GetNumaprobados() const;
    void SetNumcursos(int numcursos);
    int GetNumcursos() const;
    void SetNombre(const char*);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator +=(class Nota &nota);
    void ImprimirCursos(ofstream &arch);
    void ObtenerDatos();
};

void operator >>(ifstream &arch,class Alumno &al);
void operator <<(ofstream &arch,class Alumno &al);

#endif /* ALUMNO_H */

