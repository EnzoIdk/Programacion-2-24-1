/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tesoreria.h
 * Author: Enzo
 *
 * Created on 7 de junio de 2024, 10:22 PM
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include <fstream>
using namespace std;
#include "Boleta.h"
#include "Escala.h"
class Tesoreria {
private:
    class Boleta lboleta[100];
    class Escala lescala[10];
public:
    void cargaescalas();
    void cargaalumnos();
    void imprimeboleta();
    void actualizaboleta();
    void imprimeLinea(ofstream &,int,char);
};

#endif /* TESORERIA_H */

