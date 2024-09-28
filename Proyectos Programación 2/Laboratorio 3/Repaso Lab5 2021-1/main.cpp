/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 18 de abril de 2024, 17:08
 */

#include "funcionesMemoriaDinamica.h"

int main(int argc, char** argv) {
    
    char ** conductor, *** placa;
    int * licencia, ** falta;
    double ** multa;
    
    cargarConductores("Conductores.csv", licencia, conductor);
    reporteConductores("ReporteConductores.txt", licencia, conductor);
    
    cargarFaltas("RegistroDeFaltas.csv", licencia, placa, falta);
    reporteFaltas("ReporteFaltas.txt", licencia, conductor, placa, falta);
    
    resumenMultas("Infracciones.csv", licencia, falta, multa);
    reporteMultas("ReporteMultas.txt", licencia, conductor, multa);
    
    return 0;
}

