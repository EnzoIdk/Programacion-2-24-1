/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Enzo
 *
 * Created on 29 de mayo de 2024, 04:05 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;
class Libro {
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    Libro();
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char*);
    void GetNombre(char*) const;
    void SetCodigo(const char*);
    void GetCodigo(char*) const;
};

void operator >>(ifstream &arch,class Libro &lib);
void operator <<(ofstream &arch,class Libro &lib);

#endif /* LIBRO_H */

