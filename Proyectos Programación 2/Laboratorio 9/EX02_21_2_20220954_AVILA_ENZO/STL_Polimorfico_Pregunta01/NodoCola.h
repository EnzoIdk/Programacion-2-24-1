/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NodoCola.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 02:12 PM
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <fstream>
#include "ColaSol.h"
using namespace std;

class NodoCola {
private:
    char *libsol;
    int carne;
    class NodoCola *sig;
public:
    NodoCola();
    friend class ColaSol;
    virtual ~NodoCola();
    void SetCarne(int carne);
    int GetCarne() const;
    void SetLibsol(const char *cad);
    void GetLibsol(char *cad) const;
};

#endif /* NODOCOLA_H */

