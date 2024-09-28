/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: margo
 *
 * Created on 29 de mayo de 2024, 9:13
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Libro.h"
#include "Estante.h"
#include "Literatura.h"
#include "Matematica.h"
class Biblioteca {
private:
    Estante *mat;
    Matematica lmat[20];
    int estantesMat;
    Estante *lit;
    int estantesLit;
    Literatura llit[20];
    int totalLibros;
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void SetTotalLibros(int totalLibros);
    int GetTotalLibros() const;
    void SetEstantesLit(int estantesLit);
    int GetEstantesLit() const;
    void SetEstantesMat(int estantesMat);
    int GetEstantesMat() const;
    void cargarLibros();
    void cargarEstantes();
    void agregarLibros();
    void agregarMatematica();
    void agregarLiteratura();
    void impresion();
    void impresionEstanteMatematica(ofstream&);
    void impresionEstanteLiteratura(ofstream &);
};
#endif /* BIBLIOTECA_H */

