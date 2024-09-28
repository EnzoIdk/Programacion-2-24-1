
/*/ 
 * Projecto:  BibEstaticaEnUnaAplicacion
 * Nombre del Archivo:  funciones.h
 * Autor: El Real Candy
/*/

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "biblioteca.h"

void obtenerDatos(struct Cliente *,const char *);

void obtenerDatos(struct Producto *,const char *);

void obtenerDatos(struct Pedido *,const char *);

void procesarDatos(struct Cliente *,struct Producto *,struct Pedido *);

void imprimirDatos(struct Cliente *,struct Producto *,struct Pedido *,
                   const char *);

void imprimirEncabezado(ofstream &,char);

void imprimirLinea(ofstream &,int,char);

#endif /* FUNCIONES_H */
