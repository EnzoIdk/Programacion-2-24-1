/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   sobrecargas.h
 * Author: margo
 *
 * Created on 4 de abril de 2024, 17:34
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H
#include "Estructuras.h"
#include <fstream>
using namespace std;
ifstream & operator >>(ifstream &arch,struct Estructura_ClienteRegistrado &cliente);
void operator += (struct Estructura_ClienteRegistrado clientes[], struct Estructura_ClienteRegistrado &cliente);
void     modificarNombre(char nombre[], char &categoria);
void operator +=(struct Estructura_ClienteRegistrado &cliente, struct Estructura_PedidoRealizado &pedido);
void operator +=(struct Estructura_ProductosEnAlmacen productos[], struct Estructura_ProductosEnAlmacen &producto);
int buscar(char cod[], struct Estructura_ProductosEnAlmacen productos[]);
void operator +=(struct Estructura_ProductosEnAlmacen productos[], struct Estructura_ProductosEnAlmacen &producto);
void operator <<(ofstream &arch, struct Estructura_ClienteRegistrado &cliente);
void operator <<(ofstream &arch, struct Estructura_ProductosEnAlmacen prod[]);

#endif /* SOBRECARGAS_H */

