/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Urgencia.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 10:44 PM
 */

#ifndef URGENCIA_H
#define URGENCIA_H
#include <fstream>
using namespace std;
#include "Paciente.h"
class Urgencia:public Paciente{
private:
    double porcSeguro;
    double porcUrgencia;
public:
    Urgencia();
    void SetPorcUrgencia(double porcUrgencia);
    double GetPorcUrgencia() const;
    void SetPorcSeguro(double porcSeguro);
    double GetPorcSeguro() const;
    void lee(ifstream &);
    int getPrioridad() const;
    void imprime(ofstream &);
    bool tieneSeguro() const;
};

#endif /* URGENCIA_H */

