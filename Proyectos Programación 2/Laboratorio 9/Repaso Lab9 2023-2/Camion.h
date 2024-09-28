/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Camion.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 12:15
 */

#ifndef CAMION_H
#define CAMION_H

#include <vector>
using namespace std;

#include "Vehiculo.h"
#include "NPedido.h"

class Camion:public Vehiculo {
private:
    int ejes;
    int llantas;
    class vector<class NPedido> vdeposito; //5 como MAX
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Camion();
    Camion(const class Camion &orig);
    virtual ~Camion();
    //GETTERS Y SETTERS
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    //METODOS
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void cargaDeposito(char * codPed, int cant, double peso);
};

//FUNCIONES

#endif /* CAMION_H */

