/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medico.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 07:21 AM
 */

#ifndef MEDICO_H
#define MEDICO_H
#include <fstream>
using namespace std;

class medico {
private:
    int codigo;
    char *nombre;
    double tarifa;
public:
    medico();
    medico(const medico& orig);
    virtual ~medico();
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    void SetNombre(const char *);
    void GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

void operator >>(ifstream &,medico &med);

#endif /* MEDICO_H */

