/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Rectangulo.h
 * Author: Enzo
 *
 * Created on 19 de mayo de 2024, 09:33 PM
 */

#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
public:
    Rectangulo();
    Rectangulo(const Rectangulo& orig);
    virtual ~Rectangulo();
private:
    char *nombre;
};

#endif /* RECTANGULO_H */

