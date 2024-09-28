/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Registro.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 04:40 PM
 */

#ifndef REGISTRO_H
#define REGISTRO_H
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
#include "Nota.h"
class Registro {
private:
    vector<class Nota> vregistro;
public:
//    Registro();
//    Registro(const Registro& orig);
//    virtual ~Registro();
    void carga();
    void procesa();
    void muestra();
};

#endif /* REGISTRO_H */

