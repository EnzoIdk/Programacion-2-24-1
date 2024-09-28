/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 24 de junio de 2024, 09:43 AM
 */

#include <iomanip>
#include <iostream>
#include "Biblioteca.h"
using namespace std;

int main(int argc, char** argv) {
    Biblioteca bli;
    bli.carga();
    bli.muestra();
    bli.prueba(20);
    return 0;
}

