
/* 
 * File:   Funciones.cpp
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 4 de enero de 2024, 01:00 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include <valarray>
#include "Estruturas.h"
#include "BibliotecaEstatica.h"
#include "Funciones.h"
#define NO_ENCONTRADO -1

void LeerClientes(struct Estructura_ClienteRegistrado *clientes,int &numCli,
        ifstream &arch){
    struct Estructura_ClienteRegistrado aux;
    while(true){
        arch>>aux;
        if(arch.eof())break;
        clientes += aux;
        numCli++;
    }
}

void ProcesarProductos(struct Estructura_ClienteRegistrado *clientes,int numCli,
        struct Estructura_ProductosEnAlmacen *productos,int &numPro,
        ifstream &arch){
    struct Estructura_PedidoRealizado ped;
    struct Estructura_ProductosEnAlmacen pro;
    char c;
    int dni,dd,mm,aaaa;
    while(true){
        arch>>pro.codigo;
//        if(strcmp(pro.codigo,"VUT136")==0){
//            cout<<"Alerta"<<endl;
//            break;
//        }
        if(arch.eof())break;
        arch>>pro.descripcion>>ped.cantidad;
        if(arch.fail()){
            arch.clear();
            arch>>c>>pro.descuento>>ped.cantidad;
        }
        arch>>pro.precioUnitario>>dni>>dd>>c>>mm>>c>>aaaa;
        strcpy(ped.codigo,pro.codigo);
        NumerosToFecha(dd,mm,aaaa,ped.fecha);
        ped.descuento = pro.descuento;
        ped.precioUnitario = pro.precioUnitario;
        AsignacionesDelProducto(dni,clientes,numCli,productos,numPro,ped,pro);
    }
}

void AsignacionesDelProducto(int dni,struct Estructura_ClienteRegistrado *clientes,
        int numCli,struct Estructura_ProductosEnAlmacen *productos,int &numPro,
        const struct Estructura_PedidoRealizado &pedido,
        const struct Estructura_ProductosEnAlmacen &pro){
    int pos = BuscarCliente(dni,clientes,numCli);
    if(pos != NO_ENCONTRADO){
        clientes[pos]+=pedido;
    }else cout<<"Producto vendido a cliente no registrado del dni "<<dni<<endl;
    productos += pro;
    numPro++;
}
int BuscarCliente(int dni,struct Estructura_ClienteRegistrado *clientes,int numCli){
    for(int i=0;i<numCli;i++)
        if(dni == clientes[i].dni)return i;
    return NO_ENCONTRADO;
}

void NumerosToFecha(int dd,int mm,int aaaa,int &fecha){
    fecha = aaaa*10000 + mm*100 + dd;
}

void ImprimirReporte(struct Estructura_ClienteRegistrado *clientes,int numCli,
        struct Estructura_ProductosEnAlmacen *productos,int numPro,
        ofstream &arch){
    arch<<setw(50)<<"EMPRESA COMERCIALIZADORES ABC"<<endl;
    arch<<productos; //Corregir en la biblioteca la alineacion
    for(int i=0;i<numCli;i++)
        arch<<clientes[i];
}
