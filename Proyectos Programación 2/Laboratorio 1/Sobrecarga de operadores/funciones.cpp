/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "Persona.h"
#include "funciones.h"

void operator *=(struct Persona &p,double porcentaje){
    p.sueldo*=(1+porcentaje);
}

//void operator <<(ostream &out,const struct Persona &p){
//    out<<setprecision(2)<<fixed;
//    out<<"DNI: "<<p.dni<<endl;
//    out<<"Nombre: "<<p.nombre<<endl;
//    out<<"Sueldo: "<<p.sueldo<<endl<<endl;
//}

/*ostream: para imprimir en la pantalla*/
/*con esto estamos sobrecargando el operador << para que muestre todo*/
ostream & operator <<(ostream &out,const struct Persona &p){
    out<<setprecision(2)<<fixed;
    out<<"DNI: "<<p.dni<<endl;
    out<<"Nombre: "<<p.nombre<<endl;
    out<<"Sueldo: "<<p.sueldo<<endl<<endl;
    return out;
}

void leerDatosExactos(int *&datos,int &numDatos){
    int buffer[1000];
    numDatos=0;
    while(true){
        cin>>buffer[numDatos];
        if(cin.eof()) break;
        numDatos++;
    }
    datos=new int[numDatos];
    for(int i=0;i<numDatos;i++){
        datos[i]=buffer[i];
    }
}

void imprimirDatos(const int *datos,int numDatos){
    for(int i=0;i<numDatos;i++){
        cout<<setw(5)<<datos[i];
    }
    cout<<endl;
}