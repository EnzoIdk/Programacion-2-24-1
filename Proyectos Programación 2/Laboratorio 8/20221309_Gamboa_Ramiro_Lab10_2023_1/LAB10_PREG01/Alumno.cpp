/* 
 * File:   Alumno.cpp
 * Author: ramir
 * 
 * Created on 7 de junio de 2024, 11:05 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    codigo = 0;
    nombre = nullptr;
    escala = 1;
    creditos = 0.0;
    total = 0.0;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    if(nombre) delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::SetNombre(char *cad){
    if(nombre) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}
    
void Alumno::GetNombre(char *cad) const{
    if(nombre) strcpy(cad,nombre);
    else cad[0] = '\0';
}
//202119153,MENDOZA/ARIAS/HENRY,4,19.5,
void Alumno::lee(ifstream &archAlum){
    char nomb[40],c;
    
    archAlum>>codigo;
    archAlum.get();
    archAlum.getline(nomb,40,',');
    SetNombre(nomb);
    archAlum>>escala>>c>>creditos>>c;
}

void Alumno::imprime(ofstream &archRep){
    archRep<<fixed<<setprecision(2);
    archRep<<left<<setw(10)<<codigo<<setw(40)<<nombre<<right<<setw(3)<<escala
           <<setw(12)<<creditos;
}