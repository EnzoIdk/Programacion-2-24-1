/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstring>

using namespace std;

#include "funciones.h"
#define TAM_LINEA 120
#define MAX_DATOS 20
#define NO_ENCONTRADO -1

// sin nada: no se cambia el valor, se usa en reportes más q nada
// con &: se pasa por referencia y se puede cambiar el valor
// con *: hace referencia a punteros y arreglos
// con **: para arreglos de cadenas de caracteres

void emitirReporte(){
    ofstream archReporte("Reporte.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    archReporte<<setprecision(2)<<fixed; /*pasar a que los double se muestren con 2 decimales*/
//    imprimirEncabezado();
    imprimirLinea(archReporte,TAM_LINEA,'=');
}

void leerDatos(){
    /*cin>>ws (te lee hasta encontrar un espacio,tab o enter)*/
    /*cin.get(): lee caracter por caracter*/
    ifstream archIdk("si.txt",ios::in);
    if(not archIdk.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo si.txt"<<endl;
        exit(1);
    }
    //45 c [ejemplo random]
    //34 a
    int codigo;
    char si;
    while(true){
        archIdk>>codigo;
        if(archIdk.eof()) break; /*detener a la primera lectura*/
        archIdk>>si;
    }
}

void tipoDeLecturaEspecial(){
    // se quiere leer: Juan Perez Quispe 89123
    //={0} es para inicializar el arreglo en 0 y se pueda concatenar
    char nombre[100]={0},palabra[20];
    int codigo;
    while(true){
        cin>>codigo;
        if(cin.eof()) exit(1);
        if(cin.fail()){
            cin.clear(); /*levanta la bandera de error*/
            cin>>palabra;
            strcat(nombre,palabra);
            strcat(nombre," ");
        }
        else break;
    }
}

void definirYLlenarArreglos(){
    /*siempre se definen asi, tiene que asignarse una cantidad de datos maxima dentro de []*/
    int arrEnteros[MAX_DATOS],numDatos;
    double arrIdk[MAX_DATOS]{}; /*asi se incializa todo el arreglo en cero*/
    /* llenarArreglo(arrEnteros,cantDatos); 
     * void llenarArreglo(int *arrEnteros,int &cantDatos){
        }  */
    int entero;
    numDatos=0;
    while(true){
        cin>>entero;
        if(cin.eof()) break;
        arrEnteros[numDatos]=entero;
        numDatos++;
    }
}

/*buscar posicion en arreglo*/

int buscarPos(int *arreglo,int dato,int cantDatos){
    for(int i=0;i<cantDatos;i++){
        if(arreglo[i]==dato) return i;
    }
    return NO_ENCONTRADO;
}

/*para hacer la busqueda binaria el arreglo debe estar ordenado, en este caso ascendente*/
int busquedaBinaria(int *arreglo,int dato,int cantDatos){
    int limInf=0,limSup=cantDatos-1,puntoMedio;
    while(true){
        puntoMedio=(limInf+limSup)/2;
        if(arreglo[puntoMedio]==dato) return puntoMedio;
        else if(dato<arreglo[puntoMedio]) limSup=puntoMedio-1; /*sera < o > dependiendo de como este ordenado*/
        else limInf=puntoMedio+1;
        if(limInf>limSup) return NO_ENCONTRADO;
    }
}

/* Uso recurrente: 
    if(posInt!=NO_ENCONTRADO){
        arch>>sgteDato;
    }else while(arch.get()!='\n') --> se salta la linea con esto
 */

int buscarPosCadena(char ){
    
}

void ordenarArreglo(int *arregloInt,int cantDatos){
    /*orden descendente*/
    for(int i=0;i<cantDatos-1;i++){
        for(int j=i+1;j<cantDatos;j++){
            if(arregloInt[j]>arregloInt[i]){
                cambiarInt(arregloInt[i],arregloInt[j]);
            }
        }
    }
}

void cambiarInt(int &dato1,int &dato2){
    int aux=dato1;
    dato1=dato2;
    dato2=aux;
}

/*Funciones con cadenas de caracteres*/

void pasarAMayus(char *nombre){
    for(int i=0;nombre[i];i++){
        if(nombre[i]=='_') nombre[i]=' ';
        else if(nombre[i]>='a' and nombre[i]<='z') nombre[i]+='A'-'a';
    }
}

char *leerCadenaExacta(ifstream &arch){
    char cadena[100],*ptrCadena;
    arch.getline(cadena,100,',');
    if(arch.eof()) return nullptr;
    ptrCadena=new char[strlen(cadena)+1];
    strcpy(ptrCadena,cadena);
    return ptrCadena;
}

/*Funciones auxiliares*/

int juntarFecha(int dd,int mm,int aa){
    return aa*10000+mm*100+dd;
}

void descomponerTiempo(int tiempo,int &hh,int &mm,int &ss){
    hh=tiempo/3600;
    mm=(tiempo%3600)/60;
    ss=tiempo%60;
}

void imprimirFecha(ofstream &archReporte,int dd,int mm,int aa){
    archReporte<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<
            aa<<setfill(' ');
}

void imprimirLinea(ofstream &archReporte,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) archReporte.put(simbolo);
    endl;
}