/* 
 * File:   PunterosGenericos.h
 * Author: Lucas
 *
 * Created on 21 de abril de 2024, 19:28
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

void cargarProductos(const char * nombArch, void * &productos);

void * leerProducto(ifstream &arch);

char * leerCadena(ifstream &arch, char delim);

void cargaClientes(const char * nombArch, void * &clientes);

void * leerCliente(ifstream &arch);

void cargaPedidos(const char * nombArch, void * productos, void * clientes);

void leerPedido(ifstream &arch, char * &cod, int &dni, int &cant);

void procesarPedido(char * cod, int dni, int cant, void * productos, 
        void * clientes, int * numPedidos);

int buscarProductos(char * cod, void ** arrProd);

bool comparaCodigo(char * cod, void * producto);

int buscaCliente(int dni, void ** arrClientes);

bool comparaDni(int dni, void * cliente);

void agregarPedido(void * cliente, void * producto, int cant, int &numPedidos);

void finalizarPedido(void * listaCliente, int numPedidos, char * cod, int cant, 
        double total);

void * guardarPedido(char * cod, int cant, double total);

void memoriaExacta(void * clientes, int * numPedidos);

void asignarMemoriaExacta(void * cliente, int numPedidos);


#endif /* PUNTEROSGENERICOS_H */

