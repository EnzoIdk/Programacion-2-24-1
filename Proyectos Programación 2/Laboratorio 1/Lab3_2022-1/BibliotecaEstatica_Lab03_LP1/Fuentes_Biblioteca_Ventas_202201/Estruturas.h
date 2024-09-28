
/* 
 * File:   Estruturas.h
 * Autor: Enzo
 * 
 * Created on 24 de marzo de 2024, 10:18 PM
 */

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

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

#endif /* ESTRUTURAS_H */

