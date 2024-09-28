/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 08:59 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Cliente.h"
#include "Libro.h"
#include "LibroPedido.h"
#include "Superclase.h"
#include "AperturaDeArchivos.h"

using namespace std;

int main(int argc, char** argv) {
    class Superclase abc;
    abc.cargarLibros();
    abc.cargarClientes();
    abc.leerPedidos();
    abc.emitirReporte();
    return 0;
}

