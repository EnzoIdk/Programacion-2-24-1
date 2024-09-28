/* 
 * File:   Nodo.h
 * Author: Lucas
 *
 * Created on 8 de junio de 2024, 20:59
 */

#ifndef NODO_H
#define NODO_H

#include "Ficha.h"

class Nodo {
private:
    class Ficha * ficha;
    class Nodo * siguiente;
public:
    //CONST Y DEST
    Nodo();
    //METODOS
    friend class Lista;
};

//FUNCIONES

#endif /* NODO_H */

