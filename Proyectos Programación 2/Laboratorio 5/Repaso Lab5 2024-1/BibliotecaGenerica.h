/* 
 * File:   BibliotecaGenerica.h
 * Author: Lucas
 *
 * Created on 7 de mayo de 2024, 17:33
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void crearLista(void * &pedidos, void * (*leer)(ifstream &), const char* nomb);

void insertaLista(void ** lista, void * dato);

bool listaVacia(void ** lista);

void imprimeLista(void * pedido, void (*imprimir)(ofstream &, void * ), 
        const char * nomb);

void combinaLista(void * pedidos1, void * pedidos2, void * &pedidosFinal, 
        int (*cmp)(const void *, const void *));

void * quitaLista(void ** lista);

#endif /* BIBLIOTECAGENERICA_H */

