
/*/ 
 * Projecto:  Biblioteca_Compilada_2023_2
 * Nombre del Archivo:  biblioteca.h
 * Autor: El Real Candy
/*/

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "AperturaDeArchivos.h"
#include "Estructuras.h"

bool operator >>(ifstream &,struct Cliente &);

bool operator >>(ifstream &,struct Producto &);

bool operator >>(ifstream &,struct Pedido &);

void operator +=(struct Cliente *,struct Pedido);

void operator +=(struct Producto *,struct Pedido &);

bool operator <<(ofstream &,const struct Cliente &);

bool operator <<(ofstream &,const struct Producto &);

void obtenerDatos(struct Cliente *,const char *);

void obtenerDatos(struct Producto *,const char *);

void obtenerDatos(struct Pedido *,const char *);

void procesarDatos(struct Cliente *,struct Producto *,struct Pedido *);

void imprimirDatos(struct Cliente *,struct Producto *,struct Pedido *,
                   const char *);

void imprimirEncabezado(ofstream &,char);

void imprimirLinea(ofstream &,int,char);

#endif /* BIBLIOTECA_H */
