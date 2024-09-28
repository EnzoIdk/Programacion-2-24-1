/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 08:25 PM
 */

#ifndef NOTA_H
#define NOTA_H

#include "CursoAlumno.h"


class Nota {
public:
    Nota();
    Nota(const Nota& orig);
    virtual ~Nota();
    
    void leer(ifstream &in);
    void operator=(const Nota &otro);
    bool operator<(const Nota &otro);
    void getCurso(char *cad);
    int getCodigo();
    void actualizar(const Nota &nota);
    void imprimir(ofstream &out);
private:
    CursoAlumno *pnota;
};

#endif /* NOTA_H */

