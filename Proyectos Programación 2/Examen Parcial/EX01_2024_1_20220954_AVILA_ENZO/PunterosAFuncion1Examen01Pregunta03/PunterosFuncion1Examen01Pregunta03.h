/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosFuncion1Examen01Pregunta03.h
 * Author: alulab14
 *
 * Created on 14 de mayo de 2024, 10:13 AM
 */

#ifndef PUNTEROSFUNCION1EXAMEN01PREGUNTA03_H
#define PUNTEROSFUNCION1EXAMEN01PREGUNTA03_H

void cargarranking(void *&rank,void *(*crea)(void*),void *ven);
void muestraranking(void *rank,void (*imprime)(ofstream &,void*),const char *nombArch,void *ven);

#endif /* PUNTEROSFUNCION1EXAMEN01PREGUNTA03_H */

