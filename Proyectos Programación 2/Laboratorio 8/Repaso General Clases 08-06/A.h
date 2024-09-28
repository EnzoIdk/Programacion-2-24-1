/* 
 * File:   A.h
 * Author: Lucas
 *
 * Created on 9 de junio de 2024, 12:21
 */

#ifndef A_H
#define A_H

#include "Ficha.h"

class A:public Ficha {
private:
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    A();
    A(const class A &orig);
    virtual ~A();
    //GETTERS Y SETTERS
    //METODOS
    void mover(char direccion, int casillas);
    void imprimir(std::ofstream &arch);
};

//FUNCIONES

#endif /* A_H */

