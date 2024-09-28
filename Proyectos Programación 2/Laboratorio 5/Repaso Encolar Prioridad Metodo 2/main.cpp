/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 1 de mayo de 2024, 17:53
 */

#include <iostream>
using namespace std;

#include "funcionesCola.h"

/*
 * 
 */

int main(int argc, char** argv) {
    
    void * cola;
    
    construirCola(cola);
    
    encolar(cola, 'A', 71337111);
    encolar(cola, 'V', 12567891);
    encolar(cola, 'N', 66611166);
    encolar(cola, 'V', 22165455);
    encolar(cola, 'V', 66548422);
    encolar(cola, 'A', 71665444);
    encolar(cola, 'V', 54154777);
    encolar(cola, 'N', 82517891);
    encolar(cola, 'A', 22687891);
    
    imprimirCola(cola);
    
    return 0;
}

