/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Libro.h
 * Author: Lucas
 *
 * Created on 8 de julio de 2024, 07:44 PM
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
#include <string>
using namespace std;

class Libro {
private:
    string nombre;
    int paginas;
    double peso;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Libro();
    Libro(const class Libro &orig);
    virtual ~Libro();
    //GETTERS Y SETTERS
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    //METODOS
    virtual void leer(ifstream &arch);
    virtual void actualiza(int aa)=0;
    virtual void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* LIBRO_H */

