
/* 
 * File:   main.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 3 de enero de 2024, 11:21 AM
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estruturas.h"
#include "BibliotecaEstatica.h"
#define MAX_CLIE 100
#define MAX_PROD 100
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes.txt");
    struct Estructura_ClienteRegistrado C1,C2;
    archCli>>C1>>C2;
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"Reporte.txt");
    archRep.precision(2);
    archRep<<fixed;
    archRep<<C2;
    struct Estructura_ClienteRegistrado clientes[MAX_CLIE]{};
    clientes += C1;
    archRep<<clientes[0];
    struct Estructura_PedidoRealizado Ped1;
    strcpy(Ped1.codigo,"LVO823");
    Ped1.cantidad = 0.17;
    Ped1.precioUnitario = 13.81;
    Ped1.descuento = 2.0;
    Ped1.fecha = 20191018;
    C1 += Ped1;
    archRep<<C1;
    struct Estructura_ProductosEnAlmacen Pro1,productos[MAX_PROD]{{"X"}};
    strcpy(Pro1.codigo,"LVO823");
    strcpy(Pro1.descripcion,"TE_DE_MANZANILLA_NEBO_24_1GR");
    Pro1.descuento = 0.0;
    Pro1.precioUnitario = 13.81;
    productos += Pro1;
    Pro1.descuento = 1.0;
    productos += Pro1;
    Pro1.descuento = 2.0;
    productos += Pro1;
    archRep<<productos;
    return 0;
}

