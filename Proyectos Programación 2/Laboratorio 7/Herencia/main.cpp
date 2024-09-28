/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 21 de mayo de 2024, 08:49 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

//#include "Circulo.h"
#include "Cilindro.h"

int main(int argc, char** argv) {
//    class Circulo cir;
//    cir.SetRadio(4.56);
//    cir.SetNombre("Circulo Solo");
//    cir.mostrarResultados();
//    class Circulo cir2=cir;
//    cir2.SetNombre("Circulo 2");
//    cir2.mostrarResultados();
//    class Cilindro cil;
    class Cilindro cil("Cilindro CP",10.67,8.45);
//    cil.SetNombre("Cilindro");
//    cil.SetRadio(8.73);
//    cil.SetAltura(10);
    cil.mostrarResultados();
    return 0;
}

