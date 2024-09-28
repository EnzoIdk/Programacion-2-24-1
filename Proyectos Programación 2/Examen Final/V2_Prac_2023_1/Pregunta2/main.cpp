/* 
 * Proyecto:   main.cpp
 * Author: Jeremy Lopez Galindo
 *
 * Created on 4 de diciembre de 2023, 08:15 PM
 */

#include <iostream>
#include <iomanip>

#include "Registro.h"

using namespace std;

int main(int argc, char** argv) {
    Registro reg;
    reg.carga();
    reg.procesa();
    reg.muestra();
    return 0;
}

