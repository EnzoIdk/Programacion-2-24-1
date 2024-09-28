/* 
 * Proyecto:   main.cpp
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 06:40 PM
 */

#include <iostream>
#include <iomanip>

#include "Facultad.h"

using namespace std;

int main(int argc, char** argv) {
    Facultad facultad;
    facultad.leerAlumnosNotas("Alumnos-Preg01.csv","Notas-Preg01.csv");
    facultad.imprimirAlumnosNotas("PruebaAlumnosNotas.txt");
    facultad.actualizaNotas();
    facultad.imprimirAlumnosNotas("PruebaNotasActualizadas.txt");
    return 0;
}

