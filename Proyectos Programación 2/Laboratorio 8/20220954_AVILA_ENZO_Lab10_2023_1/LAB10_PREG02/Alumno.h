/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Enzo
 *
 * Created on 10 de junio de 2024, 10:22 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <fstream>
using namespace std;
class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char *);
    void GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &);
    virtual void imprime(ofstream &);
    virtual void actualizatotal(double);
};

#endif /* ALUMNO_H */

