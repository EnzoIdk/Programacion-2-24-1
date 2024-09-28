/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: Enzo
 *
 * Created on 4 de abril de 2024, 11:35 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

bool operator >>(ifstream &arch,struct Cliente &cliente);
bool operator >>(ifstream &arch,struct Producto &producto);
bool operator >>(ifstream &arch,struct Pedido &pedido);
void operator +=(struct Cliente*,struct Pedido);
bool operator +=(struct Producto *productos,struct Pedido &pedido);
int buscarCliente(struct Cliente *,int);
int buscarProducto(struct Producto *productos,const char *codigo);
void operator <<(ofstream &arch,struct Cliente cliente);
void operator <<(ofstream &arch,struct Producto producto);
void leerClientes(ifstream &archClientes,struct Cliente *clientes);
void leerProductos(ifstream &archProductos,struct Producto *productos);
void leerPedidos(ifstream &archPedidos,struct Pedido *pedidos,struct Cliente *clientes,
        struct Producto *productos);
void emitirReporte(struct Cliente *clientes,struct Producto *productos);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);

#endif /* FUNCIONES_H */

