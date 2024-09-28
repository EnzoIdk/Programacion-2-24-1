/* 
 * File:   Boleta.h
 * Author: ramir
 *
 * Created on 7 de junio de 2024, 11:12 AM
 */

#ifndef BOLETA_H
#define BOLETA_H

#include "Alumno.h"

class Boleta {
public:
    Boleta();
    Boleta(const Boleta& orig);
    virtual ~Boleta();
    void asignaMemoria(char);
    void leerDatos(ifstream &);
    void SetNull();
    int GetCodigo() const;
    void imprimealumnos(ofstream &);
private:
    Alumno *pboleta;
};

#endif /* BOLETA_H */

