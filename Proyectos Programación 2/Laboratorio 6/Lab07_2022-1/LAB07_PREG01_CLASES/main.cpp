/* 
 * Proyecto: LAB07_PREG01_CLASES
 * File:   main.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 10 de junio de 2022, 8:03
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Cliente.h"
#include "Pedido.h"

#include "sobrecargaOperaciones.h"

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archCli("clientes2.csv",ios::in);
    if(!archCli){
        cout << "No se puede abrir los clientes2";
        exit(1);
    }
    
    ofstream archRepCli("reporteClientes.txt",ios::out);
    if(!archRepCli){
        cout << "No se pudo abrir las reporteClientes ";
        exit(1);
    }
    
    ifstream archPed("pedidos2.csv",ios::in);
    if(!archPed){
        cout << "No se puede abrir los pedidos2";
        exit(1);
    }
    
    ofstream archRepPed("reportePedidos.txt",ios::out);
    if(!archRepPed){
        cout << "No se pudo abrir las reportePedidos ";
        exit(1);
    }
    
    Cliente cliente01;
    Pedido pedido01;
    
    archCli >> cliente01;
    archPed >> pedido01;
    
    cliente01 = pedido01;
    cliente01 -= pedido01;
    cliente01 / 25;
    
    archRepCli << cliente01;
    
    
    return 0;
}

