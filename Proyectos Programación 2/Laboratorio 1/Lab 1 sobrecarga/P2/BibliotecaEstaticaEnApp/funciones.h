/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: margo
 *
 * Created on 25 de marzo de 2024, 16:38
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

using namespace std;

#include "Estructuras.h"
bool operator >>(ifstream &in, struct Cliente &C);
bool operator >>(ifstream &in, struct Pedido &p);
bool operator >>(ifstream &in, struct Producto &p);
void operator += (struct Cliente c[], struct Pedido &p);
int buscarPedido(int dni, struct Cliente c[]);
int buscarPro(char codigo[], struct Producto c[]);
bool operator +=(struct Producto pr[], struct Pedido &pe);
void operator <<(ofstream &out, struct Cliente &p);
void operator <<(ofstream &out, struct Producto &p);
void rellenarProductos(ifstream &in, struct  Producto p[]);
void rellenarClientes(ifstream &in, struct Cliente p[]);
void rellenarPedidos(ifstream &in, struct Pedido p[], struct Cliente clientes[], struct Producto productos[]);
void  impresionCliente(ofstream &archImp, struct Cliente clientes[]);
void  impresionProductos(ofstream &archImp, struct Producto productos[]);
void linea(int cant, char simb, ofstream &archImp);

#endif /* FUNCIONES_H */

