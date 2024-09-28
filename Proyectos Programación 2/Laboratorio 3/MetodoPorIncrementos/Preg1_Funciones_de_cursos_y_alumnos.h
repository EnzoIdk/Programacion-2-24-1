/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.h
 * Author: Enzo
 *
 * Created on 15 de abril de 2024, 04:37 PM
 */

#ifndef PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
#define PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H

void cargarCursosYEscalas(char ***&cursos,double *&cursos_cred,double *escalas,
        const char *nombArchCursos,const char *nombArchEsc);
void leerEscalas(ifstream &arch,double *escalas);
void leerCursos(ifstream &arch,char ***&cursos,double *&cursos_cred);
void aumentarCap(char ***&cursos,double *&cursos_cred,int &numDat,int &cap);
void aumentarEspaciosSND(char ***&cursos,double *&cursos_cred,int &numDat,int &cap);
char **leerRegistro(ifstream &arch,double &cred);
char *leerCadena(ifstream &arch,char delim);
void pruebaDeCargaDeCursos(char ***cursos,double *cursos_cred,const char *nombArch);
void cargarAlumnos(int *&alumnos_cod,int **&alumnos,char ***&alumnos_nom_mod,const char *nombArch);
void pruebaDeCargaDeAlumnos(int *alumnos_cod,int **alumnos,char ***alumnos_nom_mod,const char *nombArch);


#endif /* PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H */

