/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   EstanteVertical.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 08:24 AM
 */

#ifndef ESTANTEVERTICAL_H
#define ESTANTEVERTICAL_H
#include <fstream>
using namespace std;
#include "Estante.h"
#include "Enciclopedia.h"
#include "Libro.h"
class EstanteVertical:public Estante{
private:
    class Enciclopedia enciclopedias[10];
    int cantidad_enciclopedias;
public:
    EstanteVertical();
    void SetCantidad_enciclopedias(int cantidad_enciclopedias);
    int GetCantidad_enciclopedias() const;
    void leeEst(ifstream &);
    void imprimeEst(ofstream &);
    void agregarLibro(class Libro *);
};

#endif /* ESTANTEVERTICAL_H */

