/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 7 de mayo de 2024, 10:19 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

#include "ClientesPreg1.h"
#include "FuncionesExamen01Pregunta01.h"

int main(int argc, char** argv) {
    char ***cli_NombreCategoria,**pro_Descripcion;
    int ***cli_DniTelPed,**pro_Informacion,**ped_Todo;
    CargaDeClientes(cli_DniTelPed,cli_NombreCategoria,"ClientesPreg01.csv");
    PruebaDeClientes(cli_DniTelPed,cli_NombreCategoria,"PruebaClientes01.txt");
    CargarProductosPedidos(pro_Informacion,pro_Descripcion,ped_Todo,"PedidosPreg01.csv");
    PruebaProductosPedidos(pro_Informacion,pro_Descripcion,ped_Todo,"PruebaProductosPedidos01.txt");
    ordenarPedidos(ped_Todo);
    PruebaProductosPedidos(pro_Informacion,pro_Descripcion,ped_Todo,"PruebaProductosPedidos02.txt");
    asignarPedidos(cli_DniTelPed,pro_Informacion,ped_Todo);
    PruebaProductosPedidos(pro_Informacion,pro_Descripcion,ped_Todo,"PruebaProductosPedidos03.txt");
    PruebaDeClientes(cli_DniTelPed,cli_NombreCategoria,"PruebaClientes02.txt");
    return 0;
}

