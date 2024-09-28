/* 
 * File:   Nodo.cpp
 * Author: ramir
 * 
 * Created on 7 de junio de 2024, 11:13 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Nodo.h"

Nodo::Nodo() {
    izq = nullptr;
    der = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

