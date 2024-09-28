/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NFalta.cpp
 * Author: ISA
 * 
 * Created on 6 de junio de 2024, 04:04 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "NFalta.h"
#include "Falta.h"
#include "Infraccion.h"
#include "Leve.h"
#include "Grave.h"
#include "MuyGrave.h"
NFalta::NFalta() {
    pfalta = nullptr;
    sig = nullptr;
}

NFalta::NFalta(const NFalta& orig) {
}

NFalta::~NFalta() {
//    if(dfalta != nullptr)delete dfalta;
//    if(nfalta != nullptr)delete nfalta;
}

bool NFalta::operator<=(int cod){
    bool no_error = true;
    switch(cod/100){
        case 1:{
            pfalta = new class Leve;
            break;
        }
        case 2:{
            pfalta = new class Grave;
            break;
        }
        case 3:{
            pfalta = new class MuyGrave;
            break;
        }
        default:{
            no_error = false;
            break;
        }
    }
    if(no_error){
        ifstream arch("Infracciones.csv",ios::in); //Se puede leer varias veces
        if (!arch) {
            cout << "Error en: Infracciones.csv"<< endl;
            exit(1);
        }
        no_error = (pfalta->lee(arch,cod));
        if(not no_error)delete pfalta;
    }
    return no_error;
}

void NFalta::operator>=(ofstream &arch){
    dfalta >= arch;
    pfalta->imprime(arch);
}