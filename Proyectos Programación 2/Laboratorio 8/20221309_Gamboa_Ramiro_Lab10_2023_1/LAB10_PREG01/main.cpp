/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 7 de junio de 2024, 11:05 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Tesoreria.h"
int main(int argc, char** argv) {
    
    Tesoreria ABoleta;
    
    ABoleta.cargaalumnos();
    ABoleta.actualizaboleta();
    ABoleta.imprimeboleta();
    
    return 0;
}

