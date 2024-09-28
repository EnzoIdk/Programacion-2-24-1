/* 
 * File:   MuestraPunteros.h
 * Author: Lucas
 *
 * Created on 21 de abril de 2024, 19:28
 */

#ifndef MUESTRAPUNTEROS_H
#define MUESTRAPUNTEROS_H

#include <fstream>
using namespace std;

void imprimeProductos(const char * nombArch, void * productos);

void imprimirProducto(ofstream &arch, void * producto);

void imprimeClientes(const char * nombArch, void * clientes);

void imprimirCliente(ofstream &arch, void * cliente);

void imprimeReporte(const char * nombArch, void * clientes);

void imprimirLinea(ofstream &arch, int largo, char car);

void imprimirPedidosPorCliente(ofstream &arch, void *cliente);

void imprimirLista(ofstream &arch, void * lista);

void imprimePedidoParcial(ofstream &arch, void * pedido);

#endif /* MUESTRAPUNTEROS_H */

