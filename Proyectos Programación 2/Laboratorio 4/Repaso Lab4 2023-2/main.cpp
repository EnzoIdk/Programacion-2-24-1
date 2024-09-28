/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 21 de abril de 2024, 17:59
 */

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

int main(int argc, char** argv) {
    
    void * productos, * clientes;
    
    cargarProductos("Productos2.csv", productos);
    imprimeProductos("ProductosIncial.txt", productos);
    
    cargaClientes("Clientes2.csv", clientes);
    imprimeClientes("ClientesInicial.txt", clientes);
    
    cargaPedidos("Pedidos2.csv", productos, clientes);
    
    imprimeReporte("ReporteFinal.txt", clientes);
    
    
    return 0;
}

