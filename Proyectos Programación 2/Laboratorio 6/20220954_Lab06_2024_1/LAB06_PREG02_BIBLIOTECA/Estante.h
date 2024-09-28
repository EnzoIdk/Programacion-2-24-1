/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Enzo
 *
 * Created on 29 de mayo de 2024, 04:05 PM
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include <fstream>
using namespace std;
#include "Libro.h"
#include "Espacio.h"
class Estante {
private:
    char *codigo;
    int anchura;
    int altura;
    class Libro libros[10];
    class Espacio *espacios;
    int cantidad_libros;
public:
    Estante();
    virtual ~Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char*);
    void GetCodigo(char *) const;
    void InicializarEspacios();
    bool operator +=(class Libro &lib);
    void imprimirLinea(ofstream &,int,char);
    void imprimirEspacio(ofstream &,int,int);
    int EspacioDisponible(class Libro &lib);
    void imprimirLibro(ofstream &,int);
};

void operator >>(ifstream &arch,class Estante &est);
void operator <<(ofstream &arch,class Estante &est);

#endif /* ESTANTE_H */

