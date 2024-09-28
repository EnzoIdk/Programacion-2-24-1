/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Procesa.h
 * Author: Enzo
 *
 * Created on 8 de julio de 2024, 07:08 AM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <fstream>
#include <list>
using namespace std;
#include "Pedido.h"
class Procesa {
private:
    list<Pedido*> lped;
    void reserva(int,Pedido*&);
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();
    void carga();
    void muestra();
};

#endif /* PROCESA_H */

