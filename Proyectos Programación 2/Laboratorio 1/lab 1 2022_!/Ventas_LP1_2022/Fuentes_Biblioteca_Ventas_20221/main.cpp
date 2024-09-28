/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: margo
 *
 * Created on 4 de abril de 2024, 15:32
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ifstream archCli, archPed, archProd;
    ofstream archImp;
    AperturaDeUnArchivoDeTextosParaLeer(archCli, "clientes.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPed, "pedidos.txt");
    struct Estructura_PedidoRealizado pedido;
    struct Estructura_ClienteRegistrado Clientes[50]{};
    struct Estructura_ProductosEnAlmacen productos[100];{}
    archCli>>Clientes[0];
    Clientes+=Clientes[0];
    Clientes[0]+=pedido;
    productos+=productos[0];
    AperturaDeUnArchivoDeTextosParaEscribir(archImp, "Prueba.txt");
    archImp<<Clientes[0];
    archImp<<productos;
    return 0;
}

