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
    VALOR, SIGUIENTE
};

void  construirLista(void *dato, void *&cima){
    void **nuevoDato=new void*[2]{};    
    nuevoDato[VALOR]=dato;
    if (cima==nullptr){//si no hay elementos
        cima=nuevoDato;
    }else{
        nuevoDato[SIGUIENTE]=cima;
        cima=nuevoDato;
    }
}