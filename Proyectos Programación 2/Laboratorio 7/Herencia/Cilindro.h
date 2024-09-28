/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cilindro.h
 * Author: aml
 *
 * Created on 21 de mayo de 2024, 09:30 AM
 */

#ifndef CILINDRO_H
#define CILINDRO_H
#include "Circulo.h"

class Cilindro:public Circulo { /*así se pasa por herencia*/
public:
    Cilindro();
    Cilindro(const char *nomb,double rad,double alt);
//    Cilindro(const Cilindro& orig); /*esto ya no va*/
    virtual ~Cilindro();
    void SetAltura(double altura);
    double GetAltura() const;
    double area(); /*sobreescribiendo el área del círculo*/
    double volumen();
    void mostrarResultados(); /*sobreescribiendo*/
private:
    double altura;
};

#endif /* CILINDRO_H */

