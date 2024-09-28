/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesSobrecarga.h
 * Author: margo
 *
 * Created on 4 de abril de 2024, 7:29
 */

#ifndef FUNCIONESSOBRECARGA_H
#define FUNCIONESSOBRECARGA_H
#include "Estructuras.h"
#include <fstream>
using namespace std;
bool operator >>(ifstream &arch, struct StMedico &medico );
bool operator >>(ifstream &arch, struct StPaciente &p );
int  operator >>(ifstream &arch, struct StCita &c );
int obtenerFecha(int dd, int mm , int aa);
void obtenerNOmbreEsp(char cadena[], char nombre[], char especialidad[]);
bool operator <=(struct StCita &cita, struct StMedico medico[]);
int buscarCodMedico(int cod,  struct StMedico medico[]);
void operator+=(struct StPaciente &pac,struct StCita &cita);
void operator ++ (struct StPaciente &pac);
void operator <<(ofstream &impre, struct  StPaciente &pac);
void impresFecha(int fecha, ofstream &impre);

#endif /* FUNCIONESSOBRECARGA_H */

