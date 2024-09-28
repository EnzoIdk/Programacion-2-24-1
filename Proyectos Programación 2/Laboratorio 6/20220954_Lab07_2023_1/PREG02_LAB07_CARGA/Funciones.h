/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Funciones.h
 * Author: Enzo
 *
 * Created on 23 de mayo de 2024, 05:42 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

using namespace std;

void cargaralumnos(class Alumno *arrAlumnos);
void carganotas(class AlumnoNota *arrAluNotas);
void actualizanotas(class Alumno *arrAlumnos,class AlumnoNota *arrAluNotas);
int buscarAlu(int cod,class Alumno *arr);
void imprimealumnos(class Alumno *arrAlumnos);

#endif /* FUNCIONES_H */

