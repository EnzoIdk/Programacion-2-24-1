/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: margo
 *
 * Created on 29 de mayo de 2024, 9:13
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;
class Libro {
private:
    char *codigo;
    char *nombre;
    int alto;
    int ancho;
    bool colocado;

public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*) const; 
    void lectura(ifstream &);
    void agregarDatosLibro(Libro &);
};
#endif /* LIBRO_H */

