/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Espacio.h
 * Author: Enzo
 *
 * Created on 29 de mayo de 2024, 04:05 PM
 */

#ifndef ESPACIO_H
#define ESPACIO_H
#include <fstream>
using namespace std;

class Espacio {
private:
    char contenido;
    int posx;
    int posy;
public:
    Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
};

void operator <<(ofstream &arch,class Espacio &esp);

#endif /* ESPACIO_H */

