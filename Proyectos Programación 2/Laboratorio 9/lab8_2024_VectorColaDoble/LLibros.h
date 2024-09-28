/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LLibros.h
 * Author: margo
 *
 * Created on 20 de junio de 2024, 20:01
 */

#ifndef LLIBROS_H
#define LLIBROS_H
#include "Libro.h"
class LLibros {
private:
    class Nodo* cabeza;
    double peso;
    class Nodo *fin;
public:
    LLibros();
    LLibros(const LLibros& orig);
    virtual ~LLibros();
    void insertarNuevoNodo( Libro *&libro);
    void setPeso(double peso);
    double getPeso() const;
    void actualizaLibros();
    void impresionLista(ofstream&);
};
#endif /* LLIBROS_H */

