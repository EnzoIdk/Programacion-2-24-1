/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: margo
 *
 * Created on 8 de julio de 2024, 18:41
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
    void SetNombre(char* nombre);
    void GetNombre(char *) const;
    void SetCodigo_alumno(int codigo_alumno);
    int GetCodigo_alumno() const;

};
void operator >>(ifstream &, Alumno &);
void operator <<(ofstream&, Alumno &);
#endif /* ALUMNO_H */

