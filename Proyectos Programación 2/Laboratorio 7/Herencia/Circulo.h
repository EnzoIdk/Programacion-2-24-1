/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Circulo.h
 * Author: aml
 *
 * Created on 21 de mayo de 2024, 08:50 AM
 */

#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo {
public:
    Circulo();
    Circulo(const char *nomb,double rad);
    Circulo(const Circulo& orig);
    virtual ~Circulo();
    void SetRadio(double radio);
    double GetRadio() const;
    void SetNombre(const char *nombre);
    void GetNombre(char *nombre) const;
    void operator=(const Circulo& orig);
    double area();
    double circunferencia();
    void mostrarResultados();
private:
    double radio;
    char *nombre;
};

#endif /* CIRCULO_H */

