/* 
 * File:   funcionesCola.h
 * Author: Lucas
 *
 * Created on 1 de mayo de 2024, 17:55
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construirCola(void * &cola);


void encolar(void * cola, char categoria, int dni);

void ** crearNodo(char categoria, int dni, void * siguiente);

void * extraerSiguiente(void * nodo);

bool siguienteVacio(void * nodo);


void imprimirCola(void * cola);

void imprimeNodo(void ** recorre);

#endif /* FUNCIONESCOLA_H */

