/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 12:37 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <fstream>
using namespace std;

class Alumno {
private:
    int codigo_alumno;
    char *nombre;
    double promedio;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetPromedio(double promedio);
    double GetPromedio() const;
    void SetNombre(const char *cad);
    void GetNombre(char *cad) const;
    void SetCodigo_alumno(int codigo_alumno);
    int GetCodigo_alumno() const;
    void imprimeAlumno(ofstream &arch);
};

void operator >>(ifstream &arch,class Alumno &alu);

#endif /* ALUMNO_H */

