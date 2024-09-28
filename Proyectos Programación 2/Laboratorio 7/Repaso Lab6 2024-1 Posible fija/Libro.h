/* 
 * File:   Libro.h
 * Author: Lucas
 *
 * Created on 30 de mayo de 2024, 19:28
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
using namespace std;

class Libro {
private:
    char * codigo;
    char * nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    //CONST Y DEST
    Libro();
    virtual ~Libro();
    //GETTERS Y SETTERS
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(char * cad);
    void GetNombre(char * cad) const;
    void SetCodigo(char * cad);
    void GetCodigo(char * cad) const;
    //METODOS
    void leer_datos(ifstream &arch);
    void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* LIBRO_H */

