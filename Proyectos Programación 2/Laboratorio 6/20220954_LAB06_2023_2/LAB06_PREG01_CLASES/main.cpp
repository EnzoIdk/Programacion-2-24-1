/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 22 de mayo de 2024, 10:32 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Cliente.h"
#include "Producto.h"
#include "ProductoEntregado.h"
#include "Pedido.h"

int main(int argc, char** argv) {
    ifstream archCli("Clientes.csv",ios::in);
    if(not archCli.is_open()){
        cout<<"No se abrio Clientes.csv"<<endl;
        exit(1);
    }
    ifstream archProd("Productos.csv",ios::in);
    ifstream archPed("Pedidos.csv",ios::in);
    ofstream archRepCli("ReporteClientes.txt",ios::out);
    ofstream archRepProd("ReporteProductos.txt",ios::out);
    class Cliente cli;
    class Producto prod;
    class Pedido ped1,ped2;
    ped1.SetCodigo("AABB_CC");
    ped1.SetPrecio_producto(32.4);
    ped1.SetDni_cliente(79464412);
    ped2.SetCodigo("BBAA_CC");
    ped2.SetPrecio_producto(42.4);
    ped2.SetDni_cliente(89465422);
    if(archCli>>cli){
        cli+=ped1;
        cli+=ped2;
        archRepCli<<cli;
    }
    if(archProd>>prod){
        prod+=ped1;
        prod+=ped2;
        archRepProd<<prod;
    }
    return 0;
}

