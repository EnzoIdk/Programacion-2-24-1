/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Ventas_LP1_20221.h
 * Author: Enzo
 *
 * Created on 4 de abril de 2024, 07:48 PM
 */

#ifndef VENTAS_LP1_20221_H
#define VENTAS_LP1_20221_H

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Estructuras.h"

ifstream & operator>>(ifstream &arch,struct Estructura_ClienteRegistrado &cliente);
void asignarCategoria(char *categoria,char tipo);
void operator +=(struct Estructura_ClienteRegistrado *arreglo,
        struct Estructura_ClienteRegistrado &cliente);
void operator +=(struct Estructura_ClienteRegistrado &cliente,
        struct Estructura_PedidoRealizado pedido);
void operator +=(struct Estructura_ProductosEnAlmacen *arreglo,
        struct Estructura_ProductosEnAlmacen producto);
void operator <<(ofstream &arch,struct Estructura_ClienteRegistrado cliente);
void imprimirFecha(ofstream &arch,int fecha);
void operator<<(ofstream &arch,struct Estructura_ProductosEnAlmacen *arr);


#endif /* VENTAS_LP1_20221_H */

