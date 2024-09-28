/* 
 * File:   Boleta.h
 * Author: ramir
 *
 * Created on 5 de junio de 2024, 02:49 PM
 */

#ifndef BOLETA_H
#define BOLETA_H

#include "Alumno.h"

class Boleta {
public:
    Boleta();
    Boleta(const Boleta& orig);
    virtual ~Boleta();
    void leealumno(ifstream &);
    bool existe();
    void imprimealumno(ofstream &);
private:
    Alumno *pboleta;
};

#endif /* BOLETA_H */

