/* 
 * File:   Semipresencial.h
 * Author: ramir
 *
 * Created on 5 de junio de 2024, 02:46 PM
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Alumno.h"

class Semipresencial:public Alumno {
public:
    Semipresencial();
    Semipresencial(const Semipresencial& orig);
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void actualiza(double);
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

