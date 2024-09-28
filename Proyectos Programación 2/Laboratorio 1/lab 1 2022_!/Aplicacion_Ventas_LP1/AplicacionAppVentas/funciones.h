/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: margo
 *
 * Created on 4 de abril de 2024, 17:47
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void  lecturaClientes(ifstream &arch, struct Estructura_ClienteRegistrado p[], ofstream &archImp);
void  lecturaPedidos(ifstream &arch, struct Estructura_ClienteRegistrado p[], struct Estructura_ProductosEnAlmacen prod[]);
int buscarCli(int dni, struct Estructura_ClienteRegistrado p[]);
void agregarCliente(int dni,struct Estructura_ClienteRegistrado p[],
        struct Estructura_PedidoRealizado  &pedido, double cant, double precio, int fecha, char codigo[],  
        struct Estructura_ClienteRegistrado  &cliente, double desc);
void rellenarProducto(struct Estructura_ProductosEnAlmacen &prod, char codigo[], char descripcion [], double desc, double precio );
void rellenarPedido(struct Estructura_PedidoRealizado &pedido, double cant, int aa, int mm, int dd, char codigo[]);
#endif /* FUNCIONES_H */

