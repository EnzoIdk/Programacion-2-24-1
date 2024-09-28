/* 
 * File:   ListaConRegistros.h
 * Author: Lucas
 *
 * Created on 3 de mayo de 2024, 0:04
 */

#ifndef LISTACONREGISTROS_H
#define LISTACONREGISTROS_H

#include <fstream>
using namespace std;

void * leeRegistro(ifstream &arch);

int cmpRegistro(const void * datoA, const void * datoB);

void imprimeRegistro(ofstream &arch, void * registro);

#endif /* LISTACONREGISTROS_H */

