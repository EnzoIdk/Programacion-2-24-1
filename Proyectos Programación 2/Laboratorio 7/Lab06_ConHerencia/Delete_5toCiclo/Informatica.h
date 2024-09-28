/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Informatica.h
 * Author: Enzo
 *
 * Created on 30 de mayo de 2024, 10:32 PM
 */

#ifndef INFORMATICA_H
#define INFORMATICA_H
#include <fstream>
using namespace std;
#include "Libro.h"
class Informatica:public Libro{
private:
    char *curso;
public:
    Informatica();
    virtual ~Informatica();
    void SetCurso(const char *);
    void GetCurso(char *) const;
    void leerDatos(ifstream &);
};

#endif /* INFORMATICA_H */

