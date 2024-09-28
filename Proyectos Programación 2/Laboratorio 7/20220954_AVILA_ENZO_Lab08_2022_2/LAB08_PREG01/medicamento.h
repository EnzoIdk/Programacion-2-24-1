/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medicamento.h
 * Author: aml
 *
 * Created on 29 de mayo de 2024, 08:54 AM
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include <fstream>
using namespace std;

class medicamento {
public:
    medicamento();
    virtual ~medicamento();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(const char*);
    void GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void asignarDatos(int,int,int);
    void imprimir(ofstream &);
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int fecha;
};

#endif /* MEDICAMENTO_H */

