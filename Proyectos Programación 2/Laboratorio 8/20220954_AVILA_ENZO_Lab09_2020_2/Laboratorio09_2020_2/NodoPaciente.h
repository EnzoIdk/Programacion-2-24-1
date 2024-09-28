/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NodoPaciente.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 10:57 PM
 */

#ifndef NODOPACIENTE_H
#define NODOPACIENTE_H
#include <fstream>
using namespace std;
#include "ListaPacientes.h"
#include "Paciente.h"
class NodoPaciente {
private:
    class Paciente *ptrPaciente;
    class NodoPaciente *sig;
public:
    NodoPaciente();
    friend class ListaPacientes;
};

#endif /* NODOPACIENTE_H */

