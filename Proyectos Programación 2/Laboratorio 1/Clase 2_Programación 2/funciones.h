/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: aml
 *
 * Created on 20 de marzo de 2024, 09:22 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Persona.h"

void operator *=(struct Persona &,double);
//void operator <<(ostream &,const struct Persona &);

/*<<: operador que se va a sobrecargar*/
/* &: pasar variable por referencia 
   const: no voy a modificar la variable*/

/*devolviendo la referencia*/
ostream & operator <<(ostream &,const struct Persona &);

#endif /* FUNCIONES_H */

