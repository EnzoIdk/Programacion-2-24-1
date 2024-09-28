/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Persona.h"

/*los operadores de aca se sobrecargan cuando se trabaje con ESTRUCTURAS(Persona), 
    en el otro caso de arreglo de enteros se opera sin ningun cambio especial*/

void operator >>(ifstream &arch,struct Persona &p){
    arch>>p.dni;
    if(arch.eof()) return;
    arch.get(); /*sacando la coma*/
    arch.getline(p.nombre,60,',');
    arch>>p.sueldo;
}

bool operator ==(int dni,struct Persona &p){
    return dni==p.dni;
}

ostream &operator <<(ostream &out,const struct Persona &p){
    out<<setprecision(2)<<fixed;
    out<<setw(8)<<p.dni<<setw(3)<<' '<<left<<setw(35)<<p.nombre<<right<<setw(10)<<
            p.sueldo<<endl;
    return out;
}