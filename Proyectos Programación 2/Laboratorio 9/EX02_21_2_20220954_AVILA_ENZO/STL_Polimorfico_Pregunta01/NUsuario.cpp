/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NUsuario.cpp
 * Author: Enzo
 * 
 * Created on 20 de junio de 2024, 02:09 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NUsuario.h"
#include "Administrativo.h"
#include "Estudiante.h"
#include "Docente.h"

NUsuario::NUsuario() {
    pusuario=nullptr;
}

NUsuario::NUsuario(const NUsuario& orig) {
    pusuario=orig.pusuario;
}

void NUsuario::lee(ifstream& arch){
    int carne;
    char tipo,car,cad[60];
    arch>>carne;
    if(arch.eof()) return;
    arch>>tipo>>car;
    switch(tipo){
        case 'A':
            pusuario=new class Administrativo;
            break;
        case 'D':
            pusuario=new class Docente;
            break;
        case 'E':
            pusuario=new class Estudiante;
            break;
    }
    arch.getline(cad,60,',');
    pusuario->SetCarne(carne);
    pusuario->SetTipo(tipo);
    pusuario->SetNombre(cad);
    pusuario->leer(arch);
}

void NUsuario::imprime(ofstream& arch){
    pusuario->imprime(arch);
}

int NUsuario::ObtenerCarne() const{
    return pusuario->GetCarne();
}