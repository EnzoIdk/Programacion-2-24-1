/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 132
 *
 * Created on 5 de junio de 2024, 01:20 PM
 */

#include "Pila.h"

void imprimeInt(void *dato){
    cout<<*(int*)dato<<"->";
}

void hanoi3(int n,Pila &A,Pila &C,Pila &B){
    if(n==0) return;
    hanoi3(n-1,A,B,C);
    C.apilar(A.desapilar());
    hanoi3(n-1,B,C,A);
}

int main(int argc, char** argv) {
    Pila pila;
    
    int **n=new int*[5];
    
    for(int i=0;i<5;i++){
        n[i]=new int;
        *n[i]=(i+1)*10;
    }
    
    for(int i=0;i<5;i++)
        pila.apilar(n[i]);
    
    void *datoAlFondo=pila.fondo();
    cout<<"Dato al fondo de la pila: "<<*(int*)datoAlFondo<<endl;
    
    pila.invertir();
    
    Pila pilaDuplicadaDoblemente;
    pila.duplicarDoblemente(pilaDuplicadaDoblemente);
    
    cout<<"Pila duplicada: "<<endl;
    pilaDuplicadaDoblemente.imprimir(imprimeInt);
    
    cout<<"Pila original: "<<endl;
    pila.imprimir(imprimeInt);
    
    cout<<"Pila original concatenada: "<<endl;
    pila.concatenar(pilaDuplicadaDoblemente);
    pila.imprimir(imprimeInt);
    pilaDuplicadaDoblemente.imprimir(imprimeInt);
    
    Pila pilaMerge,pilaOrigen1,pilaOrigen2;
    for(int i=0;i<5;i++){
        pilaOrigen1.apilar(n[i]);
        pilaOrigen2.apilar(n[i]);
    }
    pilaOrigen2.invertir();
    
    pilaMerge.mezclar(pilaOrigen1,pilaOrigen2);
    cout<<"Pila mezclada:"<<endl;
    pilaMerge.imprimir(imprimeInt);
    pilaOrigen1.imprimir(imprimeInt);
    pilaOrigen2.imprimir(imprimeInt);
    
    Pila aux,destino;
    hanoi3(pilaMerge.profundidad(),pilaMerge,destino,aux);
    cout<<"Datos pasados con hanoi:"<<endl;
    destino.imprimir(imprimeInt);
    
    return 0;
}

