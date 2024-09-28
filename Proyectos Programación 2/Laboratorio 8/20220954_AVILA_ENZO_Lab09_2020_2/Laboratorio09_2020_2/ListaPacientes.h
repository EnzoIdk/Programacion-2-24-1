/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ListaPacientes.h
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 10:55 PM
 */

#ifndef LISTAPACIENTES_H
#define LISTAPACIENTES_H
#include <fstream>
using namespace std;
#include "NodoPaciente.h"
#include "Paciente.h"
class ListaPacientes {
private:
    class NodoPaciente *lista;
    void asignaMemoria(class Paciente *&,char);
public:
    ListaPacientes();
    virtual ~ListaPacientes();
    void elimina();
    void crealista(const char *nombArch);
    void imprimelista(const char *nombArch);
    void insertar(class Paciente *);
    void imprimirLinea(ofstream &,int,char);
    void encabezado1(ofstream &);
    void encabezado2(ofstream &);
    void encabezado3(ofstream &);
};

#endif /* LISTAPACIENTES_H */

