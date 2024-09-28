/* 
 * File:   Biblioteca.cpp
 * Author: Lucas
 * 
 * Created on 30 de mayo de 2024, 20:15
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "Biblioteca.h"

//CONST Y DEST
Biblioteca::Biblioteca() {
    cantidad_estantes=0;
}

Biblioteca::~Biblioteca() {

}

//GETTERS Y SETTERS
void Biblioteca::SetCantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::GetCantidad_estantes() const {
    return cantidad_estantes;
}

//METODOS
void Biblioteca::cargar_libros(){
    ifstream arch("libros.csv", ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con libros.csv";
        exit(1);
    }
    char tipo[60];
    int nfis=0, ncal=0, ninf=0;  
    //FISICA, CBA123, El libro de la Sierra, 1, 4, Prof. Calderon
    while(true){
        arch.getline(tipo, 60, ',');
        if(arch.eof()) break;
        arch.get(); // ' '
        if(strcmp(tipo, "FISICA")==0){ //FISICA
            lfisica[nfis].leer_datos(arch);
            nfis++;
        }
        else if(strcmp(tipo, "INFORMATICA")==0){ //INFORMATICA
            linformatica[ninf].leer_datos(arch);
            ninf++;
        } 
        else{ //CALCULO
            lcalculo[ncal].leer_datos(arch);
            ncal++;
        }
    }
}

void Biblioteca::cargar_estantes(){
    ifstream arch("estantes.csv", ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con estantes.csv";
        exit(1);
    }
    int nest=0;
    //CCC, 10, 10
    while(true){
        estantes[cantidad_estantes].leer_datos(arch);
        if(arch.eof()) break;
        cantidad_estantes++;
    }
    //CREACION 
}
void Biblioteca::posicionar_libros(){
    for(int i=0; i<cantidad_estantes; i++){
        for(int j=0; lfisica[j].GetAncho() ; j++){
            if(not lfisica[j].IsColocado()){
                estantes[i].asignar_libro(lfisica[j]);
            }
        }
        for(int j=0; lcalculo[j].GetAncho() ; j++){
            if(not lcalculo[j].IsColocado()){
                estantes[i].asignar_libro(lcalculo[j]);
            }
                
        } 
        for(int j=0; linformatica[j].GetAncho() ; j++){
            if(not linformatica[j].IsColocado()){
                estantes[i].asignar_libro(linformatica[j]);
            }
        } 
    }
}
void Biblioteca::mostrar_datos(){
    ofstream arch("Reporte.txt", ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: Reporte.txt";
        exit(1);
    }
    //IMPRESION
    for(int i=0; i<cantidad_estantes; i++){
        estantes[i].imprimir(arch);
    }
    arch<<endl;
    //LIBROS
    arch<<"Informacion de todos los libros"<<endl;
    for(int i=0; lcalculo[i].GetAncho(); i++){
        lcalculo[i].imprimir(arch);
    }
    for(int i=0; lfisica[i].GetAncho(); i++){
        lfisica[i].imprimir(arch);
    }
    for(int i=0; linformatica[i].GetAncho(); i++){
        linformatica[i].imprimir(arch);
    }
}

//FUNCIONES
