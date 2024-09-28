/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 17 de abril de 2024, 11:50 AM
 */

#include "funcionesMemoriaIncrementos.h"

int main(int argc, char** argv) {
    
    char *** libros, *** pedidosLibros;
    int ** stock, ** pedidosClientes;
    bool ** pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",libros, stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt", libros, stock);
    
    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, 
            pedidosLibros, pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt", libros, stock);
    pruebaDePedidos("Prueba.txt",pedidosClientes);
//    
//    reporteDeEntregaDePedidos("ReporteDeEntregaDePedisos.txt", pedidosClientes, 
//            pedidosLibros,pedidosAtendidos);
    
    return 0;
}

