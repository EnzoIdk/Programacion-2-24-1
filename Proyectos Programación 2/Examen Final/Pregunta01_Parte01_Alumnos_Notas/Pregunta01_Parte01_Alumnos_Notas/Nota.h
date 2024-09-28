/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.h
 * Author: margo
 *
 * Created on 8 de julio de 2024, 18:37
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
    void SetCodigo_curso(char* codigo_curso);
    void GetCodigo_curso(char *) const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void operator = (Nota &);
};
void operator >>(ifstream&, Nota&);
void operator <<(ofstream&, Nota&);
#endif /* NOTA_H */

