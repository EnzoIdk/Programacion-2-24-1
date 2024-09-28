/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 4 de junio de 2024, 08:22 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Lista.h"
/*
 *Clausula friend: Permite a otras clsaes o funciones independientes
 * acceso total a sus elementos, incluso a los que se encuentran
 * en la zona privada 
 * 
 * La clase a define a las funciones amigan que tendrán acceso a ella
 * 
 * Listas enlazadas:
 *  Clase Lista (*lista) -> Clase Nodo (friend Lista) -> Clase Nodo (friend Lista)
 */

int main(int argc, char** argv) {
    class Lista lista;
    lista.crear("datos.txt");
    lista.imprimir("reporte.txt");
    lista.imprimeR("reporteAlReves.txt");
    return 0;
}

