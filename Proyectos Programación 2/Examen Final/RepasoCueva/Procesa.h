/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Procesa.h
 * Author: Enzo
 *
 * Created on 29 de junio de 2024, 05:12 PM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <fstream>
#include <map>
#include <string>
#include <iterator>
#include <vector>
using namespace std;
#include "Revista.h"
#include "Libro.h"
#include "Estante.h"
class Procesa {
private:
    //ISSN Revista
    //las revistas están ordenadas por el ISSN
    //llave primaria: ISSN
    //llave secundaria: Revista
    map<string, Revista> mrevista;
    //mapa de vector de libros (con índice de estantes)
    map<Estante,vector<Libro>> mestante;
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();
    void carga();
    void muestra();
    void cargaEstante();
    void cargaLibros();
    void muestraLibros();
};

#endif /* PROCESA_H */

