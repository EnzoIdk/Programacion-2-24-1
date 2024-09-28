/* 
 * File:   BibliotecaListaGenerica.h
 * Author: Lucas
 *
 * Created on 3 de mayo de 2024, 0:03
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H

#include <fstream>
using namespace std;

void crearLista(void * &lista, void * (*leer)(ifstream &), int cmp(const void *, 
        const void *), const char * nombArch);

void insertaLista(void ** lista, void * dato, int (*cmp)(const void *, 
        const void *));

bool listaVacia(void ** lista);

void uneLista(void * lista1, void * lista2);

void imprimeLista(void * lista, void imprime(ofstream &, void * dato), 
        const char * nombArch);

void imprimeNum(ofstream &arch, void * dato);

#endif /* BIBLIOTECALISTAGENERICA_H */

