/* 
 * File:   Ficha.h
 * Author: Lucas
 *
 * Created on 8 de junio de 2024, 21:32
 */

#ifndef FICHA_H
#define FICHA_H

#include <fstream>

class Ficha {
private:
    char * id;
    int fila;
    int columna;
public:
    //CONSTRUCTOR, COPIA, DESTRUCTOR
    Ficha();
    Ficha(const class Ficha &orig);
    virtual ~Ficha();
    //GETTERS Y SETTERS
    void SetColumna(int columna);
    int GetColumna() const;
    void SetFila(int fila);
    int GetFila() const;
    void SetId(char * cad);
    void GetId(char * cad) const;
    //METODOS
    virtual void imprimir(std::ofstream &arch)=0;
    virtual void mover(char direccion, int casillas)=0;
    void asignar(char * id, int fila, int columna);
    void imprimirDatos(std::ofstream &arch);
};

//FUNCIONES

#endif /* FICHA_H */

