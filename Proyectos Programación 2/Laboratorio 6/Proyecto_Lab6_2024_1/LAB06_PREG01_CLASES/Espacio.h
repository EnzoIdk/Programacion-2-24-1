/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Espacio.h
 * Author: ISA
 *
 * Created on 24 de mayo de 2024, 10:14 PM
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
    Espacio(const Espacio& orig);
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;

};

ofstream & operator <<(ofstream &arch,const class Espacio &Esp);
#endif /* ESPACIO_H */

