/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LFalta.h
 * Author: ISA
 *
 * Created on 6 de junio de 2024, 04:08 PM
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
    void insertarNodoOrdenado(class NFalta *nuevo);
public:
    LFalta();
    LFalta(const LFalta& orig);
    virtual ~LFalta();
    void leer(const char* nomArch);
    void imprimir(const char* nomArch);
};

#endif /* LFALTA_H */

