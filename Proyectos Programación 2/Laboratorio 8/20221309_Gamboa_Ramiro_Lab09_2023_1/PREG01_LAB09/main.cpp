/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 5 de junio de 2024, 02:42 PM
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

