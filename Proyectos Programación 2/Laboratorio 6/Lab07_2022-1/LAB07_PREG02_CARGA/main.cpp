/* 
 * Proyecto: LAB07_PREG02_CARGA
 * File:   main.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 10 de junio de 2022, 8:04
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Cliente.h"
#include "Pedido.h"

#include "sobrecargaOperaciones.h"
#include "funcionesSolucion.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Cliente lcliente[50];
    Pedido lpedido[150];
    
    leeclientes(lcliente);
    leepedidos(lpedido);
    
    anadirpedidos(lcliente, lpedido);
    eliminarpedido(lcliente);
    aplicardescuento(lcliente);
    
    imprimirclientes(lcliente);
    
    return 0;
}

