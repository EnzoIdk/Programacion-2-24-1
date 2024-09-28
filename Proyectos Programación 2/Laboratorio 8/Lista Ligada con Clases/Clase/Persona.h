/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: Enzo
 *
 * Created on 9 de junio de 2024, 09:33 AM
 */

#ifndef PERSONA_H
#define PERSONA_H
#include <fstream>
using namespace std;
class Persona {
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(const char*);
    void GetNombre(char *) const;
    void SetDni(int dni);
    int GetDni() const;
    bool operator >(const class Persona &);
    void operator =(const class Persona &);
private:
    int dni;
    char *nombre;
    double sueldo;
};

ifstream & operator >>(ifstream &arch,class Persona &persona);
ofstream & operator <<(ofstream &arch,const class Persona &persona);

#endif /* PERSONA_H */

