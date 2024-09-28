/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Primera.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 04:39 PM
 */

#ifndef PRIMERA_H
#define PRIMERA_H
#include <fstream>
using namespace std;
#include "CursoAlumno.h"
class Primera:public CursoAlumno{
private:
    char *codacceso;
public:
    Primera();
    Primera(const Primera& orig);
    virtual ~Primera();
    void SetCodacceso(const char *cad);
    void GetCodacceso(char *cad) const;
    void lee(ifstream &arch);
    void muestra();
    void imprime(ofstream &arch);
    void actualiza();
};

#endif /* PRIMERA_H */

