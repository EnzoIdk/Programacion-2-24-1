/* 
 * File:   FuncionesEnteras.h
 * Author: Lucas
 *
 * Created on 7 de mayo de 2024, 17:34
 */

#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H

#include <fstream>
using namespace std;

void * leeNum(ifstream &arch);

void imprimeNum(ofstream &arch, void * dato);

int cmpNum(const void * datoA, const void * datoB);


#endif /* FUNCIONESENTERAS_H */

