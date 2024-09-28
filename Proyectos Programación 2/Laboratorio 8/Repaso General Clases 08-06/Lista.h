/* 
 * File:   Lista.h
 * Author: Lucas
 *
 * Created on 8 de junio de 2024, 21:00
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
private:
    class Nodo * cabeza;
public:
    //CONST Y DEST
    Lista();
    virtual ~Lista();
    //GETTERS Y SETTERS
    //METODOS
    void insertar(class Ficha * ficha);
    void moverFicha(char * id, char direccion, int casillas);
    void imprimir(std::ofstream &arch);
    void eliminar();
};

//FUNCIONES

#endif /* LISTA_H */

