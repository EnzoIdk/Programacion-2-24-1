
/* 
 * File:   main.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 6 de junio de 2024, 03:39 PM
 */

#include "LFalta.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    LFalta lf1,lf2;
    lf1.leer("RegistroDeFaltas1.csv");
    lf2.leer("RegistroDeFaltas2.csv");
    lf1.imprimir("Reporte1.txt");
    lf2.imprimir("Reporte2.txt");
    return 0;
}

