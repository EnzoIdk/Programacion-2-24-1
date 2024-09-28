/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Furgon.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 12:21
 */

#ifndef FURGON_H
#define FURGON_H

#include <vector>
using namespace std;

#include "Vehiculo.h"
#include "NPedido.h"

class Furgon:public Vehiculo {
private:
    int filas;
    int puertas;
    class vector<class NPedido> vdeposito; //PILA
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Furgon();
    Furgon(const class Furgon &orig);
    virtual ~Furgon();
    //GETTERS Y SETTERS
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    //METODOS
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void cargaDeposito(char * codPed, int cant, double peso);
};

//FUNCIONES

#endif /* FURGON_H */

