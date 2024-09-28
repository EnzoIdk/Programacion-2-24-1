/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConEnteros.h
 * Author: user
 *
 * Created on 2 de mayo de 2024, 16:57
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H
#include <fstream>
using namespace std;

void*leenumero(ifstream &arch);
int cmpnumero(const void*regA,const void*regB);
void imprimenumero(ofstream &arch,void*reg);

#endif /* PILACONENTEROS_H */

