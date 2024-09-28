/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.h
 * Author: Enzo
 *
 * Created on 11 de mayo de 2024, 04:38 PM
 */

#ifndef PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
#define PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H

void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,double *escalas,
        const char *nombCur,const char *nombEsc);
void cargarEscalas(ifstream &arch,double *escalas);
void leerDatos(ifstream &arch,char **&datosCur,double &cred);
char *leerCadena(ifstream &arch,char delim);
void aumentarCap(char ***&cursos,double *&cursos_cred,int &num,int &cap);
void pruebaDeCargaDeCursos(char ***cursos,double *cursos_cred,const char *nombArch);
void cargarAlumnos(int *&alumnos_cod,int **&alumnos,char ***&alumnos_nom_mod,const char *nombArch);
void leerDatosAlu(ifstream &arch,int &cod,int &escala,int &porc,char *&nombre,char &mod);
void aumentarCapAlu(int *&arr1,int **&arr2,char ***&arr3,int &num,int &cap);
int *insertarDatAlu(int cod,int esc,int porc);
char **insertarNomMod(char *nombre,char mod);
void pruebaDeCargaDeAlumnos(int *alumnos_cod,int **alumnos,char ***alumnos_nom_mod,const char *nombArch);

#endif /* PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H */

