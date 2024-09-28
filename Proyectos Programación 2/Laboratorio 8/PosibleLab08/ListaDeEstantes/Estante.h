/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 08:24 AM
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include <fstream>
using namespace std;
#include "Libro.h"
class Estante {
private:
    char *codigo;
    int anchura;
    int altura;
    double pesoSoportado;
    double pesoActual;
public:
    Estante();
    virtual ~Estante();
    void SetPesoActual(double pesoActual);
    double GetPesoActual() const;
    void SetPesoSoportado(double pesoSoportado);
    double GetPesoSoportado() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char*);
    void GetCodigo(char *) const;
    virtual void leeEst(ifstream &);
    virtual void imprimeEst(ofstream &);
    virtual void agregarLibro(class Libro *)=0;
};

#endif /* ESTANTE_H */

