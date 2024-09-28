/* 
 * File:   Virtual.cpp
 * Author: ramir
 * 
 * Created on 7 de junio de 2024, 11:10 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0.0;
}

Virtual::Virtual(const Virtual& orig) {
}

Virtual::~Virtual() {
    if(licencia) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char *cad){
    if(licencia) delete licencia;
    licencia = new char[strlen(cad)+1];
    strcpy(licencia,cad);
}
    
void Virtual::GetLicencia(char *cad) const{
    if(licencia) strcpy(cad,licencia);
    else cad[0] = '\0';
}
//202318072,RIVERA/MONTERO/GLORIA-OFELIA,3,20,323R33-02
void Virtual::lee(ifstream &archAlum){
    char lic[10];
    
    Alumno::lee(archAlum);
    archAlum.getline(lic,20);
    SetLicencia(lic);
}

void Virtual::imprime(ofstream &archRep){
    Alumno::imprime(archRep);
    archRep<<setw(12)<<licencia<<setw(10)<<total<<endl;
}