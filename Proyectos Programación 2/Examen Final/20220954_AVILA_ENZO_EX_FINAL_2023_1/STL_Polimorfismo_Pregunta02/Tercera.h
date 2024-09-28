/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tercera.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 04:40 PM
 */

#ifndef TERCERA_H
#define TERCERA_H
#include <fstream>
using namespace std;
#include "CursoAlumno.h"
class Tercera:public CursoAlumno{
private:
    double porcentaje;
public:
    Tercera();
    Tercera(const Tercera& orig);
    virtual ~Tercera();
    void SetPorcentaje(double porcentaje);
    double GetPorcentaje() const;
    void actualiza();
    void imprime(ofstream &arch);
};

#endif /* TERCERA_H */

