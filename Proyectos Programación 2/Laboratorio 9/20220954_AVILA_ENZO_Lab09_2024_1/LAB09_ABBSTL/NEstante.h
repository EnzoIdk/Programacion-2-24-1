/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NEstante.h
 * Author: aml
 *
 * Created on 24 de junio de 2024, 09:48 AM
 */

#ifndef NESTANTE_H
#define NESTANTE_H

#include <fstream>
#include <vector>
using namespace std;
#include "NLibro.h"
#include "Arbol.h"
class NEstante {
private:
    int id;
    double capacidad;
    double disponible;
    vector<class NLibro> vlibros;
    class NEstante *izq;
    class NEstante *der;
public:
    NEstante();
//    NEstante(const NEstante& orig);
//    virtual ~NEstante();
    friend class Arbol;
    void SetDisponible(double disponible);
    double GetDisponible() const;
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void leerEst(ifstream &arch);
    void agregarAEst(class NLibro &auxLib);
    void imprimirEst(ofstream &arch);
    void imprimirLinea(ofstream &arch,int tam,int simb);
};

#endif /* NESTANTE_H */

