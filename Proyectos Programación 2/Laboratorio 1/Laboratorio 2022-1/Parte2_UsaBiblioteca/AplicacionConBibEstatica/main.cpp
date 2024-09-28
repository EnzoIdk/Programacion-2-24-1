/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: margo
 *
 * Created on 4 de abril de 2024, 7:38
 */

#include <cstdlib>
#include <fstream>

using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesSobrecarga.h"
#include "funciones.h"


/*
 * 
 */
int main(int argc, char** argv) {

    ifstream archMed;
    struct StMedico medicos[100]{};
    AperturaDeUnArchivoDeTextosParaLeer(archMed, "MedicosLab3.txt");
    lecturaMedicos(archMed, medicos);

    ifstream archPac;
     struct StPaciente pacientes[200]{};
    AperturaDeUnArchivoDeTextosParaLeer(archPac, "PacientesLab3.txt");
   lecturaPacientes(archPac, pacientes);

    ifstream archCit;
    struct StCita citas[300]{};
    AperturaDeUnArchivoDeTextosParaLeer(archCit, "ConsultasLab3.txt");
    lecturaCitas(archCit, citas, medicos, pacientes);
    
    
    
    ofstream archImp;
    AperturaDeUnArchivoDeTextosParaEscribir(archImp, "impresion.txt");
    impresion(archImp, pacientes);
    
  
    return 0;
}



