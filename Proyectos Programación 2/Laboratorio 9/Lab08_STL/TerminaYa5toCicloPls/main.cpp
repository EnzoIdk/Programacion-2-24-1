/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 08:56 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Biblioteca.h"
using namespace std;

int main(int argc, char** argv) {
    class Biblioteca bli;
    bli.carga();
    bli.llena();
    bli.baja();
    bli.muestra();
    return 0;
}

