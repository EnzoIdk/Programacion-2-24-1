/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: alulab14
 *
 * Created on 26 de abril de 2024, 08:06 AM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

using namespace std;

void cargaclientes(void *&cli);
void *leerRegCli(ifstream &arch);
char *leerCadena(ifstream &arch,char delim);
void creareserva(void *&res);
void *leerRegRes(ifstream &arch);
void cargareservar(void *cli,void *res);
void memoriaExacta(void *res);
int buscarCli(int dni,void **clientes);
bool esCliente(int dni,void *cli);
int buscarRes(char *codigo,void **reservas);
bool esReserva(char *codigo,void *res);
void agregarReserva(void *cli,void *res);
void agregarALista(void *lis,int dni,char *nombre,int);
void colocarDatos(void *&lis,int dni,char *nombre);

#endif /* PUNTEROSGENERICOS_H */

