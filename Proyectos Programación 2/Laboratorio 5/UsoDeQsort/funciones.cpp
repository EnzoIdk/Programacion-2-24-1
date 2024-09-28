/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#include "funciones.h"

/*si devuelve >0, el ai va después del bi, si no se queda atrás*/
int intcmp(const void *a,const void *b){
    int *ai=(int *)a,*bi=(int *)b;
    return *ai-*bi;
}

int cadcmp(const void*cad1,const void*cad2){
    char **cad1i=(char **)cad1,**cad2i=(char **)cad2;
    return strcmp(*cad1i,*cad2i);
}

