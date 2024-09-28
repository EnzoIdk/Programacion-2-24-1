/* 
 * File:   PilaConRegistros.h
 * Author: Lucas
 *
 * Created on 2 de mayo de 2024, 12:52
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H

#include <fstream>
using namespace std;

void * leeRegistro(ifstream &arch);

double calculaRegistro(void * registro);

int cmpRegistro(const void * datoA, const void * datoB);

void imprimeRegistro(void * registro, ofstream &arch);

void imprimePilaRegistro(void * cabeza, ofstream &arch);

#endif /* PILACONREGISTROS_H */

