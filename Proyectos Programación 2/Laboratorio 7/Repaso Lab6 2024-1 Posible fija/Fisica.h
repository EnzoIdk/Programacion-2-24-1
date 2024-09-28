/* 
 * File:   Fisica.h
 * Author: Lucas
 *
 * Created on 30 de mayo de 2024, 19:41
 */

#ifndef FISICA_H
#define FISICA_H

#include "Libro.h"

class Fisica:public Libro{
private:
    char * profesor;
public:
    //CONST Y DEST
    Fisica();
    virtual ~Fisica();
    //GETTERS Y SETTERS
    void SetProfesor(char * cad);
    void GetProfesor(char * cad) const;
    //METODOS
    void leer_datos(ifstream &arch);
    void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* FISICA_H */

