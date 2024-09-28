/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 09:38 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <fstream>
#include <vector>
using namespace std;
#include "Estante.h"
#include "Libro.h"
class Biblioteca {
private:
    vector<class Estante> VEstantes;
    void asignarMemoria(class Libro *&auxLib,char tipo);
    void insertarLibro(class Libro *auxLib);
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void carga();
    void llena();
    void baja();
    void muestra();
};

#endif /* BIBLIOTECA_H */

