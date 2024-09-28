/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Segunda.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 08:23 PM
 */

#ifndef SEGUNDA_H
#define SEGUNDA_H

#include "CursoAlumno.h"


class Segunda:public CursoAlumno {
public:
    Segunda();
    Segunda(const Segunda& orig);
    virtual ~Segunda();
    
    void setCreditosS(double c);
    double getCreditosS()const;
    
    void actualiza();
    void imprime(ofstream &out);
private:
    double creditos;
};

#endif /* SEGUNDA_H */

