/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medico.h
 * Author: aml
 *
 * Created on 29 de mayo de 2024, 08:43 AM
 */

#ifndef MEDICO_H
#define MEDICO_H

class medico {
public:
    medico();
    virtual ~medico();
    void SetEspecialidad(const char*);
    void GetEspecialidad(char *) const;
    void SetNombre(const char*);
    void GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    char *nombre;
    char *especialidad;
};

#endif /* MEDICO_H */

