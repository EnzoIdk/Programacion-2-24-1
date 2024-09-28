/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.h
 * Author: ISA
 *
 * Created on 6 de junio de 2024, 03:39 PM
 */

#ifndef INFRACCION_H
#define INFRACCION_H
#include <fstream>
using namespace std;
class Infraccion {
private:
    int codigo;
    char *gravedad;
    double multa;
public:
    Infraccion();
    Infraccion(const Infraccion& orig);
    virtual ~Infraccion();
    void operator = (const Infraccion& orig);
    void SetMulta(double multa);
    double GetMulta() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void SetGravedad(char *cad);
    void GetGravedad(char *cad) const;
    virtual bool lee(ifstream &arch,int cod);
    virtual void imprime(ofstream &arch);
};

#endif /* INFRACCION_H */

