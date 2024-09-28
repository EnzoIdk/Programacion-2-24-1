/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   NLibro.h
 * Author: Lucas
 *
 * Created on 8 de julio de 2024, 07:50 PM
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include "Libro.h"

class NLibro {
private:
    class Libro * plibro;
    //
    void asignarLibro(char tipo);
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    NLibro();
    NLibro(const class NLibro &orig);
    virtual ~NLibro();
    //METODOS
    void operator =(const class NLibro &orig);
    void leer(ifstream &arch);
    double GetPeso() const;
    void imprimir(ofstream &arch) const;
    void actualiza(int aa);
};

//FUNCIONES

#endif /* NLIBRO_H */

