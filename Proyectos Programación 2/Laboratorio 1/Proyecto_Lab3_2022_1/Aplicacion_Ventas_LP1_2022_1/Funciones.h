
/* 
 * File:   Funciones.h
 * Autor: Sebastian Grajeda
 * Codigo: 20210800
 * Created on 4 de enero de 2024, 12:59 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void LeerClientes(struct Estructura_ClienteRegistrado *clientes,int &numCli,
        ifstream &arch);

void ProcesarProductos(struct Estructura_ClienteRegistrado *clientes,int numCli,
        struct Estructura_ProductosEnAlmacen *productos,int &numPro,
        ifstream &arch);
void AsignacionesDelProducto(int dni,struct Estructura_ClienteRegistrado *clientes,
        int numCli,struct Estructura_ProductosEnAlmacen *productos,int &numPro,
        const struct Estructura_PedidoRealizado &pedido,
        const struct Estructura_ProductosEnAlmacen &pro);
int BuscarCliente(int dni,struct Estructura_ClienteRegistrado *clientes,int numCli);
void NumerosToFecha(int dd,int mm,int aaaa,int &fecha);
void ImprimirReporte(struct Estructura_ClienteRegistrado *clientes,int numCli,
        struct Estructura_ProductosEnAlmacen *productos,int numPro,
        ofstream &arch);

#endif /* FUNCIONES_H */

