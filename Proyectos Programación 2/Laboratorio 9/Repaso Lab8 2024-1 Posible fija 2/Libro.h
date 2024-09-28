/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Libro.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 21:06
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
using namespace std;

class Libro {
private:
    char * nombre;
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
    void SetNombre(char * cad);
    void GetNombre(char * cad) const;
    //METODOS
    virtual void lee(ifstream &arch);
    virtual void actualiza()=0;
    virtual void imprime(ofstream &arch);
};

//FUNCIONES

#endif /* LIBRO_H */

