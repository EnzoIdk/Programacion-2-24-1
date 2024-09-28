/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 02:51 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Programacion.h"
using namespace std;

int main(int argc, char** argv) {
    Programacion pro;
    pro.cargavehiculos();
    pro.cargaprogramacion();
    pro.reducevehiculos(10);
    pro.muestraprogramacion();
    return 0;
}

