/* 
 * File:   Espacio.h
 * Author: Lucas
 *
 * Created on 30 de mayo de 2024, 19:55
 */

#ifndef ESPACIO_H
#define ESPACIO_H

#include <fstream>
using namespace std;

class Espacio {
private:
    char contenido;
    int posx;
    int posy;
public:
    //CONST Y DEST
    Espacio();
    virtual ~Espacio();
    //GETTERS Y SETTERS
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
    //METODOS
    void imprimir(ofstream &arch);
};

//FUNCIONES

#endif /* ESPACIO_H */

