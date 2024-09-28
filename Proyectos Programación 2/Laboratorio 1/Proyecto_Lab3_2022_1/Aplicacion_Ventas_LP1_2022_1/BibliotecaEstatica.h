
/* 
 * File:   BibliotecaEstatica.h
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 3 de enero de 2024, 11:57 AM
 */

#ifndef BIBLIOTECAESTATICA_H
#define BIBLIOTECAESTATICA_H

#include <iostream>
#include <fstream>
using namespace std;
#include "Estruturas.h"

ifstream & operator >>(ifstream &arch,struct Estructura_ClienteRegistrado &cliente);
void AsignarCategoria(char *categoria,char tipo);
ofstream & operator <<(ofstream &arch,const struct Estructura_ClienteRegistrado &cliente);

void ImprimirPedidos(const struct Estructura_PedidoRealizado *pedidosRealizados,
        int numeroDePedidos,ofstream &arch);
void ImprimirFecha(int fecha,ofstream &arch);

void operator +=(struct Estructura_ClienteRegistrado* arr,
        const struct Estructura_ClienteRegistrado &cliente);
void operator +=(struct Estructura_ClienteRegistrado &cliente,
        const struct Estructura_PedidoRealizado &pedido);
void operator +=(struct Estructura_ProductosEnAlmacen *arr,
        const struct Estructura_ProductosEnAlmacen &producto);

ofstream & operator <<(ofstream &arch,const struct Estructura_ProductosEnAlmacen *arr);


#endif /* BIBLIOTECAESTATICA_H */

