/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Docente.h
 * Author: Enzo
 *
 * Created on 20 de junio de 2024, 02:08 PM
 */

#ifndef DOCENTE_H
#define DOCENTE_H
#include <fstream>
#include "Usuario.h"
using namespace std;

class Docente:public Usuario{
private:
    int anexo;
public:
    Docente();
    void SetAnexo(int anexo);
    int GetAnexo() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* DOCENTE_H */

