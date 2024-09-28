
/*/ 
 * Projecto:  Biblioteca_Compilada_2023_2
 * Nombre del Archivo:  biblioteca.h
 * Autor: El Real Candy
/*/

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Estructuras.h"

bool operator >>(ifstream &,struct Cliente &);

bool operator >>(ifstream &,struct Producto &);

bool operator >>(ifstream &,struct Pedido &);

void operator +=(struct Cliente *,struct Pedido);

void operator +=(struct Producto *,struct Pedido &);

bool operator <<(ofstream &,const struct Cliente &);

bool operator <<(ofstream &,const struct Producto &);

#endif /* BIBLIOTECA_H */
