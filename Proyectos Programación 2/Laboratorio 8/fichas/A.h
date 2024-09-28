/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   A.h
 * Author: margo
 *
 * Created on 11 de junio de 2024, 18:29
 */

#ifndef A_H
#define A_H
#include "FIchas.h"
#include <fstream>
using namespace std;
class A : public FIchas {
private:


public:
    A();
    A(const A& orig);
    virtual ~A();
    void movimientos(char, int);    
    void impresion(ofstream&);
};
#endif /* A_H */

