/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlumnosNotas.h
 * Author: margo
 *
 * Created on 8 de julio de 2024, 18:47
 */

#ifndef ALUMNOSNOTAS_H
#define ALUMNOSNOTAS_H
#include <vector>
using namespace std;
#include "Nota.h"
#include "Alumno.h"
class AlumnosNotas {
private:
    Alumno alumno;
    vector<class Nota>notas;

public:
    AlumnosNotas();
    AlumnosNotas(const AlumnosNotas& orig);
    virtual ~AlumnosNotas();
    void agregarAlumno(Alumno&);
    int codigoAlumno();
    void agregarNotas(vector<Nota>&notas);
    void impresion(ofstream&);
};
#endif /* ALUMNOSNOTAS_H */

