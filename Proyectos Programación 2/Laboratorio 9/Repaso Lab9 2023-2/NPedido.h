/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   NPedido.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 12:10
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

#include <fstream>
using namespace std;

class NPedido {
private:
    char * codigo;
    int cantidad;
    double peso;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    NPedido();
    NPedido(const class NPedido &orig);
    virtual ~NPedido();
    //GETTERS Y SETTERS
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(char* cad);
    void GetCodigo(char * ) const;
    //METODOS
    void operator=(const class NPedido &orig);
    void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* NPEDIDO_H */

