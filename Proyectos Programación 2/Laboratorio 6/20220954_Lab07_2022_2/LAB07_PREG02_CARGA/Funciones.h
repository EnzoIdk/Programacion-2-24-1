/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Funciones.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 11:55 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "cita.h"
#include "medico.h"
#include "paciente.h"
using namespace std;

class Funciones {
private:
    medico arrMed[100];
    paciente arrPac[100];
public:
    Funciones();
    Funciones(const Funciones& orig);
    virtual ~Funciones();
    void cargarMedicos();
    void cargarPacientes();
    void cargarCitas();
    void actualizarTarifas();
    void mostrarDatos();
};

int buscarCli(paciente *arr,int dni);

#endif /* FUNCIONES_H */

