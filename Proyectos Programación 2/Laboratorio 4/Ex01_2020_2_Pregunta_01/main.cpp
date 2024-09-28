/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 24 de abril de 2024, 09:35 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    void *pedidos,*stock;
    leerDatos(pedidos,stock);
    atiende(pedidos,stock);
    imprimirDatos(pedidos);
    return 0;
}

