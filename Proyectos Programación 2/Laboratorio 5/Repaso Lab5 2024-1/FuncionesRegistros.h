/* 
 * File:   FuncionesRegistros.h
 * Author: Lucas
 *
 * Created on 7 de mayo de 2024, 17:34
 */

#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

#include <fstream>
using namespace std;

void * leeRegistro(ifstream &arch);

void imprimeRegistro(ofstream &arch, void * dato);

int cmpRegistro(const void * datoA, const void * datoB);

#endif /* FUNCIONESREGISTROS_H */

