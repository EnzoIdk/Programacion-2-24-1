/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 30 de abril de 2024, 08:25 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConCadenas.h"
#include "ListaConRegistrosVoid.h"

int main(int argc, char** argv) {
    void *lista;
    crearLista("datos.txt",lista,leeEnteros,intcmp);
    imprimirLista(lista,imprimeInt);
    eliminarLista(lista,eliminaInt);
    crearLista("personas.txt",lista,leeCad,cadcmp);
    imprimirLista(lista,imprimeCad);
    eliminarLista(lista,eliminaCad);
    crearLista("personal.csv",lista,leeReg,regNombcmp);
    imprimirLista(lista,imprimeReg);
    eliminarLista(lista,eliminaReg);
    return 0;
}

