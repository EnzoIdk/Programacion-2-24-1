/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConEnteros.h
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 1 de mayo de 2024, 19:11
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

#include <fstream>
using namespace std;

void *leenumero(ifstream &arch);
void  imprimenumero(ofstream &arch,void*camion);
int cmpnumero(const void*a, const void*b);
#endif /* PILACONENTEROS_H */

