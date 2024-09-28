/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.h
 * Author: margo
 *
 * Created on 11 de junio de 2024, 18:30
 */

#ifndef TABLERO_H
#define TABLERO_H

#include "Lista.h"


class Tablero {
private:
    Lista listaPosiciones;
public:
    Tablero();
    Tablero(const Tablero& orig);
    virtual ~Tablero();
    void lecturaIncial(const char *nombarch);
    void impresion(const char *nombarch);
    void movimientos(const char*nombarch);
};
#endif /* TABLERO_H */

