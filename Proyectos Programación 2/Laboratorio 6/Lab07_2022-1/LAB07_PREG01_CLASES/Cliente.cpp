/* 
 * Proyecto: LAB07_PREG01_CLASES
 * File:   Cliente.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 10 de junio de 2022, 8:05
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Cliente.h"
#include "Pedido.h"

#include "sobrecargaOperaciones.h"

Cliente::Cliente() {
    dni = 0;
    nombre = nullptr;
    numPed = 0;
    total = 0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    if(nombre != nullptr) delete nombre;
}

// --------------------------------------------------------------------------

void Cliente::SetTotal(double total) {
    this->total = total;
}

double Cliente::GetTotal() const {
    return total;
}

void Cliente::SetNumPed(int numPed) {
    this->numPed = numPed;
}

int Cliente::GetNumPed() const {
    return numPed;
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::SetNombre(const char *cad) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Cliente::GetNombre(char *cad) const {
    if (nombre == nullptr) cad[0] = 0; //Cadena vacía
    else strcpy(cad, nombre);
}

// --------------------------------------------------------------------------

void Cliente::operator =(const Pedido &ped){
    char cad[150];

    ped.GetNombre(cad);
    lped[numPed].SetCodigo(ped.GetCodigo());
    lped[numPed].SetNombre(cad);
    lped[numPed].SetCantidad(ped.GetCantidad());
    lped[numPed].SetPrecio(ped.GetPrecio());
    lped[numPed].SetDni(ped.GetDni());
    lped[numPed].SetFecha(ped.GetFecha());

    total += lped[numPed].GetCantidad() * lped[numPed].GetPrecio();
    numPed++;
}

void Cliente::operator -=(const Pedido &ped){
    int d = ped.GetDni(), c = ped.GetCantidad(), f = ped.GetFecha();
    
    for(int i=0; lped[i].GetCodigo(); i++){
        if(lped[i].GetDni() == d && lped[i].GetCodigo() == c && lped[i].GetFecha() == f){
            int j;
            for(j=i; j<numPed-1; j++){
                char cad[150];
                lped[j+1].GetNombre(cad);
                lped[j].SetCodigo(lped[j+1].GetCodigo());
                lped[j].SetNombre(cad);
                lped[j].SetCantidad(lped[j+1].GetCantidad());
                lped[j].SetPrecio(lped[j+1].GetPrecio());
                lped[j].SetDni(lped[j+1].GetDni());
                lped[j].SetFecha(lped[j+1].GetFecha());
            }
            lped[numPed].SetCodigo(0);
            numPed--;
            break;
        }
    }
}

void Cliente::operator /(double descuento){
    double precio;
    for(int i=0; lped[i].GetCodigo(); i++){
        precio = lped[i].GetPrecio();
        precio *= (1-(descuento/100));
        lped[i].SetPrecio(precio);
    }
    total = (1-(descuento/100))*total;
}

// --------------------------------------------------------------------------

void Cliente::imprimirPedidos(ofstream &arch) const{
    char cad[150];
    for(int i=0; lped[i].GetCodigo(); i++){
        lped[i].imprimirFecha(arch);
        arch << "  " << left << setw(10) << lped[i].GetCodigo();
        lped[i].GetNombre(cad);
        arch << setw(50) << cad << right << 
                setw(10) << lped[i].GetCantidad() << 
                setw(10) << lped[i].GetPrecio() << endl;
    }
}