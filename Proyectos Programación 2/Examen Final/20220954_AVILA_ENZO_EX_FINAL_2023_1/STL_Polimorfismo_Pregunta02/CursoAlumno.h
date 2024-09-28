/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   CursoAlumno.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 04:39 PM
 */

#ifndef CURSOALUMNO_H
#define CURSOALUMNO_H
#include <fstream>
using namespace std;

class CursoAlumno {
private:
    int codigo;
    char *codcur;
    int ciclo;
    double creditos;
    int nota;
    int vez;
public:
    CursoAlumno();
    CursoAlumno(const CursoAlumno& orig);
    virtual ~CursoAlumno();
    void SetVez(int vez);
    int GetVez() const;
    void SetNota(int nota);
    int GetNota() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCodcur(const char *cad);
    void GetCodcur(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch);
    virtual void muestra();
    virtual void actualiza()=0;
    virtual void imprime(ofstream &arch);
};

#endif /* CURSOALUMNO_H */

