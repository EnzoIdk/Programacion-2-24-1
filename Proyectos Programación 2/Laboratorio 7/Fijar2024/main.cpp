/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: margo
 *
 * Created on 29 de mayo de 2024, 9:12
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

#include "Biblioteca.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Biblioteca biblioteca;
    biblioteca.cargarLibros();
    biblioteca.cargarEstantes();
    biblioteca.agregarLibros();
    biblioteca.impresion();
    
    return 0;
}

