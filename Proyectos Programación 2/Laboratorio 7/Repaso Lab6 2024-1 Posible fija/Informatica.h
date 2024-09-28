/* 
 * File:   Informatica.h
 * Author: Lucas
 *
 * Created on 30 de mayo de 2024, 19:47
 */

#ifndef INFORMATICA_H
#define INFORMATICA_H

#include "Libro.h"

class Informatica:public Libro{
private:
    char * curso;
public:
    //CONST Y DEST
    Informatica();
    virtual ~Informatica();
    //GETTERS Y SETTERS
    void SetCurso(char * cad);
    void GetCurso(char * cad) const;
    //METODOS
    void leer_datos(ifstream &arch);
    void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* INFORMATICA_H */

