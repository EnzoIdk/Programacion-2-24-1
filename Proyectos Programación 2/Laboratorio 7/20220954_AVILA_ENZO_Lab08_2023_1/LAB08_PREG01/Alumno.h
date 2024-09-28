/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Enzo
 *
 * Created on 28 de mayo de 2024, 12:14 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
using namespace std;
class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double total;
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char*);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leerDatos(ifstream &);
    void imprime(ofstream &);
};

#endif /* ALUMNO_H */

