/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NFalta.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 03:24 PM
 */

#ifndef NFALTA_H
#define NFALTA_H
#include <fstream>
using namespace std;
#include "Infraccion.h"
#include "Falta.h"
#include "LFalta.h"
class NFalta {
private:
    class Infraccion *pfalta;
    class Falta dfalta;
    class NFalta *sig;
public:
    NFalta();
    friend class LFalta;
    void asignarMemoria(int);
    void buscaInf(int);
    void imprimeNodo(ofstream &);
};

#endif /* NFALTA_H */

