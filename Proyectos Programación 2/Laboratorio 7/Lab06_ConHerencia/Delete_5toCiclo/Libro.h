/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Enzo
 *
 * Created on 30 de mayo de 2024, 10:31 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;

class Libro {
private:
    char *tipo;
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
    void GetNombre(char *) const;
    void SetCodigo(const char*);
    void GetCodigo(char *) const;
    void SetTipo(const char *);
    void GetTipo(char *) const;
    void leerDatos(ifstream &);
    void imprime(ofstream &);
};

#endif /* LIBRO_H */

