/* 
 * Proyecto: LAB07_PREG02_CARGA
 * File:   funcionesSolucion.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 10 de junio de 2022, 9:04
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Cliente.h"
#include "Pedido.h"

#include "sobrecargaOperaciones.h"
#include "funcionesSolucion.h"

void leeclientes(Cliente *lista) {
    ifstream archCli("clientes2.csv",ios::in);
    if(!archCli){
        cout << "No se puede abrir los clientes2";
        exit(1);
    }

    int i = 0;
    while (1) {
        archCli >> lista[i];
        if (archCli.eof()) break;
        i++;
    }
}

void leepedidos(Pedido *lista) {
    ifstream archPed("pedidos2.csv",ios::in);
    if(!archPed){
        cout << "No se puede abrir los pedidos2";
        exit(1);
    }

    int i = 0;
    while (1) {
        archPed >> lista[i];
        if (archPed.eof())break;
        i++;
    }
}

// ----------------------------------------------------------------------------

void anadirpedidos(Cliente *lcliente, Pedido *lpedido){
    int dniPedido, dniCliente;
    for(int i=0; lpedido[i].GetCodigo(); i++) {
        dniPedido = lpedido[i].GetDni();
        
        for(int j=0; lcliente[j].GetDni(); j++){
            dniCliente = lcliente[j].GetDni();
            if(dniCliente == dniPedido){
                lcliente[j] = lpedido[i];
                break;
            }
        }
    }
}

void eliminarpedido(Cliente *lcliente){
    ifstream archPed("eliminar2.csv",ios::in);
    if(!archPed){
        cout << "No se puede abrir los eliminar2";
        exit(1);
    }
    Pedido ped;
    
    while(1) {
        archPed >> ped;
        if(archPed.eof()) break;
        
        for(int j=0; lcliente[j].GetDni(); j++){
            lcliente[j] -= ped;
        }
    }
}

void aplicardescuento(Cliente *lcliente){
    int i = 0;
    char categoria;
    while (lcliente[i].GetDni()) {
        categoria = lcliente[i].GetCategoria();
        if(categoria == 'A'){
            lcliente[i]/10.0;
        }
        i++;
    }
}

// ----------------------------------------------------------------------------

void imprimirclientes(Cliente *lcliente){
    ofstream archRepCli("reporteClientes.txt",ios::out);
    if(!archRepCli){
        cout << "No se pudo abrir las reporteClientes ";
        exit(1);
    }
    
    archRepCli << setprecision(2) << fixed;
    
    int i = 0;
    while (lcliente[i].GetDni()) {
        archRepCli << lcliente[i];
        i++;
    }
}