/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 04:24 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Alumno.h"
#include "AlumnoNota.h"
#include "Nota.h"

using namespace std;

int main(int argc, char** argv) {
    class Alumno al;
    class AlumnoNota alNota;
    class Nota nota;
    ifstream archAlu("Alumnos.csv",ios::in);
    ifstream archNot("Notas.csv",ios::in);
    archAlu>>al;
    archNot>>alNota;
    alNota&nota;
    al+=nota;
    ofstream archRep("RepSimple.txt",ios::out);
    archRep<<al;
    return 0;
}

