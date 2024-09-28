/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: margo
 *
 * Created on 25 de marzo de 2024, 16:46
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
    ofstream archImp;
    
    //Cliente
    AperturaDeUnArchivoDeTextosParaLeer(archCli, "Cliente.csv");
    struct Cliente clientes[10];
    rellenarClientes(archCli, clientes);
    
      ifstream archPro;
     //Producto
     AperturaDeUnArchivoDeTextosParaLeer(archPro, "Producto.csv");
     struct Producto productos[10];
     rellenarProductos(archPro, productos);

      ifstream archPed;
     //Pedido
     AperturaDeUnArchivoDeTextosParaLeer(archPed, "Pedido.csv");
     struct Pedido pedidos[10];
      rellenarPedidos(archPed, pedidos);
    
      
      
      productos+=pedidos[3];
      clientes+=pedidos[3];
      
          AperturaDeUnArchivoDeTextosParaEscribir(archImp, "PruebaImpresion.txt");

      
      
      archImp<<clientes[4];
      
      archImp<<productos[4];
      
    
    return 0;
}

