/* 
 * File:   Estante.h
 * Author: Lucas
 *
 * Created on 30 de mayo de 2024, 19:57
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include "Fisica.h"
#include "Calculo.h"
#include "Informatica.h"
#include "Espacio.h"

class Estante {
private:
    char * codigo;
    int anchura;
    int altura;
    class Libro libros[20];
    class Espacio * espacios;
    int cantidad_libros;
public:
    //CONST Y DEST
    Estante();
    virtual ~Estante();
    //GETTERS Y SETTERS
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(char* cad);
    void GetCodigo(char * cad) const;
    //METODOS
    void leer_datos(ifstream &arch);
    void crear_espacios();
    void asignar_libro(class Fisica &libro);
    void asignar_libro(class Calculo &libro);
    void asignar_libro(class Informatica &libro);
    int espacio_disponible();
    void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* ESTANTE_H */

