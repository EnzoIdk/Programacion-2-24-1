/* 
 * File:   B.h
 * Author: Lucas
 *
 * Created on 9 de junio de 2024, 14:10
 */

#ifndef B_H
#define B_H

#include "Ficha.h"

class B:public Ficha {
private:
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    B();
    B(const class B &orig);
    virtual ~B();
    //GETTERS Y SETTERS
    //METODOS
    void mover(char direccion, int casillas);
    void imprimir(std::ofstream &arch);
};

//FUNCIONES

#endif /* B_H */

