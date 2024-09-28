/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nota.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 04:40 PM
 */

#ifndef NOTA_H
#define NOTA_H
#include <fstream>
using namespace std;
#include "CursoAlumno.h"
class Nota {
private:
    class CursoAlumno *pnota;
public:
    Nota();
    Nota(const Nota& orig);
    virtual ~Nota();
    void leeNota(ifstream &arch);
    void muestraNota();
    bool operator <(const Nota &nota);
    void GetCodCur(char *car) const;
    int GetCodigo() const;
    void actualizar(const Nota &nota);
    void operator =(const Nota &nota);
    void imprimeNota(ofstream &arch);
};

#endif /* NOTA_H */

