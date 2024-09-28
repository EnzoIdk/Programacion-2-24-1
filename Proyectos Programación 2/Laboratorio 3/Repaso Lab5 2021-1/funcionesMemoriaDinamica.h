/* 
 * File:   funcionesMemoriaDinamica.h
 * Author: Lucas
 *
 * Created on 18 de abril de 2024, 17:30
 */

#ifndef FUNCIONESMEMORIADINAMICA_H
#define FUNCIONESMEMORIADINAMICA_H

#include <fstream>
using namespace std;

void cargarConductores(const char* nombArch, int * &licencia, 
        char ** &conductor);

void leerConductor(ifstream &arch, int &dni, char * &nombre);

char * leerCadena(ifstream &arch, char delim);

void incrementarEspacios(int * &licencia, char ** &conductor, int &nd, 
        int &cap);

void reporteConductores(const char* nombArch, int * licencia, 
        char ** conductor);

void cargarFaltas(const char* nombArch, int * licencia, char *** &placa, 
        int ** &falta);

void leerFalta(ifstream &arch, int &dni, char * &cod, int &infraccion);

int buscarConductor(int dni, int * licencia);

void incrementarEspacios(char ** &placa, int * &falta, int &capFaltasPorCond, 
        int &numFaltasPorCond);

void agregarFalta(char * cod, int infraccion, char ** placa, int * falta, 
        int &numFaltasPorCond);

void reporteFaltas(const char* nombArch, int * licencia, char ** conductor, 
        char *** placa, int ** falta);

void imprimirFaltas(ofstream &arch, char ** placa, int * falta);

void imprimirLinea(ofstream &arch, int largo, char car);

void resumenMultas(const char* nombArch, int * licencia, int ** falta, 
        double ** &multa);

void leerMulta(ifstream &arch, int &infraccion, int &categoria, double &costo);

void incrementarEspacios(int * &regInf, int * &regCat, double * &regCosto, 
        int &nd, int &cap);

void agregarMultas(int * regCat, double * regCosto, int * regInf, 
        int * licencia, int ** falta, double ** multa);

void actualizarMultas(int * regCat, double * regCosto, int * regInf, 
        int * falta, double * multa);

int buscarFalta(int falta, int * regInf);

void reporteMultas(const char* nombArch, int * licencia, char ** conductor, 
        double ** multa);

#endif /* FUNCIONESMEMORIADINAMICA_H */

