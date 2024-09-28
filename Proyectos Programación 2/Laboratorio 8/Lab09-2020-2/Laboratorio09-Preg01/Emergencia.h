/* 
 * Archivo:   Emergencia.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de diciembre de 2020, 08:17 AM
 */

#ifndef EMERGENCIA_H
#define EMERGENCIA_H
#include <fstream>
#include "Paciente.h"
using namespace std;

class Emergencia : public Paciente {
private:

    int telefonoRef;
    char *nombreRef;

public:

    Emergencia();
    Emergencia(const Emergencia& orig);
    virtual ~Emergencia();

    void SetNombreRef(const char* nombR);
    void GetNombreRef(char *nombR) const;
    void SetTelefonoRef(int telefonoRef);
    int GetTelefonoRef() const;
    
    void operator = (const Emergencia& emer);
    
    int getPrioridad ();
    void lee (ifstream &arch);
    void imprime (ofstream &arch);
    int seguro ();
    
};
#endif /* EMERGENCIA_H */
