/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ptrLibro.h
 * Author: margo
 *
 * Created on 20 de junio de 2024, 8:18
 */

#ifndef PTRLIBRO_H
#define PTRLIBRO_H
#include "Libro.h"
#include <fstream>
using namespace std;
class ptrLibro {
private:
    class Libro *ptr;

public:
    ptrLibro();
    ptrLibro(const class ptrLibro& orig);
    virtual ~ptrLibro();
    double pesoLibro();
};
#endif /* PTRLIBRO_H */

