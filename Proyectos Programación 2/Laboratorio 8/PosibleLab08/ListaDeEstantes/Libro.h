/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 08:22 AM
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
    double peso;
    bool colocado;
public:
    Libro();
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetPeso(double peso);
    double GetPeso() const;
    void SetNombre(const char *cad);
    void GetNombre(char *cad) const;
    void SetCodigo(const char *cad);
    void GetCodigo(char *cad) const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    virtual void leerLib(ifstream &);
    virtual void imprimirLib(ofstream &);
};

#endif /* LIBRO_H */

