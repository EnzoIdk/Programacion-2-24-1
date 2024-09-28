/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 7 de mayo de 2024, 18:58
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "Pregunta01Examen01PunterosMultiples.h"
#include "Pregunta02Examen01PunterosGenericos.h"
#include "ColaConEnteros.h"
#include "ColaConProductos.h"
#include "ColaGenerica.h"

/*
 * mismas funciones
 * cuidado con los n
 * cabeza necesitaba estar apuntando a algo antes
 * impresion para la asignación de paso de void* a algo más como enteros
 * verificación de si la lista es vacía mejor no imprimirla
 */
int main(int argc, char** argv) {
    void *cola;
     char **codigoDelProducto;
    int **fechaClienteCantidad;
     void *productos;
    cargarPedidos(fechaClienteCantidad,codigoDelProducto, "pedidos.csv");
    pruebaDeCrargarDePedidos(fechaClienteCantidad, codigoDelProducto, "pruebaPedidos.txt");
    cargarProductos(productos, "productos.csv");
    pruebaDeCargaDeProductos(productos);
    cargaEnteros(cola, leenumero, "numeros.txt");
    mostrarEnteros(cola, imprimeNumero,"reporte.txt");
    procesarPedidos(fechaClienteCantidad, codigoDelProducto, productos);
    reporteDePedidos(productos, "reportefinal.txt");
    return 0;
}

