/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Infraccion.h
 * Author: aml
 *
 * Created on 12 de junio de 2024, 02:56 PM
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
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(const char *cad);
    void GetGravedad(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    //no olvidar el virtual...
    virtual void lee(ifstream &,int);
    virtual void imprime(ofstream &);
};

#endif /* INFRACCION_H */

