/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 08:06 AM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <fstream>
using namespace std;
#include "Estante.h"
#include "Libro.h"
class Biblioteca {
private:
    class Estante AEstantes[10];
    void asignarMemoria(class Libro *&,char);
public:
    Biblioteca();
    void carga();
    void llena();
    void baja();
    void muestra();
};

#endif /* BIBLIOTECA_H */

