/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Admin
 *
 * Created on 10 de abril de 2024, 06:35 PM
 */

#include <cstdlib>

using namespace std;
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char **alumno_Nombre,**curso_Nombre,*alumno_Modalidad;
    int *alumno_Codigo,*alumno_Porcentaje,*alumno_Escala;
    int **cursos_Alumnos;
    double *curso_Credito;
    lecturaAlumnos("alumnos.csv",alumno_Codigo,alumno_Nombre,alumno_Modalidad,
            alumno_Porcentaje,alumno_Escala);
    pruebaLecturaAlumnos("ResporteAlumnos.txt",alumno_Codigo,alumno_Nombre,
            alumno_Modalidad,alumno_Porcentaje,alumno_Escala);
    lecturaCursos("alumnos_cursos.csv",alumno_Codigo,alumno_Escala,curso_Nombre
            ,curso_Credito,cursos_Alumnos);
    ProbarCursos("ReporteCursos.txt",curso_Credito,curso_Nombre,cursos_Alumnos);
    return 0;
}

