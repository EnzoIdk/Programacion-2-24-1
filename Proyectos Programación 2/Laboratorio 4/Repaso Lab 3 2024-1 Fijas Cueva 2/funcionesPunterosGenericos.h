/* 
 * File:   funcionesPunterosGenericos.h
 * Author: Lucas
 *
 * Created on 25 de abril de 2024, 17:31
 */

#ifndef FUNCIONESPUNTEROSGENERICOS_H
#define FUNCIONESPUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

//CARGA INICIAL DE CLIENTES
void cargarClientes(const char * nombArch, void * &clientes);

void * leerCliente(ifstream &arch);

char * leerCadena(ifstream &arch, char delim);

void * memoriaExacta(void ** buffer, int numDatos);

//IMPRESION DE CLIENTES
void imprimirClientes(const char * nombArch, void * clientes);
    
void imprimeCliente(ofstream &arch, void * cliente);

//CARGA DE PEDIDOS
void cargarPedidos(const char * nombArch, void * &pedidos, void * clientes);

void leerPedido(ifstream &arch, int &num, int &dni, char * &cod);

void * generarPedido(int dni, char * cod, void * clientes, int num);

int buscarCliente(int dni, void ** arrClientes);

bool comparaCliente(int dni, void * cliente);

void guardarDatos(void ** pedido, char * cod, void * cliente, int num);

void guardarLibrosExactos(void ** buffPedidos);

void finalizarExacto(void * pedido);

//IMPRESION DE PEDIDOS
void imprmirPedidos(const char * nombArch, void * pedidos, void * clientes);

void imprimePedido(ofstream &arch, void * cliente, void ** arrPedidos);

bool encuentraPedido(int dni, void * pedido);

void imprimePedido(ofstream &arch, void * pedido);

void imprimeLibroPedido(ofstream &arch, void * libro);

void imprimirLinea(ofstream &arch, int largo, char car);

#endif /* FUNCIONESPUNTEROSGENERICOS_H */

