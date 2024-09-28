/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlumnoNotas.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 06:52 PM
 */

#ifndef ALUMNONOTAS_H
#define ALUMNONOTAS_H

#include "Alumno.h"
#include "Nota.h"

class AlumnoNotas {
public:
    AlumnoNotas();
//    AlumnoNotas(const AlumnoNotas& orig);
    virtual ~AlumnoNotas();
    
    void setAlumno(Alumno al);
    bool comparar(Alumno otro);
    int getCodigo();
    void insertarNota(Nota nota);
    void imprimir(ofstream &out);
    void actualizar();
    void totalizar();
private:
    Alumno alumno;
    vector<Nota> notas;
};

#endif /* ALUMNONOTAS_H */

