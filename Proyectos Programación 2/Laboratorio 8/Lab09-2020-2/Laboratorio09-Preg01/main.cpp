/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de diciembre de 2020, 08:01 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Paciente.h"
#include "Ambulatorio.h"
#include "Urgencia.h"
#include "Emergencia.h"
using namespace std;

int main(int argc, char** argv) {
    class Paciente *dato;
    char tipo;
    int cont = 0;
    ifstream archIn("prueba.txt",ios::in); 
    ofstream archOut("reporte.txt",ios::out); 
   // while (1) {
        archIn >> tipo;
        //if (archIn.eof()) break;
        archIn.get();
        if (tipo == 'E') {
            dato = new Emergencia;         
            dato->lee(archIn);
        } else if (tipo == 'A') {
            dato = new Ambulatorio;
            dato->lee(archIn);
        } else {
            dato = new Urgencia;
            dato->lee(archIn);
        }
        cont++;
        cout << dato->GetDni() << " " << dato->getPrioridad() << endl;
    //}
   //while (cont > 0) {
        dato->imprime(archOut);
        //cont--;
    //}
    return (EXIT_SUCCESS);
}
