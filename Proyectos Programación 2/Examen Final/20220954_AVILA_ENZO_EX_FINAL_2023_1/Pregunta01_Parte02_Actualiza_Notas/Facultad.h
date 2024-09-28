/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Facultad.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 01:08 AM
 */

#ifndef FACULTAD_H
#define FACULTAD_H
#include <fstream>
using namespace std;
#include "ListaDoble.h"
class Facultad {
private:
    class ListaDoble alumnosxNotas;
    void leerAlumnos(ifstream &arch);
    void imprimirAlumnos(ofstream &arch);
    void leerNotas(ifstream &arch);
public:
    Facultad();
//    Facultad(const Facultad& orig);
//    virtual ~Facultad();
    void leerAlumnosNotas(const char *,const char *);
    void imprimirAlumnosNotas(const char *);
    void actualizaNotas();
};

#endif /* FACULTAD_H */

