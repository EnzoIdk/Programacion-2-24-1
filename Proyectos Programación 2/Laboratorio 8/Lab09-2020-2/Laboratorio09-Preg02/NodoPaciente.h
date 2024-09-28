/* 
 * Archivo:   NodoPaciente.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de diciembre de 2020, 08:45 AM
 */

#ifndef NODOPACIENTE_H
#define NODOPACIENTE_H
#include <fstream>
#include "Paciente.h"
using namespace std;

class NodoPaciente {
private:

    Paciente *paciente;
    NodoPaciente *next;

public:

    NodoPaciente();
    virtual ~NodoPaciente();
    friend class ListaPacientes;

};
#endif /* NODOPACIENTE_H */
