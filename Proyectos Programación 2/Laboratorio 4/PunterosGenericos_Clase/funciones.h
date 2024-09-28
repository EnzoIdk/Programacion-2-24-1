/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: Enzo
 *
 * Created on 20 de abril de 2024, 02:33 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargarAlumnos(void *&al,const char *nombArch);
void *leerRegistro(ifstream &arch);
char *leerCadena(ifstream &arch,char);
void aumentarCap(void **&alumnos,int &nd,int &cap);
void cargarNotas(void *al,const char *nombArch);
int buscarPos(int cod,void **alumnos);
bool sonIguales(int cod,void *al);
void colocarCurso(ifstream &arch,void *al,int &nd,int &cap);
void aumentarCap(void *&al,int &nd,int &cap);
void *leerCurso(ifstream &arch);
void agregarCurso(void *cur,void *alNota,int nd);
void calcularPromedios(void *al);
void promedioDelAlumno(void *al);
void *promedio(void *al);
int obtenerNota(void *cur);
void probarCarga(void *al);
void imprimirAlumno(void *al);
void imprimirCursos(void *cur);
void imprimirCurso(void *cur);
void imprimirPromedio(void *pro);
void ordenar(void *al);
void qsort(void **alumnos,int izq,int der);
void cambiar(void *&al1,void *&al2);
bool estanEnDesorden(void *alI,void *alIzq);
void ordenarCursos(void *alu);
void qsort2(void **notas,int izq,int der);
bool estanEnDesorden2(void *notI,void *notIzq);
void eliminarDatos(void *al);
void eliminarAlumno(void *al);
void eliminarCursos(void *cur);
void eliminarCodNota(void *cur);

#endif /* FUNCIONES_H */

