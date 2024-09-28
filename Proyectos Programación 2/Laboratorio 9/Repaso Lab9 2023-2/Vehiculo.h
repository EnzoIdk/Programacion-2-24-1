/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Vehiculo.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 12:13
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <fstream>
using namespace std;

class Vehiculo {
private:
    int cliente;
    char * placa;
    double maxcarga;
    double actcarga;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Vehiculo();
    Vehiculo(const class Vehiculo &orig);
    virtual ~Vehiculo();
    //GETTERS Y SETTERS
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(char* cad);
    void GetPlaca(char * cad) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    //METODOS
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void cargaDeposito(char * codPed, int cant, double peso)=0;
};

//FUNCIONES

#endif /* VEHICULO_H */

