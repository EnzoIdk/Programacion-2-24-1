/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 25 de abril de 2024, 17:02
 */

#include "funcionesPunterosGenericos.h"

int main(int argc, char** argv) {
    
    void * clientes, * pedidos, * libros;
    
    cargarClientes("Cientes.csv", clientes);
    imprimirClientes("ReporteClientesInicial.txt", clientes);
    
    cargarPedidos("Pedidos.csv", pedidos, clientes);
    imprmirPedidos("ReportePedidos.txt", pedidos, clientes);
    
    return 0;
}

