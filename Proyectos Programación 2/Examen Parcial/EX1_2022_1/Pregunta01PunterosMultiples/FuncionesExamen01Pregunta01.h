/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesExamen01Pregunta01.h
 * Author: Enzo
 *
 * Created on 7 de mayo de 2024, 10:25 AM
 */

#ifndef FUNCIONESEXAMEN01PREGUNTA01_H
#define FUNCIONESEXAMEN01PREGUNTA01_H

void CargarProductosPedidos(int **&proInfo,char **&proDesc,int **&pedTodo,
        const char *nombArch);
void leerDatos(ifstream &arch,int &codigo,char *&descripcion,int &descuento,
        int &,int &cantPed,int &stock,int &dni,int &fecha);
char *leerCadena(ifstream &arch);
int buscarProd(int **arreglo,int cod);
void agregarInfoProd(int *&infoProd,int codigo,int descuento,int precio,int stock);
void agregarPed(int *&pedido,int dni,int fecha,int cant,int cod);
void asignarBuffers(int **&proInfo,char **&proDesc,int **&pedTodo,int nd,
        int numPed,int **bufferInfo,char **bufferDesc,int **bufferPed);
void PruebaProductosPedidos(int **proInfo,char **proDesc,int **pedTodo,const char *nombArch);
void ordenarPedidos(int **pedTodo);
void qSort(int **pedTodo,int ini,int fin);
void cambiar(int *&dato1,int *&dato2);
bool compara(int *pedido1,int *pedido2);
void asignarPedidos(int ***cli_DniTelPed,int **prodInfo,int **pedTodo);
int buscarCli(int ***dniTelPed,int dni);
void agregarPedidosCli(int *&lista,int &stock,int,int,int,int &num,int &cap);
void aumentarCap(int *&lista,int &numPed,int &cap);

#endif /* FUNCIONESEXAMEN01PREGUNTA01_H */

