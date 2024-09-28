/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 09:36 PM
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include <fstream>
using namespace std;
#include "Lista.h"
#include "Libro.h"
class Estante {
private:
    char clase;
    int id;
    double capacidad;
    class Lista Llibros;
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void setCapacidad(double capacidad);
    double getCapacidad() const;
    void setId(int id);
    int getId() const;
    void setClase(char clase);
    char getClase() const;
    void leerDatos(ifstream &arch);
    void imprimeEst(ofstream &arch);
    void operator=(const Estante &orig);
    int insertar(class Libro *auxLib);
    void actualizarEst();
    void eliminar();
};

#endif /* ESTANTE_H */

