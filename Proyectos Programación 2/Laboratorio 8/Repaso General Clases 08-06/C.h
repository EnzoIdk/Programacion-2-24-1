/* 
 * File:   C.h
 * Author: Lucas
 *
 * Created on 9 de junio de 2024, 14:10
 */

#ifndef C_H
#define C_H

#include "Ficha.h"

class C:public Ficha {
private:
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    C();
    C(const class C &orig);
    virtual ~C();
    //GETTERS Y SETTERS
    //METODOS
    void imprimir(std::ofstream &arch);
    void mover(char direccion, int casillas);
};

//FUNCIONES

#endif /* C_H */

