/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAux.h
 * Author: Admin
 *
 * Created on 10 de abril de 2024, 07:14 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include <fstream>
using namespace std;
void lecturaAlumnos(const char*nomb,int *&alumno_Codigo,char **&alumno_Nombre,
        char *&alumno_Modalidad,int *&alumno_Porcentaje,int *&alumno_Escala);
char * leerCadena(ifstream &Arch);
void EvalModalidad(char &modalidad,int &escala,int &porcent,ifstream &Arch);
void LlenarExacto(int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
        int *&alumno_Porcentaje,int *&alumno_Escala,int *bufferCodigo,int *bufferEscala
        ,char *bufferModalidad,char **bufferNombre,int *bufferPorcent,int numdat);
void pruebaLecturaAlumnos(const char*nomb,int *alumno_Codigo,char **alumno_Nombre,
            char *alumno_Modalidad,int *alumno_Porcentaje,int *alumno_Escala);
void lecturaCursos(const char*,int *alumno_Codigo,int *alumno_Escala,char **&curso_Nombre
            ,double *&curso_Credito,int **&cursos_Alumnos);
int buscarCurso(char *NombreCurso,char **bufferNombreCurso);
bool comparar(char *bufferNombreCurso,char *NombreCurso);
void agregarAlumnos(int *&bufferCursos_Alumnos,int codAlumno,int *alumno_Escala,
            int *alumno_Codigo);
int buscarAlumnos(int codAlumno,int *alumno_Codigo);
void recortarBufferAlum(int **bufferCursos_Alumnos);
void recortarAlum(int *&bufferCursos_Alumnos);
void LlenarPunteros(double *&curso_Credito,char **&curso_Nombre,int **&cursos_Alumnos,
        int numdat,double *bufferCred,int **bufferCursos_Alumnos,char **bufferNombreCurso);
void ProbarCursos(const char*nomb,double *curso_Credito,char **curso_Nombre,int **cursos_Alumnos);
void ImprimeCursos(ofstream &Arch,int *cursos_Alumnos);
#endif /* FUNCIONESAUX_H */

