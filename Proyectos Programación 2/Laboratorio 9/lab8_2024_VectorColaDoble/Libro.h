/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: margo
 *
 * Created on 20 de junio de 2024, 7:38
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;
class Libro {
private:
    char*nombre;
    int paginas;
    double peso;

public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    virtual void lee(ifstream&);
    virtual void imprime(ofstream&);
    virtual void actualizar();
};
#endif /* LIBRO_H */

