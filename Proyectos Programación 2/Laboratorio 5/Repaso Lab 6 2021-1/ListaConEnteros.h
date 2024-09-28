/* 
 * File:   ListaConEnteros.h
 * Author: Lucas
 *
 * Created on 3 de mayo de 2024, 0:03
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

#include <fstream>
using namespace std;

void * leeNum(ifstream &arch);

int cmpNum(const void * datoA, const void * datoB);

#endif /* LISTACONENTEROS_H */

