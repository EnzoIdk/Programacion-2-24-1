/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
enum Nodo{
    VALOR, SIGUIENTE, ANTERIOR
};
enum Lista{
    INICIO, FIN
};
void  cosntruirDobleAtras(void *dato, void *&lista){
    void **nuevoDato=new void*[3]{};    
    nuevoDato[VALOR]=dato;
    if(lista==nullptr){
         void**cabeza=new void*[2]{};
         cabeza[INICIO]=nuevoDato;
         cabeza[FIN]=nuevoDato;
         lista=cabeza;
    }else{
        void **cabeza=(void**)lista;
        void **ultimo=(void**)cabeza[FIN];
        ultimo[SIGUIENTE]=nuevoDato;
        nuevoDato[ANTERIOR] = ultimo;
        cabeza[FIN]=nuevoDato;
    }
}

