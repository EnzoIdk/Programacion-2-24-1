/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: Enzo
 *
 * Created on 27 de marzo de 2024, 08:59 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargarAlumnos(int *&codigo,char **&nombre,char ***&cursos,const char *nombArch);
char *leerCadenaNombre(ifstream &arch);
char **leerCursos(ifstream &arch);
char *leerCadena(ifstream &arch);
void reporteAlumnos(int *codigo,char **nombre,char ***cursos,const char *nombArch);
void reporteCursos(ofstream &archReporte,char **cursos);

#endif /* FUNCIONES_H */

