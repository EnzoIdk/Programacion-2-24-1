/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Primera.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 08:21 PM
 */

#ifndef PRIMERA_H
#define PRIMERA_H

#include "CursoAlumno.h"


class Primera:public CursoAlumno {
public:
    Primera();
    Primera(const Primera& orig);
    virtual ~Primera();
    
    void setCodAcceso(char *cad);
    void getCodAcceso(char *cad);
    
    void imprime(ofstream &out);
private:
    char *codacceso;
};

#endif /* PRIMERA_H */

