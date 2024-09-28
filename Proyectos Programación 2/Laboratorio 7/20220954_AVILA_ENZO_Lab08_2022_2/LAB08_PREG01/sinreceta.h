/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   sinreceta.h
 * Author: aml
 *
 * Created on 29 de mayo de 2024, 09:14 AM
 */

#ifndef SINRECETA_H
#define SINRECETA_H
#include <fstream>
using namespace std;
#include "medicamento.h"
class sinreceta:public medicamento{
public:
    sinreceta();
    virtual ~sinreceta();
    void SetNombre(const char*);
    void GetNombre(char *) const;
    void SetDni(int dni);
    int GetDni() const;
    void asignarDatos(int,int,int,int,const char*);
    void imprimir(ofstream &);
private:
    int dni;
    char *nombre;
};

#endif /* SINRECETA_H */

