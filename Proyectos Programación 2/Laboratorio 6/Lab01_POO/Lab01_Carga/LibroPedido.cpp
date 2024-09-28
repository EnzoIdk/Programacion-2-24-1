/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   LibroPedido.cpp
 * Author: Enzo
 * 
 * Created on 23 de mayo de 2024, 09:17 PM
 */

#include <cstring>
using namespace std;
#include "LibroPedido.h"
#define NO_ENCONTRADO -1

LibroPedido::LibroPedido() {
    codLibro=nullptr;
    numPedido=0;
}

LibroPedido::LibroPedido(const LibroPedido& orig) {
}

LibroPedido::~LibroPedido() {
    if(codLibro!=nullptr) delete codLibro;
}

void LibroPedido::SetAtendido(bool atendido) {
    this->atendido = atendido;
}

bool LibroPedido::IsAtendido() const {
    return atendido;
}

void LibroPedido::SetPrecio(double precio) {
    this->precio = precio;
}

double LibroPedido::GetPrecio() const {
    return precio;
}

void LibroPedido::SetCodLibro(const char *cod) {
    if(codLibro!=nullptr) delete codLibro;
    codLibro=new char[strlen(cod)+1];
    strcpy(codLibro,cod);
}

void LibroPedido::GetCodLibro(char *cod) const {
    if(codLibro==nullptr) cod[0]=0;
    else strcpy(cod,codLibro);
}

void LibroPedido::SetNumPedido(int numPedido) {
    this->numPedido = numPedido;
}

int LibroPedido::GetNumPedido() const {
    return numPedido;
}

bool LibroPedido::operator >>(class Libro *arrLib){
    int posLibro=buscarLibro(arrLib,codLibro);
    if(posLibro!=NO_ENCONTRADO){
        int stock=arrLib[posLibro].GetStock();
        if(stock>0){
            precio=arrLib[posLibro].GetPrecio();
            atendido=true;
            arrLib[posLibro].SetStock(stock-1);
            return true;
        }
        else{
            atendido=false;
            return false;
        }
    }
}

int buscarLibro(class Libro *arrLib,char *codLibro){
    char codigo[60];
    int i=0;
    while(true){
        arrLib[i].GetCodigo(codigo);
        if(strcmp(codigo,"FIN")==0) break;
        if(strcmp(codLibro,codigo)==0) return i;
        i++;
    }
    return NO_ENCONTRADO;
}