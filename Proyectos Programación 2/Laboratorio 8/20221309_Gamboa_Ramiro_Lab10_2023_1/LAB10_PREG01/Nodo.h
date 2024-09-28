/* 
 * File:   Nodo.h
 * Author: ramir
 *
 * Created on 7 de junio de 2024, 11:13 AM
 */

#ifndef NODO_H
#define NODO_H

#include "Nodo.h"
#include "Boleta.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Arbol; //Nodo piensa que es amigo de Arbol
private:
    Boleta dboleta;
    Nodo *izq;
    Nodo *der;
};

#endif /* NODO_H */

