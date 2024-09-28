/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NUsuario.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 02:09 PM
 */

#ifndef NUSUARIO_H
#define NUSUARIO_H
#include <fstream>
#include "Usuario.h"
using namespace std;

class NUsuario {
private:
    class Usuario *pusuario;
public:
    NUsuario();
    NUsuario(const NUsuario& orig);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    int ObtenerCarne() const;
};

#endif /* NUSUARIO_H */

