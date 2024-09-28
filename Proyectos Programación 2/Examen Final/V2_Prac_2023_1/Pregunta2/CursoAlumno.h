/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CursoAlumno.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 08:16 PM
 */

#ifndef CURSOALUMNO_H
#define CURSOALUMNO_H

#include "Librerias.h"

class CursoAlumno {
public:
    CursoAlumno();
//    CursoAlumno(const CursoAlumno& orig);
    virtual ~CursoAlumno();
    
    void setCodigo(int c);
    void setCodCurso(char *cad);
    void setCiclo(int c);
    void setCreditos(double c);
    void setNota(int n);
    void setVez(int v);
    int getCodigo()const;
    void getCodCurso(char *cad)const;
    int getCiclo()const;
    double getCreditos()const;
    int getNota()const;
    int getVez()const;
    
    virtual void actualiza();
    virtual void imprime(ofstream &out);
private:
    int codigo;
    char *codcur;
    int ciclo;
    double creditos;
    int nota;
    int vez;
};

#endif /* CURSOALUMNO_H */

