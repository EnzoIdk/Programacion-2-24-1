/* 
 * File:   PilaConRegistros.h
 * Author: RODRI
 *
 * Created on 29 de abril de 2024, 02:42 PM
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H

#include "FlotaGenerica.h"
char*leeCadenaExacta(ifstream &arch,char c);
void *leeregistro(ifstream &arch);
double calcularegistro(double pesoMax,void* dato);
int cmpregistro(const void*dato1,const void *dato2);
void imprimeregistro(ofstream &arch,void *pila);


#endif /* PILACONREGISTROS_H */

