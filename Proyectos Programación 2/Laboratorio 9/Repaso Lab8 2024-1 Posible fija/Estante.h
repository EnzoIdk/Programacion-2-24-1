/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Estante.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 18:58
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include <fstream>
using namespace std;

#include "Lista.h"

class Estante {
private:
    char clase;
    int id;
    double capacidad;
    class Lista Llibros;
    //
    void imprimirLinea(ofstream& arch, char car);
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
    void operator =(const class Estante &orig);
    void leerDatos(ifstream &arch);
    bool insertar(class Libro * temp);
    void baja(int aa);
    void muestra(ofstream &arch);
};

//FUNCIONES

#endif /* ESTANTE_H */

