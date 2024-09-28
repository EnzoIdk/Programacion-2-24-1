/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConCadenas.h
 * Author: aml
 *
 * Created on 30 de abril de 2024, 08:32 AM
 */

#ifndef LISTACONCADENAS_H
#define LISTACONCADENAS_H

void *leeCad(ifstream &arch);
int cadcmp(const void *a,const void *b);
void imprimeCad(void *cad);
void eliminaCad(void *cad);

#endif /* LISTACONCADENAS_H */

