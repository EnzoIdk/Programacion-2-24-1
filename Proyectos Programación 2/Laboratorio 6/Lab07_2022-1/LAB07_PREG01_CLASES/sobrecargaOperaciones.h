/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Proyecto: LAB07_PREG01_CLASES
 * File:   sobrecargaOperaciones.h
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 10 de junio de 2022, 8:13
 */

#ifndef SOBRECARGAOPERACIONES_H
#define SOBRECARGAOPERACIONES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Cliente.h"
#include "Pedido.h"

ifstream & operator >>(ifstream &arch, Cliente &f) ;
ifstream & operator >>(ifstream &arch, Pedido &f) ;

ofstream & operator <<(ofstream &arch, const Cliente &f) ;

#endif /* SOBRECARGAOPERACIONES_H */
