/* 
 * File:   Informatica.cpp
 * Author: Lucas
 * 
 * Created on 30 de mayo de 2024, 19:47
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Informatica.h"
#include "Libro.h"

//CONST Y DEST
Informatica::Informatica() {
    curso=nullptr;
}

Informatica::~Informatica() {
    if(curso!=nullptr) delete curso;
}

//GETTERS Y SETTERS
void Informatica::SetCurso(char * cad) {
    if(curso!=nullptr) delete curso;
    curso=new char[strlen(cad)+1];
    strcpy(curso, cad);
}

void Informatica::GetCurso(char * cad) const {
    if(curso==nullptr) cad[0]=0;
    else strcpy(cad, curso);
}

//METODOS
void Informatica::leer_datos(ifstream &arch){
    char curso[60];
    //LEEMOS
    Libro::leer_datos(arch);
    arch.get(); //' '
    arch.getline(curso, 60, '\n');
    //GUARDAMOS
    SetCurso(curso);
}

void Informatica::imprimir(ofstream &arch){
    char cur[60];
    GetCurso(cur);
    Libro::imprimir(arch);
    arch<<"Curso: "<<cur<<endl<<endl;
}

//FUNCIONES
