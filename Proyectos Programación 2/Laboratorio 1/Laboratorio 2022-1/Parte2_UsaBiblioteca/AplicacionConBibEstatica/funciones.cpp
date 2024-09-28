/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Estructuras.h"
#include "funciones.h"
#include "funcionesSobrecarga.h"


void    lecturaMedicos(ifstream &arch, struct StMedico p[]){
    bool continuar=true;
    int i;
    for ( i = 0;i<41; i++) {
        continuar=arch>>p[i];
//        cout<<p[i].codigo<<endl;
//        cout<<p[i].especialidad<<endl;
//        cout<<p[i].nombre<<endl;
//        cout<<p[i].tarifaPoxConsulta<<endl;
    }
    p[i].codigo=0;
}
void    lecturaPacientes(ifstream &arch, struct StPaciente p[]){
   bool continuar1=true;
   int j;
    for ( j = 0;j<68; j++) {
        continuar1=arch>>p[j];
//          cout<<p[j].dni<<endl;
//        cout<<p[j].nombre<<endl;
//        cout<<p[j].telefono<<endl;
    }
   p[j].dni=0;
}
void lecturaCitas(ifstream &arch, struct StCita p[],  struct StMedico med[], struct StPaciente pac[]){
     int codPaciente;
//    
     int idenPaciente;
    for (int k = 0;codPaciente!=-1; k++) {
       codPaciente=arch>>p[k];
       if (p[k]<=med){
       }else{
           cout<<k<<endl;
           cout<<"No se encontró al medico"<<endl;
       }
       idenPaciente=buscarPac(codPaciente, pac);
       if (idenPaciente!=-1){
           pac[idenPaciente]+=p[k];
           ++pac[idenPaciente];
       }else{
           cout<<"paciente no encontrado"<<endl;
       }
    }
}
int buscarPac(int codPaciente,  struct StPaciente pac[]){
    for (int i = 0; pac[i].dni!=0; i++) {
        if (codPaciente==pac[i].dni) return i;
    }
    return -1;

}
void   impresion(ofstream &archImp, struct StPaciente pac[]){
    archImp<<setw((80+31)/2)<<"EMPRESA PRESTADORA DE SALUP LP1"<<endl;
      linea(archImp, 80, '=');
    for (int i = 0; pac[i].dni!=0; i++) {
        archImp<<pac[i];
        linea(archImp, 80, '=');
    }
}
void linea(ofstream &imp, int cant, char sim){
    for (int i = 0; i < cant; i++) {
        imp<<sim;
    }
    imp<<endl;

}
