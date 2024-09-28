/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C.h
 * Author: margo
 *
 * Created on 11 de junio de 2024, 18:29
 */

#ifndef C_H
#define C_H

#include "FIchas.h"
#include <fstream>
using namespace std;

class C : public FIchas {
private:
    

public:
    C();
    C(const C& orig);
    virtual ~C();
    void movimientos(char, int);
    void impresion(ofstream&);
};
#endif /* C_H */

