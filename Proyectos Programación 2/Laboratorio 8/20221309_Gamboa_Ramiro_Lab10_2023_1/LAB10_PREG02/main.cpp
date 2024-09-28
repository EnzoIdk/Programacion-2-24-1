/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 8 de junio de 2024, 12:45 AM
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

