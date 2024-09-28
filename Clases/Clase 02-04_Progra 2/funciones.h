/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: aml
 *
 * Created on 2 de abril de 2024, 08:28 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargarAlumnos(int *&codigo,char **&nombre,const char *nombArch);
char *leeCadena(ifstream &arch);
void cargarCursos(int *codigo,char ***&cursos,const char *nombArch);
int buscarAlumno(int cod,int *codigo);
void colocarCurso(ifstream &arch,char **cursos,int &nd);
void espaciosExactos(char **&cursos,int nd);
void reporte(int *codigo,char **nombre,char ***cursos);
void reporteCursos(char **cursos);

#endif /* FUNCIONES_H */

