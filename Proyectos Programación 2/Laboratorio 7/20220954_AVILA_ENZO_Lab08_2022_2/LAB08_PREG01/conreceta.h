/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   conreceta.h
 * Author: aml
 *
 * Created on 29 de mayo de 2024, 09:03 AM
 */

#ifndef CONRECETA_H
#define CONRECETA_H
#include <fstream>
using namespace std;
#include "medicamento.h"
class conreceta:public medicamento{
public:
    conreceta();
    virtual ~conreceta();
    void SetEspecialidad(const char*);
    void GetEspecialidad(char *) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    void asignarDatos(int,int,int,int,const char*);
    void imprimir(ofstream &);
private:
    int codmed;
    char *especialidad;
};

#endif /* CONRECETA_H */

