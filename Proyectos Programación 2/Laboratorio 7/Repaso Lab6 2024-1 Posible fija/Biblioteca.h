/* 
 * File:   Biblioteca.h
 * Author: Lucas
 *
 * Created on 30 de mayo de 2024, 20:15
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Fisica.h"
#include "Calculo.h"
#include "Informatica.h"
#include "Estante.h"

class Biblioteca {
private:
    class Fisica lfisica[20];
    class Calculo lcalculo[20];
    class Informatica linformatica[30];
    class Estante estantes[20];
    int cantidad_estantes;
public:
    //CONST Y DEST
    Biblioteca();
    virtual ~Biblioteca();
    //GETTERS Y SETTERS
    void SetCantidad_estantes(int cantidad_estantes);
    int GetCantidad_estantes() const;
    //METODOS
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();
};

//FUNCIONES

#endif /* BIBLIOTECA_H */

