/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: margo
 *
 * Created on 3 de abril de 2024, 21:18
 */

#include <cstdlib>
#include <fstream>

using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesSobrecarga.h"


/*
 * 
 */
int main(int argc, char** argv) {

    ifstream archMed;
    struct StMedico medico[100]{};
    AperturaDeUnArchivoDeTextosParaLeer(archMed, "MedicosLab3.txt");
    bool continuar=true;
    int i;
    for ( i = 0;i<40; i++) {
        continuar=archMed>>medico[i];
//        cout<<medico[i].codigo<<endl;
//        cout<<medico[i].especialidad<<endl;
//        cout<<medico[i].nombre<<endl;
//        cout<<medico[i].tarifaPoxConsulta<<endl;
    }
    medico[i].codigo=0;

    ifstream archPac;
     struct StPaciente paciente[200];
    AperturaDeUnArchivoDeTextosParaLeer(archPac, "PacientesLab3.txt");
    bool continuar1=true;
    for (int j = 0;j<67; j++) {
        continuar1=archPac>>paciente[j];
//          cout<<paciente[j].dni<<endl;
//        cout<<paciente[j].nombre<<endl;
//        cout<<paciente[j].telefono<<endl;
    }
//    
////    //43704548   Vizcardo/Maribel   960851431

    ifstream archCit;
    struct StCita cita[300]{};
    AperturaDeUnArchivoDeTextosParaLeer(archCit, "ConsultasLab3.txt");
    int codPaciente;
//    
    for (int k = 0;codPaciente!=-1; k++) {
       codPaciente=archCit>>cita[k];

    }
        cita[5]<=medico;
        paciente[5]+=cita[5];
        
        ++paciente[5];
        ofstream archImpre;
        AperturaDeUnArchivoDeTextosParaEscribir(archImpre, "prueba1.txt");
        archImpre<<paciente[5];
    return 0;
    
}

