/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 24 de marzo de 2024, 10:09 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estruturas.h"
#include "funciones.h"

int main(int argc, char** argv) {
    
    ifstream archClientes;
    struct Estructura_ClienteRegistrado cliente;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"clientes.txt");
    while(archClientes>>cliente){
        cout<<cliente.dni<endl;
    }
    return 0;
}

