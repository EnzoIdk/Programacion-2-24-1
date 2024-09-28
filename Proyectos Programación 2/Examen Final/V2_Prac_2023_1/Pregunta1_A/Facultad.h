/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Facultad.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 06:55 PM
 */

#ifndef FACULTAD_H
#define FACULTAD_H

#include "ListaDoble.h"


class Facultad {
public:
    Facultad();
//    Facultad(const Facultad& orig);
    virtual ~Facultad();
    
    void leerAlumnosNotas(const char* arch1, const char *arch2);
    void cargarAlumnos(ifstream &in);
    void cargarNotas(ifstream &in);
    void imprimirAlumnosNotas(const char *arch);
    void actualizaNotas();
private:
    ListaDoble alumnosxNotas;
};

#endif /* FACULTAD_H */

