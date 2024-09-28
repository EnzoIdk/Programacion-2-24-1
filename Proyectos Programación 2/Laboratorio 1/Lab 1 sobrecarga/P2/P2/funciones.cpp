/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#define NOT_FOUND -1
using namespace std;

#include "Estructuras.h"
#include "funciones.h"


bool operator >>(ifstream &in, struct Cliente &C)
{
    //79464412,PORTUGAL RAFFO ALEXANDER,3902394
    in>>C.dni;
    if (in.eof()) return false;
    in.get();
    in.getline(C.nombre, 60, ',');
    in>>C.telefono;
     in.get();
     C.cantidadProductosEntrgados=0;
     C.montoTotal=0;
//     cout<<C.dni<<' '<<C.nombre<<' '<<C.telefono<<endl;
    return true; // solo si se logra almacenar todo, o sea se lee bien, se guarda
}

bool operator >>(ifstream &in, struct Pedido &p)
{
    //JXD-139,50375303
    in.getline(p.CodigoProducto, 8,',');
    if (in.eof()) return false;
    in>>p.dniCliente;
    p.precioProducto=0;
     in.get();
//     cout<<p.CodigoProducto<<' '<<p.dniCliente<<endl;
     return true;
}

bool operator >>(ifstream &in, struct Producto &p)
{
    //BIT-434,Campana Extractora modelo Glass,375.09,10
    in.getline(p.codigo,8,','); //recuerda que es uno más
    if (in.eof()) return false;
     in.getline(p.descripcion, 100,',');
     in>>p.precio;
     in.get();
     in>>p.stock;
     in.get(); 
     p.cantidadClientesServidos=0;
     p.cantidadClientesNoServidos=0;
    
//     cout<<p.codigo<<' '<<p.descripcion<<' '<<p.precio<<' '<<p.stock<<endl;
     return true;
}

bool operator +=(struct Producto pr[], struct Pedido &pe)
{
    int idProd=buscarPro(pe.CodigoProducto, pr);
    int servidos=pr[idProd].cantidadClientesServidos;
    int Noservidos=pr[idProd].cantidadClientesNoServidos;
    pe.precioProducto=pr[idProd].precio;
    if (pr[idProd].stock>0 and idProd!=NOT_FOUND)
    {
//        cout<<"ingreso"<<endl;
        pr[idProd].clientesServidos[servidos]=pe.dniCliente;
        pr[idProd].cantidadClientesServidos++;
        pr[idProd].stock--;
        return true;
    }else{
        pr[idProd].clientesNoServidos[Noservidos]=pe.dniCliente;
        pr[idProd].cantidadClientesNoServidos++;
        return false;
    }
}

int buscarPro(char codigo[], struct Producto c[])
{
    for (int i = 0; strcmp("XXXXXXX",c[i].codigo)!=0; i++) {
        if (strcmp(codigo,c[i].codigo)==0) {
            return i;
        }
    }
    return NOT_FOUND;

}
void operator += (struct Cliente c[], struct Pedido &p)
{
    int idCliente=buscarPedido(p.dniCliente,c);
    int pedidos=c[idCliente].cantidadProductosEntrgados;
    if (idCliente!=-1)
    {
        strcpy(c[idCliente].productosEntregados[pedidos].codigo,p.CodigoProducto);
        c[idCliente].productosEntregados[pedidos].precio=p.precioProducto;
        c[idCliente].montoTotal+=p.precioProducto;
        c[idCliente].cantidadProductosEntrgados++;
    }
}

int buscarPedido(int dni, struct Cliente c[])
{
    for (int i = 0; c[i].dni!=0; i++) {
        if (dni==c[i].dni) {
            return i;
        }
//        cout<<c[i].dni<<endl;
    }
    return NOT_FOUND;
}

void operator <<(ofstream &out, struct Cliente &p)
{
    int flag=0;
    out<<setprecision(2)<<fixed;
    out<<setw(12)<<right<<p.dni<<setw(3)<<' '<<left<<p.nombre<<setw(40-strlen(p.nombre))<<' ';
           out<<setw(10)<<p.telefono<<right<<setw(15)<<p.montoTotal<<setw(3)<<' '<<"Productos entregados: ";
    for (int i = 0; i < p.cantidadProductosEntrgados; i++) {
        out<<setw(10)<<left<<p.productosEntregados[i].codigo;
        flag=1;
    }
           
    if (!flag) out<<setw((40+29)/2)<<"NO SE LE ENTREGARON PRODUCTOS"<<endl;
    else out<<endl;
}

void operator <<(ofstream &out, struct Producto &p)
{
    int flag=0;
    out<<setprecision(2)<<fixed;
    out<<setw(12)<<right<<p.codigo<<setw(3)<<' '<<left<<setw(50)
            <<p.descripcion<<right<<p.precio<<setw(10)<<p.stock<<endl;
    out<<setw(5)<<' '<<setw(25)<<left<<"Clientes atendidos: ";
    for (int i = 0; i < p.cantidadClientesServidos; i++) {
         out<<setw(15)<<right<<p.clientesServidos[i];
         flag=1;
    }
     if (!flag) out<<setw((40+24)/2)<<"NO SE ENTREGARON PEDIDOS"<<endl;
     else  out<<endl;
    flag=0;
    out<<setw(5)<<' '<<setw(25)<<left<<"Clientes no atendidos: ";
    for (int h = 0; h < p.cantidadClientesNoServidos; h++) {
         out<<setw(15)<<right<<p.clientesNoServidos[h];
         flag=1;
    }
     if (!flag) out<<setw((40+27)/2)<<"NO HAY CLIENTES SIN ATENDER"<<endl;
    else  out<<endl;
}