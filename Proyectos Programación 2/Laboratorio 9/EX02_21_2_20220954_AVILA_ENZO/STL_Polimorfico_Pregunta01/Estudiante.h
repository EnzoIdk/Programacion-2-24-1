/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estudiante.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 02:08 PM
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <fstream>
#include "Usuario.h"
using namespace std;

class Estudiante:public Usuario{
private:
    int celular;
public:
    Estudiante();
    void SetCelular(int celular);
    int GetCelular() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* ESTUDIANTE_H */

