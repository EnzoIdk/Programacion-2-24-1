/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nota.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 04:25 PM
 */

#ifndef NOTA_H
#define NOTA_H
using namespace std;
class Nota {
private:
    char *codcurso;
    int ciclo;
    int nota;
public:
    Nota();
    Nota(const Nota& orig);
    virtual ~Nota();
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCodcurso(const char*);
    void GetCodcurso(char *) const;
};

#endif /* NOTA_H */

