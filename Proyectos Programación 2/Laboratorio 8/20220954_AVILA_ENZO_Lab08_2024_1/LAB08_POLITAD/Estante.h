/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 08:06 AM
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include <fstream>
using namespace std;
#include "Lista.h"
#include "Libro.h"
class Estante {
private:
    char clase;
    int id;
    double capacidad;
    class Lista Llibros;
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    void leerEst(ifstream &);
    int llenarLibro(class Libro *&);
    void actualizarVigencia();
    void imprimirEstante(ofstream &);
    void imprimirLinea(ofstream &,int,char);
};

#endif /* ESTANTE_H */

