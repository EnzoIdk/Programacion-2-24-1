/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nota.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 12:46 AM
 */

#ifndef NOTA_H
#define NOTA_H
#include <fstream>
using namespace std;

class Nota {
private:
    int ciclo;
    char *codigo_curso;
    double creditos;
    int calificacion;
    int vez;
public:
    Nota();
    Nota(const Nota& orig);
    virtual ~Nota();
    void SetVez(int vez);
    int GetVez() const;
    void SetCalificacion(int calificacion);
    int GetCalificacion() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetCodigo_curso(const char *cad);
    void GetCodigo_curso(char *cad) const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void imprimeNota(ofstream &arch);
    void asignarCiclo(int ciclo);
};

void operator >>(ifstream &arch,class Nota &nota);

#endif /* NOTA_H */

