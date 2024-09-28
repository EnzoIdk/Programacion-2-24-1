/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 24 de abril de 2024, 12:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "funciones.h"

int main(int argc, char** argv) {
    void *libros,*pedidosCli,*pedidosLib;
    leerLibros("Libros.csv",libros);
    mostrarLibros("RepInicialLibros.txt",libros);
    atenderPedidos("Pedidos.txt",libros,pedidosCli,pedidosLib);
    
    return 0;
}

