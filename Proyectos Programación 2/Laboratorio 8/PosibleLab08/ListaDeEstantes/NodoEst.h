/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NodoEst.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 09:15 AM
 */

#ifndef NODOEST_H
#define NODOEST_H
#include "ListaEstantes.h"
#include "Libro.h"
#include "Estante.h"
class NodoEst {
private:
    class Estante *pEstante;
    class Libro *arrLibros[10];
    class NodoEst *sig;
public:
    NodoEst();
    friend class ListaEstantes;
};

#endif /* NODOEST_H */

