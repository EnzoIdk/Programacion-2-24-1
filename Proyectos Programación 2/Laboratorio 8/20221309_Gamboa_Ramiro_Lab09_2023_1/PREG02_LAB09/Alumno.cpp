/* 
 * File:   Alumno.cpp
 * Author: ramir
 * 
 * Created on 5 de junio de 2024, 02:43 PM
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
    escala = 0;
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
//202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,
void Alumno::lee(ifstream &archBol){
    char nomb[40],c;
    
    archBol>>codigo;
    archBol.get();
    archBol.getline(nomb,40,',');
    SetNombre(nomb);
    archBol>>escala>>c>>creditos>>c;
}

void Alumno::imprime(ofstream &archRep){
    archRep<<left<<setw(18)<<codigo<<setw(40)<<nombre<<setw(10)<<escala
           <<setw(9)<<creditos;
}

void Alumno::actualiza(double costoXCred){
    
}