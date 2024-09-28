/* 
 * Archivo:   ListaPacientes.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de diciembre de 2020, 08:44 AM
 */

#ifndef LISTAPACIENTES_H
#define LISTAPACIENTES_H
#include <fstream>
#include "Ambulatorio.h"
#include "Emergencia.h"
#include "Urgencia.h"

#include "NodoPaciente.h"

using namespace std;

class ListaPacientes {
private:

    NodoPaciente *lista;

public:

    ListaPacientes();
    virtual ~ListaPacientes();
    void creaLista (const char *nombArch);
    void insertar (Paciente *& dato);
    void imprimeLista (const char *nombArch);

};
#endif /* LISTAPACIENTES_H */
