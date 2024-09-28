/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#define NOT_FOUND -1
#define MAX_LINE 200 
using namespace std;

#include "Estructuras.h"
#include "funciones.h"

void rellenarClientes(ifstream &in, struct Cliente p[])
{
    int i=0;
    while( in>>p[i]) i++;
    p[i].dni=0;
}

void rellenarProductos(ifstream &in, struct  Producto p[])
{
     int i=0;
    while(1)
    {
        in>>p[i];
        if (in.eof()) break;
        i++;
    }
      strcpy(p[i].codigo, "XXXXXXX");
}

void rellenarPedidos(ifstream &in, struct Pedido p[], struct Cliente clientes[], struct Producto productos[])
{
    int i=0;
    while(in>>p[i])
    {    
         productos+=p[i];
         clientes+=p[i];
//         productos+=p[i];
        i++;
    }
}

void  impresionCliente(ofstream &archImp, struct Cliente clientes[]){
    archImp<<setw((MAX_LINE+19)/2)<<"REPORTE DE CLIENTES"<<endl;
    archImp<<setw(7)<<right<<"DNI"<<setw(27)<<"Nombre"
            <<setw(26)<<"Telefono"<<setw(19)<<"Monto total"<<' '<<"Lista de productos entregados"<<endl;
      linea(MAX_LINE, '=', archImp);
    for (int i = 0;clientes[i].dni!=0; i++){
        archImp<<clientes[i];
        linea(MAX_LINE, '-', archImp);
    }
    archImp<<endl;
}
void  impresionProductos(ofstream &archImp, struct Producto productos[]){
    archImp<<setw((MAX_LINE+20)/2)<<right<<"REPORTE DE PRODUCTOS"<<endl;
    archImp<<setw(12)<<right<<"Codigo"<<setw(30)<<"Descripcion"<<setw(29)<<"Precio"<<setw(12)
            <<"Stock"<<endl;
      linea(MAX_LINE, '=', archImp);
    for (int i = 0;strcmp(productos[i].codigo, "XXXXXXX")!=0; i++){
        archImp<<productos[i];
          linea(MAX_LINE, '-', archImp);
    }
    archImp<<endl;
}

void linea(int cant, char simb, ofstream &archImp){
    for (int i = 0; i < cant; i++) {
        archImp<<simb;
    }
    archImp<<endl;

}