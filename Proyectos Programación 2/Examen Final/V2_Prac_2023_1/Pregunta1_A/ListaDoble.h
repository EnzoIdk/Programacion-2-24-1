/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDoble.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 06:54 PM
 */

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Nodo.h"


class ListaDoble {
public:
    ListaDoble();
//    ListaDoble(const ListaDoble& orig);
    virtual ~ListaDoble();
    
    bool listaVacia();
    void insertarLista(Alumno al);
    void insertarNota(Nota nota, int cod);
    void imprimeLista(ofstream &out);
    void actualizarNotas();
    void totalizar();
private:
    Nodo *inicio;
    Nodo *fin;
};

#endif /* LISTADOBLE_H */

