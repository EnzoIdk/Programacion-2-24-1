/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 08:59 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Cliente.h"
#include "Libro.h"
#include "LibroPedido.h"
#include "AperturaDeArchivos.h"

using namespace std;

int main(int argc, char** argv) {
    Cliente cli;
    Libro lib,arrLibros[300];
    LibroPedido ped,ped2;
    ifstream archCli,archLib,archPed;
    ofstream archRepCli,archRepLib;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Cientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archLib,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepLib,"RepLibros.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepCli,"ClienteSimple.txt");
    for(int i=0;archLib>>arrLibros[i];i++){
        archRepLib<<arrLibros[i];
    }
    archCli>>cli;
    ped.SetNumPedido(2);
    ped.SetCodLibro("CRY6839");
    ped2.SetNumPedido(3);
    ped2.SetCodLibro("VYG3594");
    ped>>arrLibros;
    ped2>>arrLibros;
    cli<<ped;
    cli<<ped2;
    ++cli;
    archRepCli<<cli;
    return 0;
}

