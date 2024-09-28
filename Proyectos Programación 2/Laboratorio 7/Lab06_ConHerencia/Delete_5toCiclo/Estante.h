/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Enzo
 *
 * Created on 30 de mayo de 2024, 10:32 PM
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include <fstream>
#include "Fisica.h"
#include "Informatica.h"
#include "Calculo.h"
#include "Espacio.h"
class Estante {
private:
    char *codigo;
    int anchura;
    int altura;
    class Fisica librosF[10];
    class Informatica librosI[10];
    class Calculo librosC[10];
    class Espacio *espacios;
    int cantidad_librosF;
    int cantidad_librosI;
    int cantidad_librosC;
public:
    Estante();
    virtual ~Estante();
    void SetCantidad_librosC(int cantidad_librosC);
    int GetCantidad_librosC() const;
    void SetCantidad_librosI(int cantidad_librosI);
    int GetCantidad_librosI() const;
    void SetCantidad_librosF(int cantidad_librosF);
    int GetCantidad_librosF() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char *cod);
    void GetCodigo(char *cod) const;
    void leerEstante(ifstream &);
    void inicializarEspacios();
    void asignarLibro(class Fisica &libro);
    void asignarLibro(class Informatica &libro);
    void asignarLibro(class Calculo &libro);
    int espacioDisp();
    void imprime(ofstream &arch);
};

#endif /* ESTANTE_H */

