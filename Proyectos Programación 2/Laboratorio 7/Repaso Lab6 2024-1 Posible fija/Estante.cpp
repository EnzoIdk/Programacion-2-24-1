/* 
 * File:   Estante.cpp
 * Author: Lucas
 * 
 * Created on 30 de mayo de 2024, 19:57
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Estante.h"

//CONST Y DEST

Estante::Estante() {
    espacios=nullptr;
    codigo=nullptr;
    cantidad_libros=0;
}

Estante::~Estante() {
    if(codigo!=nullptr) delete codigo;
    if(espacios!=nullptr) delete [] espacios;
}

//GETTERS Y SETTERS
void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(char * cad) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cad)+1];
    strcpy(codigo, cad);
}

void Estante::GetCodigo(char * cad) const {
    if(codigo==nullptr) cad[0]=0;
    else strcpy(cad, codigo);
}

//METODOS
void Estante::leer_datos(ifstream &arch){
    char cod[4];
    int alt, anch;
    //LECTURA
    arch.getline(cod, 4, ',');
    arch>>alt;
    arch.get();
    arch>>anch;
    arch.get(); //\m
    //GUARDAMOS
    SetCodigo(cod);
    SetAltura(alt);
    SetAnchura(anch);
    //GENERAMOS LOS ESPACIOS
    crear_espacios();
}

void Estante::crear_espacios(){
    if(espacios!=nullptr) delete[] espacios;
    espacios=new class Espacio[altura*anchura+1];
}

void Estante::asignar_libro(class Fisica &libro){
    char cod[10], nombre[60];
    int anchoLib=libro.GetAncho(), altoLib=libro.GetAlto(), 
            inic=espacio_disponible(), temp;
    //ITERACION
    if(inic!=-1 and anchura-inic>=anchoLib){
        libro.GetCodigo(cod);
        libro.GetNombre(nombre);
        for(int i=inic; i<inic+anchoLib; i++){
            for(int j=0; j<altoLib; j++){
                temp=i*altura+j;
                espacios[temp].SetPosx(i);
                espacios[temp].SetPosy(j);
                espacios[temp].SetContenido('*');
            }
        }
        libros[cantidad_libros].SetAlto(altoLib);
        libros[cantidad_libros].SetAncho(anchoLib);
        libros[cantidad_libros].SetCodigo(cod);
        libros[cantidad_libros].SetNombre(nombre);
        libros[cantidad_libros].SetColocado(true);
        cantidad_libros++;
        libro.SetColocado(true);
    }
}

void Estante::asignar_libro(class Calculo &libro){
    char cod[10], nombre[60];
    int anchoLib=libro.GetAncho(), altoLib=libro.GetAlto(), 
            inic=espacio_disponible(), temp;
    //ITERACION
    if(inic!=-1 and anchura-inic>=anchoLib){
        libro.GetCodigo(cod);
        libro.GetNombre(nombre);
        for(int i=inic; i<inic+anchoLib; i++){
            for(int j=0; j<altoLib; j++){
                temp=i*altura+j;
                espacios[temp].SetPosx(i);
                espacios[temp].SetPosy(j);
                espacios[temp].SetContenido('*');
            }
        }
        libros[cantidad_libros].SetAlto(altoLib);
        libros[cantidad_libros].SetAncho(anchoLib);
        libros[cantidad_libros].SetCodigo(cod);
        libros[cantidad_libros].SetNombre(nombre);
        libros[cantidad_libros].SetColocado(true);
        cantidad_libros++;
        libro.SetColocado(true);
    }
}

void Estante::asignar_libro(class Informatica &libro){
    char cod[10], nombre[60];
    int anchoLib=libro.GetAncho(), altoLib=libro.GetAlto(), 
            inic=espacio_disponible(), temp;
    //ITERACION
    if(inic!=-1 and anchura-inic>=anchoLib){
        libro.GetCodigo(cod);
        libro.GetNombre(nombre);
        for(int i=inic; i<inic+anchoLib; i++){
            for(int j=0; j<altoLib; j++){
                temp=i*altura+j;
                espacios[temp].SetPosx(i);
                espacios[temp].SetPosy(j);
                espacios[temp].SetContenido('*');
            }
        }
        libros[cantidad_libros].SetAlto(altoLib);
        libros[cantidad_libros].SetAncho(anchoLib);
        libros[cantidad_libros].SetCodigo(cod);
        libros[cantidad_libros].SetNombre(nombre);
        libros[cantidad_libros].SetColocado(true);
        cantidad_libros++;
        libro.SetColocado(true);
    }
}

int Estante::espacio_disponible(){
    for(int i=0; i<anchura; i++){
        if(espacios[i*altura+1].GetContenido()==' ') return i;
    }
    return -1;
}

void Estante::imprimir(ofstream &arch){
    char cod[10];
    GetCodigo(cod);
    //IMPRESION
    arch<<"Codigo Estante: "<<cod<<setw(29)<<"Cantidad de libros: "<<
            cantidad_libros<<endl;
    arch<<"Dimensiones:    Ancho: "<<anchura<<setw(10)<<"Alto: "<<altura<<endl;
    for(int i=1; i<=altura; i++){
        for(int j=1; j<=anchura; j++){
            espacios[altura*j-i].imprimir(arch);
        }
        arch<<endl;
    }
    arch<<"CODIGO"<<setw(10)<<"NOMBRE"<<setw(36)<<"ANCHO"<<setw(9)<<"ALTO"<<
            endl;
    for(int i=0; libros[i].GetAncho(); i++){
        libros[i].imprimir(arch);
    }
    arch<<endl;
}

//FUNCIONES
