/* 
 * File:   FlotaGenerica.h
 * Author: RODRI
 *
 * Created on 29 de abril de 2024, 02:43 PM
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
#include "FlotaGenerica.h"

void cargacamiones(void *&,const int ,const double ,void*(*lee)(ifstream &),
        double(*calcula)(double,void*),const char*);
void push(void **&,int &,void *,double(*calcula)(double,void*),
        const double ,const int);
bool pilavacia(void **);
void *casteaPila(void **&,int );
void agregarDatoPila(void **&,void **&);

void muestracamiones(void *,const int ,void(*imprime)(ofstream &,void*),const char*);
        
        
#endif /* FLOTAGENERICA_H */

