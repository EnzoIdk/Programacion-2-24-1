/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunteroVoid.h
 * Author: alulab14
 *
 * Created on 14 de mayo de 2024, 09:05 AM
 */

#ifndef PUNTEROVOID_H
#define PUNTEROVOID_H

void cargaventas(char ***libro,void *&ven);
void *leerReg(char **libro);
void actualizaventas(int **ventasDniFechaPuntaje,char **ventasLibroCodigo,void *ven);
int buscarLibro(char *codigo,void *ven);
void modificarventas(void *ven,int puntaje);

#endif /* PUNTEROVOID_H */

