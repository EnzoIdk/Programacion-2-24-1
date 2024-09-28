/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.h
 * Author: margo
 *
 * Created on 20 de junio de 2024, 7:47
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include "Libro.h"
#include "ptrLibro.h"
#include "LLibros.h"
#include <vector>
#include <fstream>
using namespace std;

class Estante {
private:
    char clase;
    int id;
    double capacidad;
    double actCapacidad;
    LLibros listaLibros;
public:
    Estante();
    Estante(char , int ,double);
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    void setear(char, int , double);
    void SetActCapacidad(double actCapacidad);
    double GetActCapacidad() const;
    void impresion();
    void insertarLista(Libro *&libro);
    void operator --(int);
    void impresionEstante(ofstream &);
    void impresionLibros(ofstream &);
};
void operator <<(ofstream &, Estante &est);
bool operator +=(Estante&estante,  Libro *&libro);
#endif /* ESTANTE_H */

