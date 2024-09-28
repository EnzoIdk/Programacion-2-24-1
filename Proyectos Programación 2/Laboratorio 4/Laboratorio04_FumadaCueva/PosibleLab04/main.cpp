/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de abril de 2024, 12:52 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "AperturaDeArchivos.h"
#include "funciones.h"

int main(int argc, char** argv) {
    void *clientes,*libros;
    leerLibros("Libros.csv",libros);
    leerClientes("Cientes.csv",clientes);
    imprimirClientes("RepInicialClientes.txt",clientes);
    analizarPedidos("Pedidos.txt",libros,clientes);
    imprimirClientes("RepFinalClientes.txt",clientes);
    return 0;
}

