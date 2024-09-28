/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 26 de marzo de 2024, 08:27 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "BibliotecaMemoriaExacta.h"

/*
 * Un puntero no apunta a un arreglo, apunta a un dato
 * Inicializacion estatica:
  p=&x;     
  *p=33;
 * Inicializacion dinámica:
 * p=new int {53}; además de crear el espacio de memoria, se inicializa el valor
 * p=new int [5];
 * 
 * Liberación de un puntero:
 * p=new int;
 * p=new int[50];
 * delete p; deja los valores allí, pero su dirección de memoria ya no es válida,
 * asume que el espacio está libre, al hacer otro new puedes sacar esos valores de nuevo.
 * ya no hacer *p; o p[i];
 * 
 * Recomendable pasar las estructuras por referencia aunque no la modifiquemos (con const mejor)
 * f(const struct St &a){
 *    cout<<a.c                                                         >>
 *    a.c=33; NO
 *    g(a);
 * }
 * 
 * g(const struct St &a){ se debe pasar como const tmbn si se llama a otra función
 * 
 * }
 * 
 * 
 * f(int *const p){  Me va a bloquear el puntero
 *      cout<<*p;                          >>
 *      *p=33;
 *      p[3]=21;
 *      no se puede hacer p=new int;
 * }
 * 
 * clase string #include <string>, no se va a poder usar
 * #include <cstring> esto sí;
 * 
 * 
 * int a[10][10], demasiado ineficiente, la máquina guarda 100x4 espacios de memoria
 * 
 * 
 * ¿Cómo definir un arreglo cuya capacidadsea la misma que la cantidad de datos 
 * que se va a leer?
 * 
 * int *arr,numDatos=0; se empieza definiendo un puntero
 * se crea la función leerDatos(arr,numDatos);
 * void leerDatos(int *&arr,int &numDatos){ 
 * 
 * }
 * 
 * 
 * MÉTODO DE ASIGNACIÓN POR INCREMENTO
 * Este método no busca exactitud, sino tener un mínimo de desperdicio
 * void leerDatos(int *&arr,int &numDatos){
 * 
 * }
 */


int main(int argc, char** argv) {
    int *datos,numDat=0;
//    leerDatosExactos(datos,numDat,"datos.txt");
//    imprimirDatos(datos,numDat);
    leerDatosExactos(datos,"datos.txt");
    imprimirDatos(datos);
    return 0;
}

