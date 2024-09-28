/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 4 de abril de 2024, 07:39 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
   
using namespace std;

#include "Estructuras.h"
#include "AperturaDeArchivos.h"     
#include "Ventas_LP1_20221.h"

int main(int argc, char** argv) {

    ifstream archClientes,archPedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.txt");
//    struct Estructura_ClienteRegistrado c1,c2;
//    archClientes>>c1>>c2;
    
    return 0;
}

