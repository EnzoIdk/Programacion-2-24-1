/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 14 de junio de 2024, 08:03 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Biblioteca.h"
int main(int argc, char** argv) {
    Biblioteca bli;
    bli.carga();
    bli.llena();
    bli.baja();
    bli.muestra();
    return 0;
}

