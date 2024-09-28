/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ServicioDeSalud.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 07:36 PM
 */

#ifndef SERVICIODESALUD_H
#define SERVICIODESALUD_H
#include <fstream>
#include <map>
#include <list>
#include <iterator>

#include "Medicina.h"
#include "Paciente_Medicina.h"
using namespace std;

class ServicioDeSalud {
private:
    map<int,Medicina> medicina;
    list<Paciente_Medicina> paciente_medicina;
public:
    ServicioDeSalud();
    ServicioDeSalud(const ServicioDeSalud& orig);
    virtual ~ServicioDeSalud();
    void leerMedicinas(const char *);
    void imprimirMedicinas(const char*);
    void leerConsultas(const char*);
    void totalizar();
    void imprimePacientes(const char*);
};

#endif /* SERVICIODESALUD_H */

