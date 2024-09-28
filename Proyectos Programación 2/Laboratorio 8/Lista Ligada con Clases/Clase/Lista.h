/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: Enzo
 *
 * Created on 9 de junio de 2024, 09:33 AM
 */

#ifndef LISTA_H
#define LISTA_H
#include <fstream>
using namespace std;
#include "Nodo.h"
class Lista {
public:
    Lista();
    virtual ~Lista();
    void crear(const char *nombArch);
    void insertar(const class Persona &dato);
    void imprimir(const char *nombArch);
    void elimina();
    void imprimeR(const char *nombArch);
private:
    class Nodo *lista;
    void imprimeRecursivo(ofstream &arch,class Nodo *p);
};

#endif /* LISTA_H */

