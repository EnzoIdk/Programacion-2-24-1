/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   EstanteHorizontal.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 08:25 AM
 */

#ifndef ESTANTEHORIZONTAL_H
#define ESTANTEHORIZONTAL_H
#include <fstream>
using namespace std;
#include "Estante.h"
#include "Novela.h"
class EstanteHorizontal:public Estante{
private:
    class Novela novelas[10];
    int cantidad_novelas;
public:
    EstanteHorizontal();
    void SetCantidad_novelas(int cantidad_novelas);
    int GetCantidad_novelas() const;
    void leeEst(ifstream &);
    void imprimeEst(ofstream &);
    void agregarLibro(class Libro *lib);
};

#endif /* ESTANTEHORIZONTAL_H */

