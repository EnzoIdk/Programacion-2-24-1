/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FunCPersona.h
 * Author: Enzo
 *
 * Created on 24 de marzo de 2024, 05:48 PM
 */

#ifndef FUNCPERSONA_H
#define FUNCPERSONA_H
#include <fstream>

using namespace std;

void operator >>(ifstream &arch,struct Persona &p);
bool operator ==(int dni,struct Persona &p);
ostream &operator <<(ostream &out,const struct Persona &p);


#endif /* FUNCPERSONA_H */

