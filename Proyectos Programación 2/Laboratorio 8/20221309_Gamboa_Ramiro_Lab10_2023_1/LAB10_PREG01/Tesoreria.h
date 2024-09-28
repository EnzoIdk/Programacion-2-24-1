/* 
 * File:   Tesoreria.h
 * Author: ramir
 *
 * Created on 7 de junio de 2024, 11:18 AM
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Arbol.h"

class Tesoreria {
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    void cargaalumnos();
    void actualizaboleta();
    void imprimeboleta();
private:
    Arbol aboleta;
};

#endif /* TESORERIA_H */

