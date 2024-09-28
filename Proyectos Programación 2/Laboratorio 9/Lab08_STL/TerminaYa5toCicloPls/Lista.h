/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 09:26 PM
 */

#ifndef LISTA_H
#define LISTA_H
#include <fstream>
using namespace std;
#include "Nodo.h"
#include "Libro.h"
class Lista {
private:
    double peso;
    class Nodo *ini;
    class Nodo *fin;
public:
    Lista();
    virtual ~Lista();
    void setPeso(double peso);
    double getPeso() const;
    void insertar(class Libro *auxLib);
    void imprimeLista(ofstream &arch);
    void actualizaLista();
    void eliminar();
};

#endif /* LISTA_H */

