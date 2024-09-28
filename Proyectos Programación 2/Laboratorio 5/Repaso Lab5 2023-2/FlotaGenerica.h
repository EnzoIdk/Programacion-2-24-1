/* 
 * File:   FlotaGenerica.h
 * Author: Lucas
 *
 * Created on 2 de mayo de 2024, 12:53
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

#include <fstream>
using namespace std;

void cargaCamiones(void * &flota, int numCamiones, double pesoMaximo, 
        void * (*leeNumero)(ifstream &), double (*calculaNumero)(void *), 
        const char * nomb);

void push(void * camion, void * dato);

bool pilaVacia(void * pila);

void muestraCamiones(void * flota, int numCamiones, 
        void (*imprimir)(void *, ofstream &), const char * nombArch);

#endif /* FLOTAGENERICA_H */

