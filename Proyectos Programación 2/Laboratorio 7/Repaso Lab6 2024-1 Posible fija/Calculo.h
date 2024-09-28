/* 
 * File:   Calculo.h
 * Author: Lucas
 *
 * Created on 30 de mayo de 2024, 19:44
 */

#ifndef CALCULO_H
#define CALCULO_H

#include "Libro.h"

class Calculo:public Libro{
private:
    int ciclo;
public:
    //CONST Y DEST
    Calculo();
    virtual ~Calculo();
    //GETTERS Y SETTERS
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    //METODOS
    void leer_datos(ifstream &arch);
    void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* CALCULO_H */

