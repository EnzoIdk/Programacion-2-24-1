/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cilindro.cpp
 * Author: aml
 * 
 * Created on 21 de mayo de 2024, 09:30 AM
 */

#include <iomanip>
#include <iostream>

using namespace std;
#include "Cilindro.h"

Cilindro::Cilindro() {
    cout<<"Estoy en la clase derivada"<<endl;
    altura=0;
}

/*esto ya no va*/
//Cilindro::Cilindro(const Cilindro& orig) {
//    
//}

Cilindro::Cilindro(const char* nomb, double rad, double alt):Circulo(nomb,rad){
    cout<<"Estoy en el constructor CP de la clase derivada"<<endl;
    SetAltura(alt);
}

Cilindro::~Cilindro() {
    cout<<"Estoy en el destructor de la clase derivada"<<endl;
}

void Cilindro::SetAltura(double altura){
    this->altura=altura; /*se usa el this si colocamos el mismo nombre al atributo y variable*/
}

double Cilindro::GetAltura() const{
    return altura;
}

/*halla toda el área de la superficie del cilindro*/
double Cilindro::area(){
    return 2*Circulo::area()+altura*circunferencia();
}

double Cilindro::volumen(){
    return Circulo::area()*altura;
}

void Cilindro::mostrarResultados(){
    Circulo::mostrarResultados();
    cout<<"Altura: "<<setw(10)<<altura<<endl;
    cout<<"Volumen: "<<setw(10)<<volumen()<<endl;
    cout<<"Área de la superficie:"<<setw(10)<<area()<<endl;
}



