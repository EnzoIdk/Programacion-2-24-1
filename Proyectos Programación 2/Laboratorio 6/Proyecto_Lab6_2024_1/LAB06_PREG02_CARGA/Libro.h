/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: ISA
 *
 * Created on 24 de mayo de 2024, 10:14 PM
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
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    
    void SetCodigo(char *cad);
    void GetCodigo(char *cad) const;
    bool IsNotNullCodigo() const;
    void SetNombre(char *cad);
    void GetNombre(char *cad) const;

};

ifstream & operator >> (ifstream &arch,class Libro &Lib);
ofstream & operator << (ofstream &arch,const class Libro &Lib);

#endif /* LIBRO_H */

