/* 
 * File:   PilaConEnteros.h
 * Author: RODRI
 *
 * Created on 29 de abril de 2024, 02:42 PM
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

#include "FlotaGenerica.h"

void* leenumero(ifstream &);
double calculanumero(double ,void* );
int cmpnumero(const void*,const void *);
void imprimenumero(ofstream &,void *);


#endif /* PILACONENTEROS_H */

