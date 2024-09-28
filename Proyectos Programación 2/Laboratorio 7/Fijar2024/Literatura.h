/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Literatura.h
 * Author: margo
 *
 * Created on 29 de mayo de 2024, 9:22
 */

#ifndef LITERATURA_H
#define LITERATURA_H
#include <fstream>

#include "Libro.h"
using namespace std;
class Literatura : public Libro {
private:
    double descuento;

public:
    Literatura();
    Literatura(const Literatura& orig);
    virtual ~Literatura();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lectura(ifstream &);
};
#endif /* LITERATURA_H */

