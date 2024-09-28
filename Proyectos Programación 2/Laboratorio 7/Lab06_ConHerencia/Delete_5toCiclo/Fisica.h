/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Fisica.h
 * Author: Enzo
 *
 * Created on 30 de mayo de 2024, 10:32 PM
 */

#ifndef FISICA_H
#define FISICA_H

#include <fstream>
using namespace std;
#include "Libro.h"

class Fisica:public Libro{
private:
    char *profesor;
public:
    Fisica();
    virtual ~Fisica();
    void SetProfesor(const char*);
    void GetProfesor(char *) const;
    void leerDatos(ifstream &);
};

#endif /* FISICA_H */

