/* 
 * File:   Presencial.h
 * Author: ramir
 *
 * Created on 5 de junio de 2024, 02:45 PM
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"

class Presencial:public Alumno {
public:
    Presencial();
    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

