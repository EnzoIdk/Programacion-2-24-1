/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 09:00 PM
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Libro {
private:
    char *codigo;
    char *titulo;
    char *autor;
    int stock;
    double precio;
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetAutor(const char *aut);
    void GetAutor(char *aut) const;
    void SetTitulo(const char *tit);
    void GetTitulo(char *tit) const;
    void SetCodigo(const char *cod);
    void GetCodigo(char *cod) const;
};

bool operator >>(ifstream &,Libro &lib);
void operator <<(ofstream &,Libro &lib);

#endif /* LIBRO_H */

