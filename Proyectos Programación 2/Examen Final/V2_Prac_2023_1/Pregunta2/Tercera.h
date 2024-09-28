/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tercera.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 08:24 PM
 */

#ifndef TERCERA_H
#define TERCERA_H

#include "CursoAlumno.h"


class Tercera:public CursoAlumno {
public:
    Tercera();
    Tercera(const Tercera& orig);
    virtual ~Tercera();
    
    void setPorcentaje(double p);
    double getPorcentaje()const;
    
    void actualiza();
    void imprime(ofstream &out);
private:
    double porcentaje;
};

#endif /* TERCERA_H */

