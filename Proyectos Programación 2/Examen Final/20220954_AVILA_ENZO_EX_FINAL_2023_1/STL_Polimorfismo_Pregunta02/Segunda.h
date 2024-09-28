/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Segunda.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 04:39 PM
 */

#ifndef SEGUNDA_H
#define SEGUNDA_H
#include <fstream>
using namespace std;
#include "CursoAlumno.h"
class Segunda:public CursoAlumno{
private:
    double creditos;
public:
    Segunda();
    Segunda(const Segunda& orig);
    virtual ~Segunda();
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void actualiza();
    void imprime(ofstream &arch);
};

#endif /* SEGUNDA_H */

