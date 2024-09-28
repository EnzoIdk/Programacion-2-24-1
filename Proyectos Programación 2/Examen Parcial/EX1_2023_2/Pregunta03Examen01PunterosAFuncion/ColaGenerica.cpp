/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Pregunta01Examen01PunterosMultiples.h"
#include "Pregunta02Examen01PunterosGenericos.h"

#include "ColaGenerica.h"

using namespace std;

enum Cola{INI,FIN,CANT};
enum Nodo{DATO,SGTE};

void cargaEnteros(void *&cola,void*(*lee)(ifstream &),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    generacola(cola);
    void *dato;
    while(true){
        dato=lee(arch);
        if(arch.eof()) break;
        encola(cola,dato);
    }
//    void **regCola=(void**)cola;
//    int *a=(int*)regCola[LONG];
//    cout<<*a<<endl;
}

void generacola(void *&cola){
    void **reg=new void*[3]{};
    int *cant=new int{0};
    reg[CANT]=cant;
    cola=reg;
}

void encola(void *&cola,void *dato){
    void **nodo,**auxCola=(void**)cola,**fin;
    crearNodo(nodo,dato);
    if(colavacia(auxCola[INI])){
        auxCola[INI]=nodo;
        auxCola[FIN]=nodo;
    }
    else{
        fin=(void**)auxCola[FIN];
        fin[SGTE]=nodo;
        auxCola[FIN]=nodo;
    }
}

void *desencola(void *&cola){
    void **auxCola=(void**)cola;
    void **ini=(void**)auxCola[INI];
    if(colavacia(ini)) return nullptr;
    void *sale;
    /*que el inicio de la cola apunte al siguiente*/
    auxCola[INI]=(void**)ini[SGTE];
    /*asignamos el dato del inicio a lo que sale*/
    sale=ini[DATO];
    /*borramos la cabeza*/
    delete ini;
    return sale;
}

void crearNodo(void **&nuevoNodo,void *dato){
    nuevoNodo=new void*[2]{};
    nuevoNodo[DATO]=dato;
    nuevoNodo[SGTE]=nullptr;
}

bool colavacia(void *cola){
    return cola==nullptr;
}

void mostrarEnteros(void *cola,void (*imprime)(ofstream &,void*),const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **auxCola=(void**)cola;
    void **ini=(void**)auxCola[INI];
    while(!colavacia(ini)){
        imprime(arch,ini[DATO]);
        ini=(void**)ini[SGTE];
    }
}