/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Boleta.h
 * Author: Enzo
 *
 * Created on 7 de junio de 2024, 04:54 PM
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
    void asignaMemoria(char tipo);
    void leeDatos(ifstream &arch) const;
    bool hayDato();
    int GetEscala();
    void imprimeBoleta(ofstream &);
    void actualizaBoleta(double);
};

#endif /* BOLETA_H */

