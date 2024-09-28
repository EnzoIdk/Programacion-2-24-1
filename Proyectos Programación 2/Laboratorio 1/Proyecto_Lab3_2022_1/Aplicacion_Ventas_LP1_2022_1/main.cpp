
/* 
 * File:   main.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 4 de enero de 2024, 12:48 AM
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estruturas.h"
#include "BibliotecaEstatica.h"
#include "Funciones.h"
#define MAX_CLI 300
#define MAX_PRO 300
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes.txt");
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.txt");
    
    struct Estructura_ClienteRegistrado clientes[MAX_CLI]{};
    int numCli = 0;
    LeerClientes(clientes,numCli,archCli);
    struct Estructura_ProductosEnAlmacen productos[MAX_PRO]{{"X"}};
    int numPro = 0;
    ProcesarProductos(clientes,numCli,productos,numPro,archPed);
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"reporte.txt");
    ImprimirReporte(clientes,numCli,productos,numPro,archRep);
    return 0;
}

