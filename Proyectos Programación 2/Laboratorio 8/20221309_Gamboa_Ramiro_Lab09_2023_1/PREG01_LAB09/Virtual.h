/* 
 * File:   Virtual.h
 * Author: ramir
 *
 * Created on 5 de junio de 2024, 02:47 PM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"

class Virtual:public Alumno {
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char *cad);
    void GetLicencia(char *cad) const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

