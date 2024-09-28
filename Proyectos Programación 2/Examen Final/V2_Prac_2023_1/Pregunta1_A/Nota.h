/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.h
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 06:41 PM
 */

#ifndef NOTA_H
#define NOTA_H

#include "Librerias.h"

class Nota {
public:
    Nota();
    Nota(const Nota& orig);
    virtual ~Nota();
    
    void setCiclo(int c);
    void setCodigoCurso(char *cad);
    void setCreditos(double c);
    void setCalificacion(int c);
    void setVez(int v);
    int getCiclo()const;
    void getCodigoCurso(char *cad)const;
    double getCreditos()const;
    int getCalificacion()const;
    int getVez()const;
    void operator=(const Nota &otro);
    
    void imprimeNota(ofstream &out);
private:
    int ciclo;
    char *codigo_curso;
    double creditos;
    int calificacion;
    int vez;
};
void operator>>(ifstream &in,Nota &nota);
#endif /* NOTA_H */

