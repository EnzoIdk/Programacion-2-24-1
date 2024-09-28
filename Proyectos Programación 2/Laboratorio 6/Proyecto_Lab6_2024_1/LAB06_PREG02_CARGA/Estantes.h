/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estantes.h
 * Author: ISA
 *
 * Created on 24 de mayo de 2024, 10:14 PM
 */

#ifndef ESTANTES_H
#define ESTANTES_H
#include <fstream>
using namespace std;
#include "Libro.h"
#include "Espacio.h"
class Estantes {
private:
    char *codigo;
    int anchura;
    int altura;
    class Libro libros[30];
    class Espacio *espacios;
    int cantidad_libros;
    
    void LlenarCoordenadas();
    int HayEspacio(class Libro &lib);
    void AnadirLibro(class Libro &lib);
public:
    Estantes();
    Estantes(const Estantes& orig);
    virtual ~Estantes();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;

    void SetCodigo(char *cad);
    void GetCodigo(char *cad) const;
    bool IsNotNullCodigo() const;
    void SetMatriz();
    void ImprimirEspacio(ofstream &arch)const;
    void GetLibroEn(int pos,class Libro &lib)const;
    bool operator += (class Libro &lib);
};


ifstream & operator>>(ifstream &arch, class Estantes &Est);
ofstream & operator<<(ofstream &arch, const class Estantes &Est);

#endif /* ESTANTES_H */

