/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Vehiculo.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 12:22 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <fstream>
using namespace std;

#include "NPedido.h"

class Vehiculo {
public:
    Vehiculo();
    virtual ~Vehiculo();
    
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(char * cad);
    void GetPlaca(char * cad) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    void crearPedido(char * idPed, int cantTemp, double pesoTemp);
    void imprimePedidos(ofstream &arch);
private:
    int cliente;
    char * placa;
    double maxcarga;
    double actcarga;
    class NPedido * ped; //PILA
};

#endif /* VEHICULO_H */

