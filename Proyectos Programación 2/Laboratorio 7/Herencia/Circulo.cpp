/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Circulo.cpp
 * Author: aml
 * 
 * Created on 21 de mayo de 2024, 08:50 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Circulo.h"
#include <cstring>
#define PI 3.1415

Circulo::Circulo() {
    cout<<"Estoy en la clase base"<<endl;
    nombre=nullptr;
}

Circulo::Circulo(const char *nomb, double rad){
    cout<<"Estoy en el constructor con P. de la clase Base"<<endl;
    nombre=nullptr;
    SetNombre(nomb);
    SetRadio(rad);
}

/*Constructor copia*/
Circulo::Circulo(const Circulo& orig) {
    nombre=nullptr; /*se inicializan en ambos*/
    *this=orig; /*luego de haber sobrecargado todos los operadores,
                 solo se hace esto*/
}

/*Destructor*/
Circulo::~Circulo() {
    if(nombre!=nullptr) delete nombre;
    cout<<"Estoy en el destructor de la clase base"<<endl;
}

void Circulo::SetRadio(double radio){
    this->radio=radio;
}

double Circulo::GetRadio() const{
    return radio;
}

void Circulo::operator=(const Circulo& orig){
    char nomb[100];
    radio=orig.GetRadio();
    orig.GetNombre(nomb);
    SetNombre(nomb);
}

void Circulo::SetNombre(const char *nomb){
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Circulo::GetNombre(char *nomb) const{
    if(nombre==nullptr) nomb[0]=0;
    strcpy(nombre,nomb);
}

double Circulo::area(){
    return PI*radio*radio;
}

double Circulo::circunferencia(){
    return 2*PI*radio;
}

void Circulo::mostrarResultados(){
    cout<<setprecision(2)<<fixed;
    cout<<"Radio: "<<setw(10)<<radio<<endl;
    cout<<"Nombre: "<<left<<setw(20)<<nombre<<right<<endl;
    cout<<"Area: "<<setw(10)<<area()<<endl;
    cout<<"Circunferencia: "<<setw(10)<<circunferencia()<<endl;
}