/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Procesa.cpp
 * Author: Enzo
 * 
 * Created on 29 de junio de 2024, 05:12 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Procesa.h"
#include "Revista.h"
#include "Estante.h"

Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}

void Procesa::carga(){
    ifstream arch("Libros3.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros3.csv"<<endl;
        exit(1);
    }
    class Revista aux;
    while(true){
        aux.lee(arch);
        if(arch.eof()) break;
        mrevista[aux.GetISSN()]=aux;
        //si se usa el insert, sobrecargar el <
        //si se usa asignación, se sobrecarga el =
        
        //con list, se sobrecarga el copia
    }
}

void Procesa::muestra(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se puede abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    for(map<string,Revista>::iterator it=mrevista.begin();
            it!=mrevista.end();it++){
        (*it).second.imprime(arch);
    }
}

void Procesa::cargaEstante(){
    ifstream arch("Estantes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"No se puede abrir el archivo Estante2.csv"<<endl;
        exit(1);
    }
    class Estante aux;
    //el map inserta ordenado, si se trabaja con 
    // int,string,etc para el first
    // no es necesario sobrecargar algún < o =; pero
    //con clases sí
    while(true){
        aux.leestante(arch);
        vector<Libro> vaux; //solo para rellenar
        if(arch.eof()) break;
        mestante[aux]=vaux;
    }
}

void Procesa::cargaLibros(){
    ifstream arch("Libros4.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros4.csv"<<endl;
        exit(1);
    }
    class Libro aux;
    while(true){
        aux.lee(arch);
        if(arch.eof()) break;
        for(map<Estante,vector<Libro>>::iterator it=mestante.begin();
                it!=mestante.end();it++){
            //la capacidad está dentro del first (Estante) 
            double capacidad=(*it).first.getCapacidad();
            double total=0;
            //el second es el vector
            for(int i=0;i<(*it).second.size();i++){
                total+=(*it).second[i].GetPeso();
            }
            if(capacidad>=total+aux.GetPeso()){
                (*it).second.push_back(aux);
                break;
            }
            
        }
    }
}

void Procesa::muestraLibros(){
    ofstream arch("Reporte2.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte2.txt"<<endl;
        exit(1);
    }
    for(map<Estante,vector<Libro>>::iterator it=mestante.begin();
            it!=mestante.end();it++){
        (*it).first.imprime(arch);
        for(int i=0;i<(*it).second.size();i++){
            (*it).second[i].imprime(arch);
        }
    }
    Estante aux;
    vector<Libro> vlibro;
    aux.setId(1);
    vlibro=mestante[aux];
    arch<<vlibro.size()<<endl;
}