/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstring>

using namespace std;

#include "AperturaDeArchivos.h"
#include "Estruturas.h"
#include "funciones.h"

bool operator >>(ifstream &arch ,struct Estructura_ClienteRegistrado cliente){
    arch>>cliente.dni;
    if(arch.eof()) break;
    arch.get();
    arch.getline(cliente.nombre,60,',');
    arch>>cliente.telefono;
}