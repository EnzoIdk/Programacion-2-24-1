/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Estante.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 21:19
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include <fstream>
#include <vector>
using namespace std;

#include "NLibro.h"

class Estante {
private:
    char clase;
    int id;
    double capacidad;
    double peso;
    class vector<class NLibro> vlibros;
    //
    void imprimirLinea(ofstream &arch, char car);
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Estante();
    Estante(const class Estante &orig);
    virtual ~Estante();
    //GETTERS Y SETTERS
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    //METODOS
    void leer(ifstream &arch);
    void operator =(const class Estante &dato);
    bool insertar(const class NLibro &libro);
    void baja();
    void muestra(ofstream &arch);
};

//FUNCIONES

#endif /* ESTANTE_H */

