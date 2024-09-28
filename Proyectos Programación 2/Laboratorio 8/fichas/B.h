/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   B.h
 * Author: margo
 *
 * Created on 11 de junio de 2024, 18:29
 */

#ifndef B_H
#define B_H

#include "FIchas.h"
#include <fstream>
using namespace std;

class B : public FIchas {
private:


public:
    B();
    B(const B& orig);
    virtual ~B();
    void movimientos(char, int);
    void impresion(ofstream&);
};
#endif /* B_H */

