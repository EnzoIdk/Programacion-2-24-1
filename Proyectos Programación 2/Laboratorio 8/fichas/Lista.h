/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: margo
 *
 * Created on 11 de junio de 2024, 18:34
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include <fstream>
using namespace std;
class Lista {
private:
    class Nodo *cabeza;
    void aplicarMov(class Nodo*nod, char mov, char *fich, int cant);
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void lecturaFichar(ifstream &);
    void insertarLista(Nodo *&nodo);
    void imprimeLista(ofstream &);
    void actualizar(ifstream &);
    
};
#endif /* LISTA_H */

