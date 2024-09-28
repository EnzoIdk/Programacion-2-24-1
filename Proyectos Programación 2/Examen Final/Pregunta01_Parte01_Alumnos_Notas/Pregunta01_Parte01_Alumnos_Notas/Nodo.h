/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: margo
 *
 * Created on 8 de julio de 2024, 18:48
 */

#ifndef NODO_H
#define NODO_H

#include "AlumnosNotas.h"
#include "ListaDoble.h"


class Nodo {
private:
    AlumnosNotas dato;
    Nodo*siguiente;
    Nodo*anterior;
    

public:
    Nodo();
    Nodo(const Nodo& orig);
//    virtual ~Nodo();
    void agregarAlumno(Alumno&);
    int codiogAlumno();
    void imprime(ofstream&);
    void agregarNotas(vector<Nota>&notas);
    friend class ListaDoble;
    
};
#endif /* NODO_H */

