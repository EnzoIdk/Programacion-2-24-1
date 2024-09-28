/*
 * Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Enciclopedia.h
 * Author: Lucas
 *
 * Created on 8 de julio de 2024, 07:46 PM
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"

class Enciclopedia:public Libro {
private:
    int sku;
    int anho;
    bool vigente;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Enciclopedia();
    Enciclopedia(const class Enciclopedia &orig);
    virtual ~Enciclopedia();
    //GETTERS Y SETTERS
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    void SetVigente(bool vigente);
    bool IsVigente() const;
    //METODOS
    void leer(ifstream &arch);
    void actualiza(int aa);
    void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* ENCICLOPEDIA_H */

