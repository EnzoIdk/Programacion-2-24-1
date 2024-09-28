/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: alulab14
 *
 * Created on 14 de junio de 2024, 08:06 AM
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
public:
    Lista();
    virtual ~Lista();
    void elimina();
    int insertarLibro(class Libro *&libro,double);
    void actualizarLista();
    void imprimeLista(ofstream &);
};

#endif /* LISTA_H */

