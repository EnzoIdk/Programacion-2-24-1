/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de diciembre de 2020, 08:42 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaPacientes.h"
using namespace std;

int main(int argc, char** argv) {
    ListaPacientes l;
    l.creaLista("AtencionDeCitas.csv");
    l.imprimeLista("Reporte.txt");
    return (EXIT_SUCCESS);
}
