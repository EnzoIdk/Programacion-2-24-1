/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Administrativo.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 02:07 PM
 */

#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include <fstream>
#include "Usuario.h"
using namespace std;

class Administrativo:public Usuario{
private:
    char *area;
public:
    Administrativo();
    virtual ~Administrativo();
    void SetArea(const char *cad);
    void GetArea(char *cad) const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* ADMINISTRATIVO_H */

