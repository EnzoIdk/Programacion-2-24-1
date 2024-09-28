/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 12 de mayo de 2024, 08:11 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "funcionesCola.h"

int main(int argc, char** argv) {
    void *cola;
    construirCola(cola);
    encolar(cola, 'N', 71337111);
    encolar(cola, 'V', 12567891);
    encolar(cola, 'C', 66611166);
    encolar(cola, 'V', 22165455);
    encolar(cola, 'V', 66548422);
    encolar(cola, 'N', 71665444);
    encolar(cola, 'V', 54154777);
    encolar(cola, 'C', 82517891);
    encolar(cola, 'N', 22687891);
    imprimirCola(cola);
    return 0;
}

