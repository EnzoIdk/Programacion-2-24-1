/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.h
 * Author: ISA
 *
 * Created on 6 de junio de 2024, 03:44 PM
 */

#ifndef FALTA_H
#define FALTA_H
#include <fstream>
using namespace std;
class Falta {
private:
    int licencia;
    int fecha;
    char *placa;
    void ImprimirFecha(ofstream &arch);
public:
    Falta();
    Falta(const Falta& orig);
    virtual ~Falta();
    void operator = (const Falta& orig);
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    void SetPlaca(char *cad);
    void GetPlaca(char *cad) const;
    int operator <= (ifstream &arch);
    void operator >= (ofstream &arch);
};

#endif /* FALTA_H */

