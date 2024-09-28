/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: margo
 *
 * Created on 20 de junio de 2024, 7:50
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <vector>
#include "Estante.h"
#include "ptrLibro.h"
#include <fstream>
#include <iostream>
using namespace std;

class Biblioteca {
private:
    vector<class Estante>AEstante;
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void cargar();
    void insertar();
    void baja();
    void imprimir();
    void agregarMemoriaSetear(char tip,Libro*&libro,ifstream& arch);
};

#endif /* BIBLIOTECA_H */

