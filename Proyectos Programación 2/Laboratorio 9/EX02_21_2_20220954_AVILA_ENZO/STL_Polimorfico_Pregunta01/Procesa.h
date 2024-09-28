/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Procesa.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 02:44 PM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include "Libro.h"
#include "ColaSol.h"
#include "Usuario.h"
#include "NUsuario.h"
using namespace std;

class Procesa {
private:
    list<class Libro> llibros;
    class ColaSol cola;
    vector<class NUsuario> vusuarios;
public:
    void Carga();
    void Atiende();
    void Imprime();
    void CargaLibros(const char *nombArch);
    void CargaUsuarios(const char *nombArch);
    void LeeSolicitudes(const char *nombArch);
    void actualiza(char *cad,int carne);
    void ImprimeLibros(const char *nombArch);
    void ImprimeCola(const char *nombArch);
    void ImprimeUsuario(int carne,ofstream &arch);
};

#endif /* PROCESA_H */

