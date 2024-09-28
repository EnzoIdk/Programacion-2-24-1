/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Vehiculo.h
 * Author: Lucas
 *
 * Created on 7 de julio de 2024, 01:53 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <fstream>
#include <string>
using namespace std;

class Vehiculo {
private:
    int dni;
    string placa;
    double carga_maxima;
    double carga_actual;
    //
    void imprimirLinea(ofstream &arch, char car);
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Vehiculo();
    Vehiculo(const class Vehiculo &orig);
    virtual ~Vehiculo();
    //GETTERS Y SETTERS
    void SetCarga_actual(double carga_actual);
    double GetCarga_actual() const;
    void SetCarga_maxima(double carga_maxima);
    double GetCarga_maxima() const;
    void SetPlaca(string placa);
    string GetPlaca() const;
    void SetDni(int dni);
    int GetDni() const;
    //METODOS
    virtual void leer(ifstream &arch);
    virtual void mostrar(ofstream &arch);
    virtual void insertar(const class Pedido &pedido)=0;
    bool hayEspacio(double peso);
};

//FUNCIONES

#endif /* VEHICULO_H */

