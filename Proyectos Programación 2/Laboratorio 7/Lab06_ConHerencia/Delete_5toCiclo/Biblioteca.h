/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Enzo
 *
 * Created on 30 de mayo de 2024, 10:32 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Estante.h"
#include "Fisica.h"
#include "Calculo.h"
#include "Informatica.h"
class Biblioteca {
private:
    class Estante estantes[10];
    int cantidad_estantes;
    class Fisica librosF[10];
    class Informatica librosI[10];
    class Calculo librosC[10];
    int cant_LibrosF;
    int cant_LibrosI;
    int cant_LibrosC;
public:
    Biblioteca();
    void SetCant_LibrosC(int cant_LibrosC);
    int GetCant_LibrosC() const;
    void SetCant_LibrosI(int cant_LibrosI);
    int GetCant_LibrosI() const;
    void SetCant_LibrosF(int cant_LibrosF);
    int GetCant_LibrosF() const;
    void SetCantidad_estantes(int cantidad_estantes);
    int GetCantidad_estantes() const;
};

#endif /* BIBLIOTECA_H */

