/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Estante.h
 * Author: Lucas
 *
 * Created on 8 de julio de 2024, 07:53 PM
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include <fstream>
using namespace std;

class Estante {
private:
    int id;
    double capacidad;
    double disponible;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Estante();
    Estante(const class Estante &orig);
    virtual ~Estante();
    //GETTERS Y SETTERS
    void SetDisponible(double disponible);
    double GetDisponible() const;
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    //METODOS
    void operator =(const class Estante &orig);
    bool operator ==(const class Estante &orig) const;
    bool operator <(const class Estante &orig) const;
    void leer(ifstream &arch);
    void actualizar(double peso);
    void imprimir(ofstream &arch) const;
};

//FUNCIONES

#endif /* ESTANTE_H */

