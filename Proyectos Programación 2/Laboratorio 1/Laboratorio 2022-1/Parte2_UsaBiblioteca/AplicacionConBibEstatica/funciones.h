/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: margo
 *
 * Created on 4 de abril de 2024, 8:04
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Estructuras.h"
#include <fstream>
void  lecturaMedicos(ifstream &arch, struct StMedico p[]);
void    lecturaPacientes(ifstream &arch, struct StPaciente p[]);
void lecturaCitas(ifstream &arch, struct StCita p[],  struct StMedico med[], struct StPaciente pac[]);
int buscarPac(int codPaciente,  struct StPaciente pac[]);
void   impresion(ofstream &archImp, struct StPaciente pac[]);
void linea(ofstream &imp, int cant, char sim);
#endif /* FUNCIONES_H */

