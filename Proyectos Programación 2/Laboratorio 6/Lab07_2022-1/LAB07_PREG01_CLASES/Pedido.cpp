/* 
 * Proyecto: LAB07_PREG01_CLASES
 * File:   Pedido.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 10 de junio de 2022, 8:06
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

Pedido::Pedido() {
    codigo = 0;
    nombre = nullptr;
    cantidad = 0;
    precio = 0;
    dni = 0;
    fecha = 0;
}

Pedido::Pedido(const Pedido& orig) {
    if(nombre != nullptr) delete nombre;
}

Pedido::~Pedido() {
}

// ---------------------------------------------------------------------------

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetPrecio(double precio) {
    this->precio = precio;
}

double Pedido::GetPrecio() const {
    return precio;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::SetNombre(const char *cad) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Pedido::GetNombre(char *cad) const {
    if (nombre == nullptr) cad[0] = 0; //Cadena vacía
    else strcpy(cad, nombre);
}

// ---------------------------------------------------------------------------

void Pedido::imprimirFecha(ofstream &arch) const{
    int dd, mm, aa;
    dd = fecha%100;
    mm = (fecha / 100)%100;
    aa = (fecha / 100)/100;
    arch << right << setfill('0') << setw(2) << dd << "/" << 
            setw(2) << mm << "/" 
            << setw(4) << aa << setfill(' ');
}