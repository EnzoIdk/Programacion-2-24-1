/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   NLibro.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 21:22
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include <fstream>
using namespace std;
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
    //GETTERS Y SETTERS
    //METODOS
    void operator =(const class NLibro &orig);
    void leer(ifstream &arch);
    double GetPeso() const;
    void eliminar();
    void actualiza();
    void imprime(ofstream &arch);
};

//FUNCIONES

#endif /* NLIBRO_H */

