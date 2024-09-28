/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 7 de mayo de 2024, 17:32
 */

#include <iostream>
using namespace std;

#include "BibliotecaGenerica.h"
#include "FuncionesEnteras.h"
#include "FuncionesRegistros.h"

int main(int argc, char** argv) {
    
    void * pedidos1, * pedidos2, * pedidosFinal;
    
    crearLista(pedidos1, leeNum, "RegistroNum1.txt");
    imprimeLista(pedidos1, imprimeNum, "RepNum1.txt");
    crearLista(pedidos2, leeNum, "RegistroNum2.txt");
    imprimeLista(pedidos2, imprimeNum, "RepNum2.txt");
    combinaLista(pedidos1, pedidos2, pedidosFinal, cmpNum);
    imprimeLista(pedidosFinal, imprimeNum, "RepNumFinal.txt");
    
    crearLista(pedidos1, leeRegistro, "Pedidos31.csv");
    imprimeLista(pedidos1, imprimeRegistro, "RepReg1.txt");
    crearLista(pedidos2, leeRegistro, "Pedidos32.csv");
    imprimeLista(pedidos2, imprimeRegistro, "RepReg2.txt");
    combinaLista(pedidos1, pedidos2, pedidosFinal, cmpRegistro);
    imprimeLista(pedidosFinal, imprimeRegistro, "RepRegFinal.txt");
    
    return 0;
}

