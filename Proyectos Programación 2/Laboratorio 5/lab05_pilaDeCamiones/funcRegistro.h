/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcRegistro.h
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 1 de mayo de 2024, 22:42
 */

#ifndef FUNCREGISTRO_H
#define FUNCREGISTRO_H

#include <fstream>
using namespace std;

void *leeregistro(ifstream &arch);
 int calcularegistro(void *numero);
  int cmpRegistro(const void*a, const void*b);
   void  imprimeregistro(ofstream &arch,void*reg);
#endif /* FUNCREGISTRO_H */

