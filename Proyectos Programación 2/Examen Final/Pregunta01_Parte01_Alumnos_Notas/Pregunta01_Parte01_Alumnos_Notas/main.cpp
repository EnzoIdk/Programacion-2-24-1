/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: margo
 *
 * Created on 8 de julio de 2024, 18:34
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Alumno.h"
#include "Nota.h"
#include "AlumnosNotas.h"
#include "ListaDoble.h"
#include "Facultad.h"
/*
 * 
 */
int main(int argc, char** argv) {

    Facultad facultad;
    facultad.leerAlumnosNotas("Alumnos-Preg01.csv", "Notas-Preg01.csv");
    facultad.ImprimeAlumnosNotas("PruebaAlumnosNotas.txt");
    return 0;
}

