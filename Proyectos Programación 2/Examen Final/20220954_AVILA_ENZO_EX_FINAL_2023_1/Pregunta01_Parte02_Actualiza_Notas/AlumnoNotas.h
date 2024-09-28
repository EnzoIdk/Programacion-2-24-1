/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   AlumnoNotas.h
 * Author: Enzo
 *
 * Created on 25 de junio de 2024, 01:04 AM
 */

#ifndef ALUMNONOTAS_H
#define ALUMNONOTAS_H
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;
#include "Alumno.h"
#include "Nota.h"
class AlumnoNotas {
private:
    class Alumno alumno;
    vector <class Nota> notas;
public:
    AlumnoNotas();
    AlumnoNotas(const AlumnoNotas& orig);
    virtual ~AlumnoNotas();
    void leerAluNotas(ifstream &arch);
    void imprimeAluNotas(ofstream &arch);
    void operator =(const class AlumnoNotas &orig);
    void insertarNota(class Nota &nota);
    int obtenerCodigo() const;
    void actualizar();
    void totalizar();
};

#endif /* ALUMNONOTAS_H */

