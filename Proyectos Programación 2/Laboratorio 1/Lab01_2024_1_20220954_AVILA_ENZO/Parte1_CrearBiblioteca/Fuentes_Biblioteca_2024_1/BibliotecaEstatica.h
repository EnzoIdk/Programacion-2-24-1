/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaEstatica.h
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 5 de abril de 2024, 08:08 AM
 */

#ifndef BIBLIOTECAESTATICA_H
#define BIBLIOTECAESTATICA_H

bool operator >>(ifstream &arch,struct Libro &libro);
bool operator >>(ifstream &arch,struct Cliente &cliente);
bool operator >>(struct LibroSolicitado &libroPedido,struct Libro *libros);
int buscarLibro(struct Libro *libros,char *codigo);
bool operator <<(struct Cliente &cliente,struct LibroSolicitado &pedido);
void operator ++(struct Cliente &cliente);
void operator <<(ofstream &arch,struct Libro libro);
void operator <<(ofstream &arch,struct Cliente cliente);


#endif /* BIBLIOTECAESTATICA_H */

