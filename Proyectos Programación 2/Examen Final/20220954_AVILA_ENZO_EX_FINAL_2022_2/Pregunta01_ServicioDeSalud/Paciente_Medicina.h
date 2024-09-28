/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Paciente_Medicina.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 07:26 PM
 */

#ifndef PACIENTE_MEDICINA_H
#define PACIENTE_MEDICINA_H
#include <fstream>
#include <list>
#include <iterator>
#include <map>
#include "Paciente.h"
using namespace std;

#include "Medicina.h"
#include "Medicina_Cantidad.h"

class Paciente_Medicina {
private:
    class Paciente paciente;
    list<class Medicina_Cantidad> medicina_cantidad;
    double totalDeGastos;
    
public:
    Paciente_Medicina();
    Paciente_Medicina(const Paciente_Medicina& orig);
    virtual ~Paciente_Medicina();
    void SetTotalDeGastos(double totalDeGastos);
    double GetTotalDeGastos() const;
    void totalizar(map<int,Medicina> med);
    int obtenerDNI() const;
    void SetPaciente(const class Paciente &);
    void leerMedicinas(ifstream &arch);
    bool operator >(const class Paciente &);
    void imprimir(ofstream &arch);
};

#endif /* PACIENTE_MEDICINA_H */

