/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
enum registro{
    CODIGO, CANTIDAD, PESO
};
enum camion{
    PILA, MAX
};
void *leeregistro(ifstream &arch){
    //JXD-139,50375303,6,120//
    int cant, *cn=new int, dni;
    char cadena[600]{}, *aux;
    double peso, *pes=new double;
    arch.getline(cadena, 600 ,',');
    if (arch.eof()) return nullptr;
     aux=new char[strlen(cadena)+1]{};
    strcpy(aux, cadena);
    arch>>dni;
    arch.get();
    arch>>cant;
    *cn=cant;
    arch.get();
    arch>>peso;
    *pes=peso;
    arch.get();
    void **registro=new void*[3]{};
    registro[CODIGO]=aux;
    registro[CANTIDAD]=cn;
    registro[PESO]=pes;
    return registro;
}
 int calcularegistro(void *numero){
     void **aux=(void**)numero;
     int *can=(int*)aux[CANTIDAD] ;
     return *can;
}
 int cmpRegistro(const void*a, const void*b){
     void **ai=(void**)a;
    void **bi=(void**)b;
    void **regA=(void**)(*ai);
    void **regB=(void**)(*bi);
    int  *valorA=(int*)regA[MAX];
    int  *valorB=(int*)regB[MAX];
    return *valorB-*valorA;
 }
 void  imprimeregistro(ofstream &arch,void*reg){
     void **registro=(void**)reg;
     char *codigo=(char*)registro[CODIGO];
     int *canti=(int*)registro[CANTIDAD];
     double *pes=(double*)registro[PESO];
     if (*canti>0)arch<<setprecision(2)<<fixed<<setw(20)<<right<<codigo<<setw(15)<<*canti<<setw(15)<<*pes<<endl;
     
 }