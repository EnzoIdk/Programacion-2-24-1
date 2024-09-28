/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Biblioteca.h
 * Author: Lucas
 *
 * Created on 8 de julio de 2024, 07:56 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <fstream>
#include <map>
#include <vector>
using namespace std;

#include "Estante.h"
#include "NLibro.h"

class Biblioteca {
private:
    class map<class Estante, class vector<class NLibro>> mestantes;
    //METODOS
    void cargarEstantes(ifstream &archEst, ifstream &archLib);
    void llenarEstantes(ifstream &arch, class Estante &estante);
    void imprimirLinea(ofstream &arch, char car);
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Biblioteca();
    Biblioteca(const class Biblioteca &orig);
    virtual ~Biblioteca();
    //GETTERS Y SETTERS
    //METODOS
    void carga(const char * nombEst, const char * nombLib);
    void actualiza(int aa);
    void muestra(const char * nomb);
    void prueba(double peso, const char * nomb);
};

#endif /* BIBLIOTECA_H */

