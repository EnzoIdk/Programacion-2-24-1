/* 
 * File:   Tesoreria.h
 * Author: ramir
 *
 * Created on 5 de junio de 2024, 02:49 PM
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    void cargaescalas();
    void cargaalumnos();
    void actualizaboleta();
    void imprimeboleta();
private:
    Boleta lboleta[100];
    Escala lescala[10];
    void imprimirLinea(ofstream &,char);
};

#endif /* TESORERIA_H */

