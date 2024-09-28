/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Facultad.h
 * Author: margo
 *
 * Created on 8 de julio de 2024, 18:48
 */

#ifndef FACULTAD_H
#define FACULTAD_H
#include "ListaDoble.h"
class Facultad {
private:
    ListaDoble alumnoxNotas;

public:
    Facultad();
    Facultad(const Facultad& orig);
    virtual ~Facultad();
    void leerAlumnosNotas(const char *, const char *);
    void insertarEnLista(int ,vector<Nota>&);
    void ImprimeAlumnosNotas(const char *nombarch);
};
#endif /* FACULTAD_H */

