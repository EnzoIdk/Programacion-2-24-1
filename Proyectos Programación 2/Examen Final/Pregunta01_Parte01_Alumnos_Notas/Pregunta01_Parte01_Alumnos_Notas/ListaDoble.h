    /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDoble.h
 * Author: margo
 *
 * Created on 8 de julio de 2024, 18:49
 */

#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "Nodo.h"
#include <fstream>
using namespace std;
class ListaDoble {
private:
    class Nodo *inicio;
    class Nodo *fin;

public:
    ListaDoble();
    ListaDoble(const ListaDoble& orig);
    virtual ~ListaDoble();
    void impresion(ofstream&);
    void insertarNodo(Alumno&);
    void agregarNotas(int, vector<Nota>&notas);
};
#endif /* LISTADOBLE_H */

