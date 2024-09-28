/* 
 * File:   Tesoreria.cpp
 * Author: ramir
 * 
 * Created on 7 de junio de 2024, 11:18 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Tesoreria.h"

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaalumnos(){
    aboleta.crear("Alumnos.csv");
}

void Tesoreria::actualizaboleta(){
    
}

void Tesoreria::imprimeboleta(){
    aboleta.mostrarEnOrden("ReporteDePagos.txt");
}