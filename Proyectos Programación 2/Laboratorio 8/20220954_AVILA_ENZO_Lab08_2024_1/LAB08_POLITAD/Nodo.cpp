/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: alulab14
 * 
 * Created on 14 de junio de 2024, 08:06 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Nodo.h"

Nodo::Nodo() {
    plibro=nullptr;
    sig=nullptr;
}

//el destructor de la lista también destruirá los nodos