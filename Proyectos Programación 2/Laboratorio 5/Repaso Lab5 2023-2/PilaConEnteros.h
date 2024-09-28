/* 
 * File:   PilaConEnteros.h
 * Author: Lucas
 *
 * Created on 2 de mayo de 2024, 12:52
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

#include <fstream>
using namespace std;

void * leeNumero(ifstream &arch);

double calculaNumero(void * registro);

int cmpNumero(const void * regA, const void * regB);

void imprimeNumero(void * camion, ofstream &arch);

#endif /* PILACONENTEROS_H */

