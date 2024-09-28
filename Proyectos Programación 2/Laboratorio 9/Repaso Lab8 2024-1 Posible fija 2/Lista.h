/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Lista.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 21:17
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
private:
    double peso;
    class Nodo * ini;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Lista();
    Lista(const class Lista &orig);
    virtual ~Lista();
    //GETTERS Y SETTERS
    void SetPeso(double peso);
    double GetPeso() const;
    //METODOS
    void insertar(const class Estante &dato);
    bool agregarLibro(const class NLibro &libro);
    void baja();
    void muestra(ofstream &arch);
    void eliminar();
};

//FUNCIONES

#endif /* LISTA_H */

