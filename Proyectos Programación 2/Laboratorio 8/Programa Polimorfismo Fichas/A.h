/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   A.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2024, 12:23 PM
 */

#ifndef A_H
#define A_H
#include <fstream>
using namespace std;
#include "Ficha.h"
class A:public Ficha {
public:
    void imprime(ofstream &);
    void mover(char,int);
};

#endif /* A_H */

