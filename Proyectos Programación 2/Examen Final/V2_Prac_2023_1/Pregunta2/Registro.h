/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Registro.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 08:26 PM
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include "Nota.h"


class Registro {
public:
    Registro();
//    Registro(const Registro& orig);
    virtual ~Registro();
    
    void carga();
    void procesa();
    void muestra();
private:
    vector<Nota> vregistro;
};

#endif /* REGISTRO_H */

