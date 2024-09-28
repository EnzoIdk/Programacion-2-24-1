/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matematica.h
 * Author: margo
 *
 * Created on 29 de mayo de 2024, 9:21
 */

#ifndef MATEMATICA_H
#define MATEMATICA_H

#include "Libro.h"
#include <fstream>
using namespace std;

class Matematica:public Libro {
private:
    char *codigo;

public:
    Matematica();
    Matematica(const Matematica& orig);
    virtual ~Matematica();
    void SetCodigo(const char* codigo);
    void GetCodigo(  char*) const;
    void lectura(ifstream&);
};
#endif /* MATEMATICA_H */

