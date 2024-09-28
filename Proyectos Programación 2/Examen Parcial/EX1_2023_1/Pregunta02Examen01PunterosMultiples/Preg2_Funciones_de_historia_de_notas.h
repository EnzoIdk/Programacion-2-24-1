/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Preg2_Funciones_de_historia_de_notas.h
 * Author: Enzo
 *
 * Created on 11 de mayo de 2024, 10:00 PM
 */

#ifndef PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H
#define PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H

void cargarNotas(char ***&cursos_cod,int ***&cursos_nota_sem_veces,double **&costos,
        int **alumnos,char ***alumnos_nom_mod,double *escalas,char ***cursos,
        double *cursos_cred,const char *nombArch);
void asignarArreglos(char ***&arr1,int ***&arr2,double **&arr3,char ***arrAux1,
        int ***arrAux2,double **arrAux3,int *nd,int numAlu);
void memoriaExacta(char **&arr1,int **&arr2,double *&arr3,char **arrAux1,int **arrAux2,
        double *arrAux3,int nd);
void agregarCurso(int &nd,char **cursosCod,char *cod,int **cursosNotSemVec,
        int nota,int ciclo,double *costos,int *datosAlumno,char **aluNomMod,
        double *escalas,double cred);
int buscarCursoCod(char **cursosCod,char *cod,int nd);
double calcularCosto(int *datosAlu,char **aluNomMod,double *escalas,double cred);
void inicializarSubBuffers(int ***buffer1,char ***buffer2,double **buffer3,int num);
void leerDatosNotas(ifstream &arch,int &codAlu,int &ciclo,int &nota,char *&codCurso);
int buscarAlu(int **alumnos,int cod);
int buscarCur(char ***cursos,char *cod);
void pruebaDeCargaDeNotas(char ***cursos_cod,int ***cursos_nota_sem_veces,
        double **costos,int **alumnos,char ***alumnos_nom_mod,const char *nombArch);
void imprimirAlumnos(ofstream &arch,int *datosAlu,char **aluNomMod,char **codCurAlu,
        int **datosCurAlu,double *costos);
void imprimirLinea(ofstream &,int,char);

#endif /* PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H */

