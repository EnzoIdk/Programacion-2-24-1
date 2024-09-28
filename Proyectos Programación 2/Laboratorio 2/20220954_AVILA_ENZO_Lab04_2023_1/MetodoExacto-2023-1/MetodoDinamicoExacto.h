/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoDinamicoExacto.h
 * Author: Enzo
 *
 * Created on 11 de abril de 2024, 11:08 AM
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H

void lecturaAlumnos(const char *nombArch,int *&alumno_Codigo,char **&alumno_Nombre,
        char *&alumno_Modalidad,int *&alumno_Porcentaje,int *&alumno_Escala);
void leerOtrosDatos(ifstream &arch,char &aluMod,int &aluPorc,int &aluEsc);
char *leerCadena(ifstream &arch);
void pruebaLecturaAlumnos(const char *nombArch,int *alumno_Codigo,char **alumno_Nombre,
        char *alumno_Modalidad,int *alumno_Porcentaje,int *alumno_Escala);
void lecturaCursos(const char *nombArch,int *alumno_Codigo,int *alumno_Escala,
        char **&curso_Nombre,double *&curso_Credito,int **&curso_Alumnos);
void llenarPunteros(char **&curso_Nombre,double *&curso_Creditos,int **&curso_Alumnos,
        char **bufferCurNomb,double *bufferCurCred,int **bufferCurAlu,int numCursos,int *nd);
void espaciosExactos(int *&curso_Alumno,int *&bufferCurAlu,int nd);
void agregarDatosAlu(int *&bufferCurAlu,int &numAlumnos,int cod,int escala);
int buscarAlumno(int *alumnos,int cod);
int buscarCurso(char **cursos,char *nombre);
void pruebaDeLecturaCursos(const char *nombArch,char **curso_Nombre,
        double *curso_Credito,int **curso_Alumnos);
void imprimirAlumnos(ofstream &archReporte,int *cursosAlumnos);

void reporteDeRecaudacionPorModalidad(const char *nombArch,int *alumno_Codigo,
        char *alumno_Modalidad,int *alumno_Porcentaje,char **alumno_Nombre,char **curso_Nombre,
        double *curso_Credito,int **curso_Alumnos);
void imprimirReporteAlumnos(ofstream &archReporte,int *aluCod,char *aluMod,int *,
        char **,int *curso_Alumnos,double *arrCostoCred,double creditos,
        double &totalP,double &totalS,double &totalV);
void llenarArreglo(const char *nombArch,double *arrCostoCred);
void imprimirEncabezado(ofstream &arch);
void imprimirLinea(ofstream &arch,int longitud,char simbolo);
#endif /* METODODINAMICOEXACTO_H */

