/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: margo
 *
 * Created on 4 de abril de 2024, 17:42
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funciones.h"
#include "sobrecargas.h"
using namespace std;
/*
 * 
 */
int main(int argc, char** argv)    {

    ifstream archCli, archPed,   archProd;
    ofstream archImp;
    AperturaDeUnArchivoDeTextosParaLeer(archCli, "clientes.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPed, "pedidos.txt");
   
    struct Estructura_ClienteRegistrado Clientes[50]{};
    struct Estructura_ProductosEnAlmacen productos[200];{}
    AperturaDeUnArchivoDeTextosParaEscribir(archImp, "Prueba.txt");
    lecturaClientes(archCli,Clientes,archImp);
    lecturaPedidos(archPed, Clientes, productos);
    archImp<<productos;
    for (int i = 0;Clientes[i].dni!=0; i++) archImp<<Clientes[i];
    
    
    return 0;
}

