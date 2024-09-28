/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   C.h
 * Author: Enzo
 *
 * Created on 7 de junio de 2024, 09:41 AM
 */

#ifndef C_H
#define C_H
#include <fstream>
using namespace std;
#include "Ficha.h"
class C:public Ficha{
public:
    void imprime(ofstream &);
    void mover(char,int);
};

#endif /* C_H */

