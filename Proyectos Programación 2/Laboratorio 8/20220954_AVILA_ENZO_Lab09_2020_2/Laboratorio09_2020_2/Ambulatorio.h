/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Ambulatorio.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 10:44 PM
 */

#ifndef AMBULATORIO_H
#define AMBULATORIO_H
#include <fstream>
using namespace std;
#include "Paciente.h"
class Ambulatorio:public Paciente{
private:
    double porcSeguro;
public:
    Ambulatorio();
    void SetPorcSeguro(double porcSeguro);
    double GetPorcSeguro() const;
    void lee(ifstream &);
    int getPrioridad() const;
    void imprime(ofstream &);
    bool tieneSeguro() const;
};

#endif /* AMBULATORIO_H */

