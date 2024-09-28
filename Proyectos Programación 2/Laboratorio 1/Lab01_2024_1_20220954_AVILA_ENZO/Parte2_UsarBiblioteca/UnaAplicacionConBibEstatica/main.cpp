/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 5 de abril de 2024, 08:06 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "BibliotecaEstatica.h"
#include "funciones.h"

int main(int argc, char** argv) {
    
    struct Libro libros[300];
    struct Cliente clientes[100];
    int numLibros,numClientes;
    ifstream archLibros,archClientes,archPedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archLibros,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Cientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.txt");
    leerLibros(archLibros,libros,numLibros);
    leerClientes(archClientes,clientes,numClientes);
    leerPedidos(archPedidos,libros,numLibros,clientes,numClientes);
    emitirReporte(libros,numLibros,clientes,numClientes);
    return 0;
}

