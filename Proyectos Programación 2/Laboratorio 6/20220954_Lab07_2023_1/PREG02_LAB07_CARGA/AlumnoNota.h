/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   AlumnoNota.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 04:24 PM
 */

#ifndef ALUMNONOTA_H
#define ALUMNONOTA_H
#include "Nota.h"
using namespace std;
class AlumnoNota {
private:
    int codigo;
    char *codcurso;
    int ciclo;
    int nota;
public:
    AlumnoNota();
    AlumnoNota(const AlumnoNota& orig);
    virtual ~AlumnoNota();
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCodcurso(const char*);
    void GetCodcurso(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator &(class Nota &nota);
};

void operator >>(ifstream &arch,class AlumnoNota &alNota);

#endif /* ALUMNONOTA_H */

