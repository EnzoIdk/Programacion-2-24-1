/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: margo
 *
 * Created on 25 de marzo de 2024, 17:11
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funciones.h"

int main(int argc, char** argv) {

    ifstream archCli;
    //Cliente
    AperturaDeUnArchivoDeTextosParaLeer(archCli, "Clientes.csv");
    struct Cliente clientes[200];
    rellenarClientes(archCli, clientes);
    
      ifstream archPro;
     //Producto
     AperturaDeUnArchivoDeTextosParaLeer(archPro, "Productos.csv");
     struct Producto productos[200];
     rellenarProductos(archPro, productos);

      ifstream archPed;
     //Pedido
     AperturaDeUnArchivoDeTextosParaLeer(archPed, "Pedidos.csv");
     struct Pedido pedidos[600];
     rellenarPedidos(archPed, pedidos, clientes, productos);
     
     ofstream archImp;
      AperturaDeUnArchivoDeTextosParaEscribir(archImp, "ImpresionFinal.txt");
      
      impresionCliente(archImp, clientes);
      impresionProductos(archImp, productos);
      
    return 0;
}

