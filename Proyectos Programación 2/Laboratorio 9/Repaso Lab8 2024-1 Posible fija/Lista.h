/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Lista.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 18:55
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
    void operator =(const class Lista &orig);
    void insertar(class Libro * temp);
    void baja(int aa);
    void muestra(ofstream &arch);
};

//FUNCIONES

#endif /* LISTA_H */

