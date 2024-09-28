/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gandy zinanyuca
 * codigo: 20220256
 *
 * Created on 20 de junio de 2024, 7:36
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Biblioteca.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Biblioteca biblioteca;
    biblioteca.cargar();
    biblioteca.insertar();
    biblioteca.baja();
    biblioteca.imprimir();
    
    return 0;
}

