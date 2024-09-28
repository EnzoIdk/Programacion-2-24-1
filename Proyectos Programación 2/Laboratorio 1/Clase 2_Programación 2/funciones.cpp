/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Persona.h"
#include "Funciones.h"

void operator *=(struct Persona &p,double percent){
    p.sueldo*=(1+percent);
}

/*ostream: para imprimir en la pantalla*/
ostream & operator <<(ostream &out,const struct Persona &p){
    out<<setprecision(2)<<fixed;
    out<<"DNI: "<<p.dni<<endl;
    out<<"Nombre: "<<p.nombre<<endl;
    out<<"Sueldo: "<<p.sueldo<<endl;
    return out;
}

/*se hace esto para que el >> lea toda una fila en lugar de un solo dato*/
void operator >>(ifstream &arch,struct Persona &p){
    
}