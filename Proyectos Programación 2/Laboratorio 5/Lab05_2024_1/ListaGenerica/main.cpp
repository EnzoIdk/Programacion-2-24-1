/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 13 de mayo de 2024, 06:57 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        


#include "BibliotecaGenerica.h"
#include "FuncionesEnteros.h"
using namespace std;

int main(int argc, char** argv) {
    void *pedidos1,*pedidos2,*pedidosFinal;
    crealista(pedidos1,leenum,"RegistroNum1.txt");
    imprimelista(pedidos1,imprimenum,"Repnum1.txt");
    crealista(pedidos2,leenum,"RegistroNum2.txt");
    imprimelista(pedidos2,imprimenum,"Repnum2.txt");
    combinalista(pedidos1,pedidos2,pedidosFinal,cmpnum);
    imprimelista(pedidosFinal,imprimenum,"RepnumFinal.txt");
    return 0;
}

