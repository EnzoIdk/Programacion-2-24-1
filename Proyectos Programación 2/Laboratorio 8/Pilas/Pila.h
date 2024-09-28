/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.h
 * Author: Usuario
 *
 * Created on 5 de junio de 2024, 01:22 PM
 */

#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

#include <iostream>

using namespace std;

class Pila {
public:
    Pila();
    ~Pila();
    
    void apilar(void *dato);//pone un dato en la cima
    bool esPilaVacia();
    void *cima();//retorna una copia de la cima
    void *desapilar();//retorna el dato de la cima
    int profundidad();//retorna la cantidad de datos apilados
    void *fondo();//retorna el fondo de la pila
    void apilarAlFondo(void *dato);//apila un dato en el fondo de la pila
    void invertir();//invierte la pila 
    void duplicar(Pila &pila);//copia cada elemento en el mismo orden de la pila original
    void duplicarDoblemente(Pila &pila);//copia cada elemento 2 veces
    void imprimir(void (*funcionParaImprimir)(void *));//hace una copia de la pila para imprimir
    void concatenar(Pila &pila);//apila una pila encima de la pila original y destruye la otra pila
    void mezclar(Pila &origen1,Pila &origen2);//mezcla 2 pilas desde el fondo y las destruye
    
private:
    Nodo *cimaPila;
    int profundidadPila;
};

#endif /* PILA_H */

