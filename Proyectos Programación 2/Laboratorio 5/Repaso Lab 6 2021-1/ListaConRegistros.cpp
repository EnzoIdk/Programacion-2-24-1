/* 
 * File:   ListaConRegistros.cpp
 * Author: Lucas
 *
 * Created on 3 de mayo de 2024, 0:04
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "ListaConRegistros.h"

enum Registro{FECHA, DNI, NOMBRE, FALTA};

void * leeRegistro(ifstream &arch){
    void ** registro=new void*[4]{};
    int * dni=new int, * fecha=new int, * falta=new int, dd, mes , aa, 
            faltaTemp, dniTemp;
    char * placa=new char[8]{}, bin;
    //60784914,A8J-929,19/10/2019,319
    arch>>dniTemp;
    if(arch.eof()) return nullptr;
    *dni=dniTemp;
    arch.get(); //,
    arch.getline(placa, 8, ',');
    arch>>dd>>bin>>mes>>bin>>aa;
    *fecha=(aa*10000+mes*100+dd);
    arch.get(); //,
    arch>>faltaTemp;
    *falta=faltaTemp;
    //GUARDAMOS
    registro[DNI]=dni;
    registro[FECHA]=fecha;
    registro[NOMBRE]=placa;
    registro[FALTA]=falta;
    return registro;
}

int cmpRegistro(const void * datoA, const void * datoB){
    void ** auxDatoA=(void ** )datoA, ** auxDatoB=(void ** )datoB;
    int * fechaA=(int * )auxDatoA[FECHA], * fechaB=(int * )auxDatoB[FECHA];
    return *fechaA-*fechaB;
}

void imprimeRegistro(ofstream &arch, void * registro){
    void ** auxRegistro=(void ** )registro;
    int * fecha=(int * )auxRegistro[FECHA], * dni=(int * )auxRegistro[DNI], 
            * falta=(int * )auxRegistro[FALTA];
    char * placa=(char * )auxRegistro[NOMBRE];
    arch<<*fecha<<setw(12)<<placa<<setw(15)<<*dni<<setw(10)<<*falta<<endl;
}
