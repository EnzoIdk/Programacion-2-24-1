/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NLibro.h
 * Author: aml
 *
 * Created on 24 de junio de 2024, 09:48 AM
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include <fstream>
using namespace std;
#include "Libro.h"
class NLibro {
private:
    class Libro *plibro;
public:
    NLibro();
    NLibro(const NLibro& orig);
    virtual ~NLibro();
    void leerLib(ifstream &arch);
    double obtenerPeso() const;
    void imprimirLib(ofstream &arch);
};

#endif /* NLIBRO_H */

