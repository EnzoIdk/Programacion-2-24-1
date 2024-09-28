/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 08:56 PM
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
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(const char *cad);
    void GetNombre(char *cad) const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void actualiza()=0;
};

#endif /* LIBRO_H */

