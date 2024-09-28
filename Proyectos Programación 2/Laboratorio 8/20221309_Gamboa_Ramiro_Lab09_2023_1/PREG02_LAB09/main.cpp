/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 6 de junio de 2024, 03:19 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Tesoreria.h"
int main(int argc, char** argv) {
    
    Tesoreria OTeso;
    
    OTeso.cargaescalas();
    OTeso.cargaalumnos();
    OTeso.actualizaboleta();
    OTeso.imprimeboleta();
    
    return 0;
}

