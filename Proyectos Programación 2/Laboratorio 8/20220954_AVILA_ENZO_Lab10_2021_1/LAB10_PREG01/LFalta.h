/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   LFalta.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 03:29 PM
 */

#ifndef LFALTA_H
#define LFALTA_H
#include <fstream>
using namespace std;
#include "NFalta.h"
class LFalta {
private:
    class NFalta *lini;
    class NFalta *lfin;
public:
    LFalta();
    LFalta(const LFalta& orig);
    virtual ~LFalta();
    void leer(const char*);
    void imprimir(const char*);
    void insertarNodo(class NFalta *nodo);
    void imprimirLinea(ofstream &,int,char);
};

#endif /* LFALTA_H */

