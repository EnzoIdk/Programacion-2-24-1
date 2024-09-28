/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ListaDoble.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 01:08 AM
 */

#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <fstream>
using namespace std;
#include "Nodo.h"
#include "AlumnoNotas.h"
#include "Nota.h"
class ListaDoble {
private:
    class Nodo *inicio;
    class Nodo *fin;
public:
    ListaDoble();
//    ListaDoble(const ListaDoble& orig);
    virtual ~ListaDoble();
    void insertar(const class AlumnoNotas &aluNot);
    void imprimirLista(ofstream &arch);
    void cargarNota(class Nota &nota,int cod);
    void actualizar();
    void totalizar();
};

#endif /* LISTADOBLE_H */

