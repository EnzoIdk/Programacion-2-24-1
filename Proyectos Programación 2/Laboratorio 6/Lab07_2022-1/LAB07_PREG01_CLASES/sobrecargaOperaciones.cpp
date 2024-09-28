/* 
 * Proyecto: LAB07_PREG01_CLASES
 * File:   sobrecargaOperaciones.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 10 de junio de 2022, 8:13
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

ifstream & operator >>(ifstream &arch, Cliente &f) {
    int dni;
    char categoria, cad[100];

    arch >> dni;
    if (!arch.eof()) {
        arch.get(); // leemos la coma
        arch.getline(cad, 100, ','); // leemos el nombre
        
        arch >> categoria;
        
        f.SetDni(dni);
        f.SetNombre(cad);
        f.SetCategoria(categoria);
    }
    return arch;
}

ifstream & operator >>(ifstream &arch, Pedido &f) {
    int codigo, cantidad, dni, dd, mm, aa, fecha;
    char cad[100], car;
    double precio;

    arch >> codigo;
    if (!arch.eof()) {
        arch.get(); // leemos la coma
        arch.getline(cad, 100, ','); // leemos el nombre
        
        arch >> cantidad >> car >> precio >> car >> dni >> car >> dd >> car >> mm >> car >> aa;
        fecha = dd + mm*100 + aa*10000;
        
        f.SetCodigo(codigo);
        f.SetNombre(cad);
        f.SetCantidad(cantidad);
        f.SetPrecio(precio);
        f.SetDni(dni);
        f.SetFecha(fecha);
    }
    return arch;
}

// ---------------------------------------------------------------------------

ofstream & operator <<(ofstream &arch, const Cliente &f) {
    char categoria, cad[100];
    
    arch << setw(10) << f.GetDni();
    f.GetNombre(cad);
    arch << setw(60) << cad << " DEL " << f.GetCategoria() << endl;
    for (int i = 0; i < 120; i++) arch.put('=');
    arch << endl;
    
    f.imprimirPedidos(arch);
    
    arch << "# de pedidos: " << f.GetNumPed() << endl; 
    arch << "Monto total : " << f.GetTotal() << endl; 

    return arch;
}