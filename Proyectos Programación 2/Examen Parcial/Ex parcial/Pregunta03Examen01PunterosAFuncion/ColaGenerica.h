/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaGenerica.h
 * Author: Gandy Margoreth Zinanyuca Huillca
 *
 * Created on 7 de mayo de 2024, 19:07
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H

#include <fstream>
using namespace std;

void encolar(void *&cola, void*reg);
void crearCola(void *&cola);
bool colavacia(void*&cola);
void* desencolar(void *&cola);
#endif /* COLAGENERICA_H */

