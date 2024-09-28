
/*/ 
 * Projecto:  Fuentes_Biblioteca_2023_2
 * Nombre del Archivo:  main.cpp
 * Autor: El Real Candy
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "pruebasBiblioteca.h"
#define MAXCLI 200
#define MAXPROD 200
#define MAXPED 600

// Modulo Principal
int main(int argc, char** argv) {
    // Declaracion de Variables
    struct Cliente arrCli[MAXCLI];
    struct Producto arrProd[MAXPROD];
    struct Pedido arrPed[MAXPED];
    // Lectura de Datos
    obtenerDatos(arrCli,"Clientes.csv");
    obtenerDatos(arrProd,"Productos.csv");
    obtenerDatos(arrPed,"Pedidos.csv");
    // Impresion de Datos Leidos [No Procesados]
    imprimirDatos(arrCli,arrProd,arrPed,"ReporteDatosNoProcesados.txt");
    // Actualizacion de Datos   [Procesamiento de Datos]
    procesarDatos(arrCli,arrProd,arrPed);
    // Impresion de Datos Leidos [Procesados]
    imprimirDatos(arrCli,arrProd,arrPed,"ReporteDatosProcesados.txt");
    
    return 0;
}
