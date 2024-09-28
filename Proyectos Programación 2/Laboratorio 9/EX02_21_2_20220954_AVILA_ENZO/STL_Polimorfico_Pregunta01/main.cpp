/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 01:53 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Procesa.h"
using namespace std;

int main(int argc, char** argv) {
    class Procesa pro;
    pro.Carga();
    pro.Atiende();
    pro.Imprime();
    return 0;
}

