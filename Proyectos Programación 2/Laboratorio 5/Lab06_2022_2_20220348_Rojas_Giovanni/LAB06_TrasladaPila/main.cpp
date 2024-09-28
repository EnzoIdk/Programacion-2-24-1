/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 2 de mayo de 2024, 16:00
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"

//Giovanni Rojas
//20220348

int main(int argc, char** argv) {
    void*arreglo,*pilaini,*pilafin;
    
    cargaarreglo(arreglo,cmpnumero,leenumero,"numeros.txt");
    cargapila(pilaini,arreglo);
//    imprimepila(pilaini,imprimenumero,"rep1.txt");
    muevepila(pilaini,pilafin);
    imprimepila(pilafin,imprimenumero,"repnumeros.txt");
    
    return 0;
}

