/* 
 * File:   Arbol.h
 * Author: ramir
 *
 * Created on 7 de junio de 2024, 11:17 AM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include "Escala.h"

class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void crear(const char*);
    void insertarRaiz(class Nodo *&,const class Boleta &);
    void mostrarEnOrden(const char*);
    void cargaEscalas(const char*);
    void actualizaBoleta();
private:
    Nodo *raiz;
    Escala lescala[10];
    void imprimirLinea(ofstream &,char);
    void mostrarEnOrdenRaiz(ofstream &,class Nodo*);
    void actualizaBoletaRaiz(class Nodo*);
};

#endif /* ARBOL_H */

