/* 
 * File:   funcionesMemoriaIncrementos.h
 * Author: alulab14
 *
 * Created on 17 de abril de 2024, 11:52 AM
 */

#ifndef FUNCIONESMEMORIAINCREMENTOS_H
#define FUNCIONESMEMORIAINCREMENTOS_H

#include <fstream>
using namespace std;

void lecturaDeLibros(const char * nombArch, char *** &libros, int ** &stock);

char ** leerLibro(ifstream &arch);

char * leerCadena(ifstream &arch, char delim);

int * leerStock(ifstream &arch);

void incrementarEspacios(char *** &libros, int ** &stock, int &cap, int &nd);

void pruebaDeLecturaDeLibros(const char* nombArch, char*** libros, int** stock);

void atencionDePedidos(const char * nombArch, char *** libros, int ** stock, 
        int ** &pedidosClientes, char *** &pedidosLibros, 
        bool ** &pedidosAtendidos);

void leerDatosPedido(ifstream &arch, int &num, int &dni);

void incrementarEspacios(int ** &pedidosClientes, int &ndClientes, 
        int &capClientes);

void incrementarEspacios(char *** &pedidosLibros, bool ** &pedidosAtendidos, 
        int num, int &capPedidos);

int buscarPersona(int dni, int ** pedidosCliente);

void agregarPersona(int dni, int * &pedidoCliente, int &capLibCli);

void procesarPedidos(ifstream &arch, char *** libros, int ** stock, 
        int * &pedidoCliente, char ** &pedidoLibro, bool * &pedidosAtendidos, 
        int &numLibrosPorPedido, int &capLibPorPed, int &capLibrPorCli, 
        int num);

int buscarLibro(char * codTemp, char *** libros);

void incrementarEspacios(char ** &pedidoLibro, bool * &pedidosAtendidos, 
        int &numLibrosPorPedido, int &capLibPorPed);

void incrementarEspacios(int * &pedidoCliente, int &capLibrPorCli);
void pruebaDePedidos(const char *nombArch,int **pedidosClientes);

#endif /* FUNCIONESMEMORIAINCREMENTOS_H */

