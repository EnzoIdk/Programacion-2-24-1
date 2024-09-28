/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   farmacia.h
 * Author: aml
 *
 * Created on 29 de mayo de 2024, 09:26 AM
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include "medico.h"
#include "conreceta.h"
#include "sinreceta.h"
class farmacia {
public:
    void cargamedico(const char*);
    void leerecetas(const char*);
    void leerDatosGenerales(ifstream &,int &,int &,char*,int &,char*);
    void leeRecetaCliente(ifstream &,int,int,const char*,int,const char*,int&,int&);
    void imprimirrecetas(const char*);
    bool conReceta(int);
    int buscarPosMed(int);
    void imprimirLinea(ofstream &,int,char);
private:
    class medico lmedico[100];
    class sinreceta lsinreceta[1000];
    class conreceta lconreceta[1000];
};

#endif /* FARMACIA_H */

