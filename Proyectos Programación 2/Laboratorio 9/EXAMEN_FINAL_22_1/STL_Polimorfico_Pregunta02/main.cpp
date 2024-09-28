/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 19 de junio de 2024, 11:13 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Programa.h"
using namespace std;

int main(int argc, char** argv) {
    class Programa pro;
    pro.cargaproductos();
    pro.muestraproductos();
    return 0;
}

