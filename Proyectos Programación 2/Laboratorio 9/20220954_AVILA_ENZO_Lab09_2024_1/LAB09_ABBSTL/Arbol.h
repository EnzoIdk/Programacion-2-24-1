/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: aml
 *
 * Created on 24 de junio de 2024, 09:48 AM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <fstream>
using namespace std;
#include "NEstante.h"
class Arbol {
private:
    class NEstante *raiz;
    void insertarRec(class NEstante *&nodo,const class NEstante &auxEst);
    void mostrarRec(class NEstante *nodo,ofstream &arch);
    void probarRec(class NEstante *nodo,double peso,ofstream &arch,int &);
//    void elimina(class NEstante *nodo);
public:
    Arbol();
//    virtual ~Arbol();
    void insertar(const class NEstante &auxEst);
    void mostrar(ofstream &arch);
    void probar(double peso,ofstream &arch);
};

#endif /* ARBOL_H */

