/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 5 de abril de 2024, 08:06 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "BibliotecaEstatica.h"


int main(int argc, char** argv) {

    struct Cliente c1;
    struct Libro l1;
    ifstream archClientes,archLibros,archPedidos;
    ofstream archPruebaC,archPruebaL;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Cientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archLibros,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archPruebaC,"PruebaClientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archPruebaL,"PruebaLibros.txt");
    archClientes>>c1;
    c1.cantDeLibros=1;
    c1.librosSolicitados[0].atendido=true;
    strcpy(c1.librosSolicitados[0].codigoDelLibro,"HOLA");
    c1.librosSolicitados[0].precio=12.3;
    c1.librosSolicitados[0].numeroDePedido=00001;
    ++c1;
    archPruebaC<<c1;
    archLibros>>l1;
    archPruebaL<<l1;
    while(archClientes>>c1){
        cout<<c1.nombre<<endl;
    }
    return 0;
}

