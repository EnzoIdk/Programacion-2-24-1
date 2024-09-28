/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: aml
 *
 * Created on 4 de junio de 2024, 08:33 AM
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
    void crear(const char*);
    void insertar(int dato);
    void imprimir(const char *);
    void elimina();
    void imprimeR(const char *);
private:
    class Nodo *lista;
    /*se define como privado porque es recursivo y necesito acceder a sus nodos,
     sin que el usuario pueda acceder a esta, sino esta por y para sí sola*/
    void imprimeRecursivo(ofstream &arch,class Nodo *rec);
};

#endif /* LISTA_H */

