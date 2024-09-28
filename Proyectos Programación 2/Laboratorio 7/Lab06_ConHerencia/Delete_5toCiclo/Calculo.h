/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Calculo.h
 * Author: Enzo
 *
 * Created on 30 de mayo de 2024, 10:32 PM
 */

#ifndef CALCULO_H
#define CALCULO_H
#include <fstream>
using namespace std;
#include "Libro.h"
class Calculo:public Libro{
private:
    int num;
public:
    Calculo();
    void SetNum(int num);
    int GetNum() const;
    void leerDatos(ifstream &);
};

#endif /* CALCULO_H */

