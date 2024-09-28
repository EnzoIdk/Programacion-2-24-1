
/*/ 
 * Projecto:  Prueba_Biblioteca_Complicada_2023_2
 * Nombre del Archivo:  funciones.cpp
 * Autor: El Real Candy
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "funciones.h"
#define MAXLINEA 224

  /* Funciones para las Pruebas de Entrada, Actualizacion y Salida de Datos */

// Modulo SOBRECARGADO de Lectura de Datos de 'Cliente'
void obtenerDatos(struct Cliente *arrCli,const char *nombCli){
    // Apertura de Archivos
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,nombCli);
    // Lectura de Datos
    for(int i = 0;archCli>>arrCli[i];i++);
}
// Modulo SOBRECARGADO de Lectura de Datos de 'Producto'
void obtenerDatos(struct Producto *arrProd,const char *nombProd){
    // Apertura de Archivos
    ifstream archProd;
    AperturaDeUnArchivoDeTextosParaLeer(archProd,nombProd);
    // Lectura de Datos
    for(int i = 0;archProd>>arrProd[i];i++);
}
// Modulo SOBRECARGADO de Lectura de Datos de 'Pedido'
void obtenerDatos(struct Pedido *arrPed,const char *nombPed){
    // Apertura de Archivos
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,nombPed);
    // Lectura de Datos
    for(int i = 0;archPed>>arrPed[i];i++);
}
// Modulo del Proceso de Actualizacion de Datos
void procesarDatos(struct Cliente *arrCli,struct Producto *arrProd,
                   struct Pedido *arrPed){
    // Iterativa del Proceso de Actualizacion de Datos
    for(int i = 0;strcmp(arrPed[i].CodigoProducto,"XXXXXXX") != 0;i++){
        arrProd += arrPed[i];                                                   // Primero se realiza la actualizacion por Productos, pues el precio del producto pedido se transcribe al pedido recien aqui.
        arrCli += arrPed[i];
    }
}
// Modulo de Impresion de Datos en Formato de Reporte
void imprimirDatos(struct Cliente *arrCli,struct Producto *arrProd,
                   struct Pedido *arrPed,const char *nombSalida){
    // Apertura de Archivos
    ofstream archSalida;
    AperturaDeUnArchivoDeTextosParaEscribir(archSalida,nombSalida);
    // Emision en Formato de Reporte
    imprimirEncabezado(archSalida,'C');
    for(int i = 0;archSalida<<arrCli[i];i++);
    imprimirLinea(archSalida,MAXLINEA,'=');
    imprimirEncabezado(archSalida,'P');
    for(int i = 0;archSalida<<arrProd[i];i++);
    imprimirLinea(archSalida,MAXLINEA,'=');
}
// Modulo de Impresion de Simbolos en Linea
void imprimirEncabezado(ofstream &archSalida,char seleccion){
    switch(seleccion){
        case 'C':
            archSalida<<setw((115+20)/2)<<"REPORTE POR CLIENTES"<<endl;
            imprimirLinea(archSalida,MAXLINEA,'-');
            archSalida<<setw(9)<<"DNI"<<setw(13)<<"NOMBRE";
            archSalida<<setw(56)<<"TELEFONO"<<setw(14)<<"MONTO TOTAL"<<endl;
            imprimirLinea(archSalida,MAXLINEA,'-');
            break;
        case 'P':
            archSalida<<setw((89+21)/2)<<"REPORTE POR PRODUCTOS"<<endl;
            imprimirLinea(archSalida,MAXLINEA,'-');
            archSalida<<setw(10)<<"CODIGO"<<setw(16)<<"DESCRIPCION";
            archSalida<<setw(59)<<"PRECIO"<<setw(12)<<"STOCK"<<endl;
            imprimirLinea(archSalida,MAXLINEA,'-');
            break;
        default:
            cout<<"ERROR: Tipo de Reporte Indefinido."<<endl;
            exit(1);
    }
}
// Modulo de Impresion de Simbolo en Linea
void imprimirLinea(ofstream &archSalida,int medida,char simbolo){
    for(int i = 0;i < medida;i++) archSalida.put(simbolo);
    archSalida<<endl;
}
