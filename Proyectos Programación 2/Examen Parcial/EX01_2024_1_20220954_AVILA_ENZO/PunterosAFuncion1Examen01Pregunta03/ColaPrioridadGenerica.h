/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaPrioridadGenerica.h
 * Author: alulab14
 *
 * Created on 14 de mayo de 2024, 10:13 AM
 */

#ifndef COLAPRIORIDADGENERICA_H
#define COLAPRIORIDADGENERICA_H

void generacola(void *&cola);
void encola(void *cola,void *dato);
int obtenerRanking(void *dato);
void crearNodo(void **&nuevoNodo,void *dato);
void *desencola(void *cola);
bool colavacia(void *cola);

#endif /* COLAPRIORIDADGENERICA_H */

