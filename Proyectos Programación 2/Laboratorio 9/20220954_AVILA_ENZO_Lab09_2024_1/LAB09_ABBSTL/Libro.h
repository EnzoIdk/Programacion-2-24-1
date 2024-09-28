/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: aml
 *
 * Created on 24 de junio de 2024, 09:47 AM
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
using namespace std;

class Libro {
private:
    char *nombre;
    int paginas;
    double peso;
public:
    Libro();
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(const char *);
    void GetNombre(char *) const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
};

#endif /* LIBRO_H */

