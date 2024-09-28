/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: margo
 *
 * Created on 11 de junio de 2024, 18:06
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Lista.h"
#include "Tablero.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Tablero tablero;
    tablero.lecturaIncial("posi.txt");
    tablero.movimientos("movimientos.txt");
    tablero.impresion("impresionInicial.txt");
    return 0;
}

