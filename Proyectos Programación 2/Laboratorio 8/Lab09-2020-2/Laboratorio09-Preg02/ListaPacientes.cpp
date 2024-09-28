/* 
 * Archivo:   ListaPacientes.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de diciembre de 2020, 08:44 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaPacientes.h"

ListaPacientes::ListaPacientes() {
    lista = nullptr;
}

ListaPacientes::~ListaPacientes() {
    NodoPaciente *sale;
    while (lista) {
        sale = lista;
        lista = lista->next;
        delete sale;
    }
}

void ListaPacientes::creaLista(const char* nombArch) {
    ifstream arch(nombArch,ios::in); 
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    char tipo;
    Paciente *dato;
    while (1) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        if (tipo == 'E') {
            dato = new Emergencia;         
            dato->lee(arch);
        } else if (tipo == 'A') {
            dato = new Ambulatorio;
            dato->lee(arch);
        } else {
            dato = new Urgencia;
            dato->lee(arch);
        }
        this->insertar(dato);
    }
}

void ListaPacientes::insertar(Paciente*& dato) {
    NodoPaciente *p = lista, *ant = nullptr, *nuevo;
    nuevo = new NodoPaciente;
    nuevo->paciente = dato;
    while (p) {
        if ((p->paciente)->getPrioridad() > dato->getPrioridad()) break;
        ant = p;
        p = p->next;
    }
    nuevo->next = p;
    if (ant != nullptr) ant->next = nuevo;
    else lista = nuevo;
}

void ListaPacientes::imprimeLista(const char* nombArch) {
    ofstream arch(nombArch,ios::out); 
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    arch.precision(2); arch << fixed;
    int prio, prioPrev, i, cont = 0, seg;
    NodoPaciente *p = lista;
    while (p) {
        prio = (p->paciente)->getPrioridad();
        seg = (p->paciente)->seguro();
        if (seg) cont++;
        if (prio != prioPrev) {
            i = 1;
            if (prio == 3) {
                arch << setfill('=') << setw(130) << " " << setfill(' ') << endl;
                arch << setw(70) << "PACIENTES ATENDIDOS POR EMERGENCIA" << endl;
                arch << setfill('-') << setw(130) << " " << setfill(' ') << endl;
                arch << "No. " << setw(10) << "DNI" << setw(20) << "Paciente"
                    << setw(40) << "Medico" << setw(25) << "Referencia" << endl;
            } else if (prio == 2) {
                arch << setfill('=') << setw(130) << " " << setfill(' ') << endl;
                arch << setw(70) << "PACIENTES ATENDIDOS POR URGENCIA" << endl;
                arch << setfill('-') << setw(130) << " " << setfill(' ') << endl;
                arch << "No. " << setw(10) << "DNI" << setw(20) << "Paciente"
                    << setw(40) << "Medico" << setw(15) << "% por Seg" << setw(20) << "% por Urgencia" << endl;
            } else {
                arch << setfill('=') << setw(130) << " " << setfill(' ') << endl;
                arch << setw(70) << "PACIENTES ATENDIDOS DE MANERA AMBULATORIA" << endl;
                arch << setfill('-') << setw(130) << " " << setfill(' ') << endl;
                arch << "No. " << setw(10) << "DNI" << setw(20) << "Paciente"
                    << setw(40) << "Medico" << setw(15) << "% por Seg" << endl;
            }
        }
        arch << setw(3) << i << ')'; i++;
        (p->paciente)->imprime(arch);
        p = p->next;
        prioPrev = prio;
    }
    arch << endl << "Atendidos por seguro: " << cont << " pacientes" << endl;
}