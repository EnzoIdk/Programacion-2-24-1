/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Boleta.h
 * Author: Enzo
 *
 * Created on 11 de junio de 2024, 09:36 PM
 */

#ifndef BOLETA_H
#define BOLETA_H
#include <fstream>
using namespace std;
#include "Alumno.h"
class Boleta {
private:
    class Alumno *pboleta;
public:
    Boleta();
    virtual ~Boleta();
    void asignaMemoria(char);
    void leerDatos(ifstream &);
    void SetNull();
    int GetCodigo() const;
    void imprimeAlumnos(ofstream &);
    int GetEscala() const;
    void actualizaBoleta(double);
};

#endif /* BOLETA_H */

