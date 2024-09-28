/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.h
 * Author: margo
 *
 * Created on 29 de mayo de 2024, 9:13
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include "Libro.h"
#include "Espacio.h"
#include <fstream>
using namespace std;

class Estante {
private:
    char *codigo;
    int anchura;
    int altura;
    Libro *libros;
    Espacio *espacios;
    int cant_libros;
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCant_libros(int cant_libros);
    int GetCant_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
    void llenarEstante(ifstream &arch);
    bool agregarLibro(Libro &);
    bool hayEspacio(int&, int , int);
    int max();
    void pintarEspacio(int , int , int);
     void impresionEstante(ofstream &);
};
#endif /* ESTANTE_H */

