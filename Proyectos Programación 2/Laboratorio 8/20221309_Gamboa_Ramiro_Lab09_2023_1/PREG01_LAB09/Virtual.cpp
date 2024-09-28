/* 
 * File:   Virtual.cpp
 * Author: ramir
 * 
 * Created on 5 de junio de 2024, 02:47 PM
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
//202318072,RIVERA/MONTERO/GLORIA-OFELIA,3,20,323R33-2
void Virtual::lee(ifstream &archBol){
    char lic[10];
    
    Alumno::lee(archBol);
    archBol.getline(lic,10);
    SetLicencia(lic);
}

void Virtual::imprime(ofstream &archRep){
    archRep<<fixed<<setprecision(2);
    Alumno::imprime(archRep);
    archRep<<left<<setw(10)<<licencia<<right<<setw(11)<<total<<endl;
}