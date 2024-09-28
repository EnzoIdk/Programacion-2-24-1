/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 7 de julio de 2024, 09:45 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Procesa.h"
using namespace std;

int main(int argc, char** argv) {
    Procesa pro;
    pro.carga();
    pro.muestra();
    return 0;
}

