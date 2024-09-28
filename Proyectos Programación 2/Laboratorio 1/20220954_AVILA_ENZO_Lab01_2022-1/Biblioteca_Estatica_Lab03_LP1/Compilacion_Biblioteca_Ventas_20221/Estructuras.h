/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Estructuras.h
 * Author: Enzo
 *
 * Created on 4 de abril de 2024, 08:11 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Estructura_PedidoRealizado{
    char codigo[7];
    double cantidad;
    double precioUnitario;
    double descuento;
    int fecha;
};

struct Estructura_ProductosEnAlmacen{
    char codigo[7];
    char descripcion[60];
    double descuento;
    double precioUnitario;
};

struct Estructura_ClienteRegistrado{
    int dni;
    char nombre[60];
    char categoria[20];
    int telefono;
    struct Estructura_PedidoRealizado pedidosRealizados[100];
    int numeroDePedidos;
    double montoTotalGastado;
};

#endif /* ESTRUCTURAS_H */

