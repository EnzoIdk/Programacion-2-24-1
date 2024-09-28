/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   Enciclopedia.h
 * Author: Lucas
 *
 * Created on 20 de junio de 2024, 18:48
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"

class Enciclopedia:public Libro {
private:
    int sku;
    int anho;
    int vigencia;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Enciclopedia();
    Enciclopedia(const class Enciclopedia &orig);
    virtual ~Enciclopedia();
    //GETTERS Y SETTERS
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    //METODOS
    void lee(ifstream &arch);
    void actualiza(int aa);
    void imprime(ofstream &arch);
};

//FUNCIONES

#endif /* ENCICLOPEDIA_H */

