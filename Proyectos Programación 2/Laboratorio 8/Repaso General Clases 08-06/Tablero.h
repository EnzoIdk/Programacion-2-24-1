/* 
 * File:   Tablero.h
 * Author: Lucas
 *
 * Created on 9 de junio de 2024, 12:46
 */

#ifndef TABLERO_H
#define TABLERO_H

#include "Lista.h"

class Tablero {
private:
    //ATRIBUTOS
    class Lista lista;
    //METODOS
    void colocarFicha(char * id, char tipo, int fila, int columna);
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Tablero();
    Tablero(const class Tablero &orig);
    virtual ~Tablero();
    //GETTERS Y SETTERS
    //METODOS
    void leerFichas(const char * nomb);
    void leerMovimientos(const char * nomb);
    void imprimirFichas(const char * nomb);
};

//FUNCIONES

#endif /* TABLERO_H */

