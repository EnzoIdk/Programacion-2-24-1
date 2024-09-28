/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 5 de abril de 2024, 08:06 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#include "Estructuras.h"
#include "BibliotecaEstatica.h"
#define NO_ENCONTRADO -1


bool operator >>(ifstream &arch,struct Libro &libro){
    arch.getline(libro.codigo,8,',');
    if(arch.eof()){
        strcpy(libro.codigo,"FIN");
        return false;
    }
    arch.getline(libro.tiltulo,80,',');
    arch.getline(libro.autor,60,',');
    arch>>libro.stock;
    arch.get();
    arch>>libro.precio;
    arch.get();
    return true;
}

bool operator >>(ifstream &arch,struct Cliente &cliente){
    arch>>cliente.dni;
    if(arch.eof()) return false;
    arch.get();
    arch.getline(cliente.nombre,60);
    cliente.cantDeLibros=0;
    cliente.pagoTotal=0;
    return true;
}

bool operator >>(struct LibroSolicitado &libroPedido,struct Libro *libros){
    int posLibro=buscarLibro(libros,libroPedido.codigoDelLibro);
    if(posLibro!=NO_ENCONTRADO){
        if(libros[posLibro].stock>0){
            libroPedido.precio=libros[posLibro].precio;
            libroPedido.atendido=true;
            libros[posLibro].stock--;
            return true;
        }
        else{
            libroPedido.atendido=false;
        }
        return false;
    }
}

int buscarLibro(struct Libro *libros,char *codigo){
    for(int i=0;strcmp(libros[i].codigo,"FIN")!=0;i++){
        if(strcmp(codigo,libros[i].codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

bool operator <<(struct Cliente &cliente,struct LibroSolicitado &pedido){
    if(cliente.cantDeLibros<30){
        cliente.librosSolicitados[cliente.cantDeLibros]=pedido;
        cliente.cantDeLibros++;
        return true;
    }
    else return false; /*arreglo lleno*/
}

void operator ++(struct Cliente &cliente){
    for(int i=0;i<cliente.cantDeLibros;i++){
        cliente.pagoTotal+=cliente.librosSolicitados[i].precio;
    }
}

void operator <<(ofstream &arch,struct Libro libro){
    arch<<setprecision(2)<<fixed;
    arch<<libro.codigo<<setw(3)<<' '<<left<<setw(60)<<libro.tiltulo<<setw(60)<<
            libro.autor<<right<<setw(4)<<libro.stock<<setw(15)<<libro.precio<<endl;
}

void operator <<(ofstream &arch,struct Cliente cliente){
    arch<<setprecision(2)<<fixed;
    arch<<cliente.dni<<setw(4)<<' '<<cliente.nombre<<endl;
    arch<<"Libros entregados:"<<endl<<setw(7)<<' '<<"Pedido No."<<setw(4)<<' '
            <<"Codigo"<<setw(5)<<' '<<"Precio"<<endl;
    for(int i=0;i<cliente.cantDeLibros;i++){
        if(cliente.librosSolicitados[i].atendido){
            arch<<setw(10)<<' '<<setfill('0')<<setw(5)<<cliente.librosSolicitados[i].numeroDePedido<<
                    setfill(' ')<<setw(6)<<' '<<left<<setw(10)<<
                    cliente.librosSolicitados[i].codigoDelLibro<<
                    right<<setw(7)<<cliente.librosSolicitados[i].precio<<endl;
        }
    }
    arch<<"Total a pagar: "<<setw(15)<<cliente.pagoTotal<<endl;
    arch<<"Libros no entregados por falta de stock: "<<endl;
    arch<<setw(7)<<' '<<"Pedido No."<<setw(4)<<' '<<"Codigo"<<endl;
    for(int i=0;i<cliente.cantDeLibros;i++){
        if(!cliente.librosSolicitados[i].atendido){
            arch<<setw(10)<<' '<<setfill('0')<<setw(5)<<cliente.librosSolicitados[i].numeroDePedido<<
                    setfill(' ')<<setw(6)<<' '<<cliente.librosSolicitados[i].codigoDelLibro<<endl;
        }
    }
}