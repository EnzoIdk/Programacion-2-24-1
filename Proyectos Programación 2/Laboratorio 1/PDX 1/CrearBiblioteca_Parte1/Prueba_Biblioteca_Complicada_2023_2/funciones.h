
/*/ 
 * Projecto:  Prueba_Biblioteca_Complicada_2023_2
 * Nombre del Archivo:  funciones.h
 * Autor: El Real Candy
/*/

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include "biblioteca.h"

void obtenerDatos(struct Cliente *,const char *);

void obtenerDatos(struct Producto *,const char *);

void obtenerDatos(struct Pedido *,const char *);

void procesarDatos(struct Cliente *,struct Producto *,struct Pedido *);

void imprimirDatos(struct Cliente *,struct Producto *,struct Pedido *,
                   const char *);

void imprimirEncabezado(ofstream &,char);

void imprimirLinea(ofstream &,int,char);

#endif /* FUNCIONESAUXILIARES_H */
