/* 
 * File:   medicamento.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 10:05 PM
 */

#include "medicamento.h"
#include <cstring>
medicamento::medicamento() {
    cantidad=0;
    codigo=0;
    nombre=nullptr;
}

medicamento::~medicamento() {
    if(nombre)delete nombre;
}

void medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int medicamento::GetFecha() const {
    return fecha;
}

void medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double medicamento::GetPrecio() const {
    return precio;
}

void medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int medicamento::GetCantidad() const {
    return cantidad;
}

void medicamento::GetNombreMedicamento(char* cad) const{
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void medicamento::SetNombreMedicamento(char* cad) {
    if(nombre)delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}

