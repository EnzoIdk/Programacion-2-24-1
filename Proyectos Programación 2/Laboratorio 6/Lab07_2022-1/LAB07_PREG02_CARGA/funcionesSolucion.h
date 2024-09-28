/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Proyecto: LAB07_PREG02_CARGA
 * File:   funcionesSolucion.h
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 10 de junio de 2022, 9:04
 */

#ifndef FUNCIONESSOLUCION_H
#define FUNCIONESSOLUCION_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Cliente.h"
#include "Pedido.h"

void leeclientes(Cliente *lista) ;
void leepedidos(Pedido *lista) ;

void anadirpedidos(Cliente *lcliente, Pedido *lpedido);
void eliminarpedido(Cliente *lcliente);
void aplicardescuento(Cliente *lcliente);

void imprimirclientes(Cliente *lcliente);

#endif /* FUNCIONESSOLUCION_H */
