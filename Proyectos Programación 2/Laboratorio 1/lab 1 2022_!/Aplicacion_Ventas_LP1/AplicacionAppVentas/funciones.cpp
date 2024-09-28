/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

#include "Estructuras.h"
#include "funciones.h"
#include "sobrecargas.h" //no olvid
using namespace std;

void  lecturaClientes(ifstream &arch,     struct Estructura_ClienteRegistrado p[], ofstream &archImp){
    int i;
    for ( i = 0;i<20; i++) {
        arch>>p[i];
    }
    p[i].dni=0;
}
void  lecturaPedidos(ifstream &arch, struct Estructura_ClienteRegistrado p[], struct Estructura_ProductosEnAlmacen productos[]){
     struct Estructura_PedidoRealizado pedido;
     struct Estructura_ClienteRegistrado cliente;
     struct Estructura_ProductosEnAlmacen prod;
     char codigo[7] ,descripcion[80], c;
     int dni, aa,mm,dd,idProd;
     double cant, desc=0.0, precio ;
    while(true){
        desc=0.0;
        arch>>codigo;
        if (arch.eof()) break;
        arch>>descripcion;
        arch>>ws;
        if (arch.get()=='%') arch>>desc>>cant>>precio>>dni>>dd>>c>>mm>>c>>aa;
        else {
            arch.unget();
            arch>>cant>>precio>>dni>>dd>>c>>mm>>c>>aa;
        }
        rellenarProducto(prod, codigo, descripcion, desc, precio);
        rellenarPedido(pedido, cant,aa,mm,dd,codigo);
        idProd=buscar(codigo, productos);
        if (idProd==-1) {
            productos+=prod;
        }
        agregarCliente(dni, p,  pedido, cant,  precio,pedido.fecha, codigo,cliente,desc);
    }

}
void agregarCliente(int dni,struct Estructura_ClienteRegistrado p[], 
        struct Estructura_PedidoRealizado &pedido, double cant, double precio, int fecha, char codigo[],  
        struct Estructura_ClienteRegistrado  &cliente, double desc){
    int ind ;
     ind=buscarCli(dni, p );
        if (ind!=-1){
            p[ind]+= pedido;
            p[ind].montoTotalGastado+=((precio*cant)-(desc*(precio*cant)/100));
        }else{
            cliente.dni= dni;
            strcpy(cliente.categoria, "Cliente nuevo");
            cliente.pedidosRealizados[cliente.numeroDePedidos].cantidad=cant;
            cliente.montoTotalGastado+=((precio*cant)-(desc*(precio*cant)/100));
            cliente.pedidosRealizados[cliente.numeroDePedidos].fecha=pedido.fecha;
            strcpy(cliente.pedidosRealizados[cliente.numeroDePedidos].codigo,codigo);
             cliente.numeroDePedidos++;
            p+=cliente;
        }
}

void rellenarProducto(struct Estructura_ProductosEnAlmacen &prod, char codigo[], char descripcion [], double desc, double precio ){
        strcpy(prod.codigo,codigo);
        strcpy(prod.descripcion, descripcion);
        prod.descuento=desc;
        prod.precioUnitario=precio;
}
void rellenarPedido(struct Estructura_PedidoRealizado &pedido, double cant, int aa, int mm, int dd, char codigo[]){
        pedido.cantidad=cant;
        pedido.fecha=aa*10000+mm*100+dd;
        strcpy(pedido.codigo,codigo);
}
int buscarCli(int dni, struct Estructura_ClienteRegistrado p[]){
    for (int i = 0; i<20; i++) {
        if (dni==p[i].dni) return i;
    }
    return -1;
}