/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 2 de mayo de 2024, 22:06
 */

#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistros.h"

int main(int argc, char** argv) {
    
    void * lista1, * lista2;
    
    crearLista(lista1, leeNum, cmpNum, "RegistroDeFaltas1.csv");
    crearLista(lista2, leeNum, cmpNum, "RegistroDeFaltas2.csv");
    uneLista(lista1, lista2);
    imprimeLista(lista1, imprimeNum, "RepNum.txt");
    
    crearLista(lista1, leeRegistro, cmpRegistro, "RegistroDeFaltas1.csv");
    crearLista(lista2, leeRegistro, cmpRegistro, "RegistroDeFaltas2.csv");
    uneLista(lista1, lista2);
    imprimeLista(lista1, imprimeRegistro, "RepFalta.txt");
    
    return 0;
}

