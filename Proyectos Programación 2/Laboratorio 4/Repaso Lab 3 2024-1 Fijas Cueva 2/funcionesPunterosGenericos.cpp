/* 
 * File:   funcionesPunterosGenericos.cpp
 * Author: Lucas
 *
 * Created on 25 de abril de 2024, 17:30
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "AperturaDeArchivos.h"
#include "funcionesPunterosGenericos.h"

#define NOTFOUND -1
#define MAXLINEA 100

enum Cliente{NOMBRE, DNI};

//CARGA INICIAL DE CLIENTES
void cargarClientes(const char * nombArch, void * &clientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    void * buffClientes[100]{};
    int numClientes=0;
    //14500753,Delgado Gonzales Guillermo Alfonso
    while(true){
        buffClientes[numClientes]=leerCliente(arch);
        if(arch.eof()) break;
        numClientes++;
    }
    //MEMORIA EXACTA
    clientes=memoriaExacta(buffClientes, numClientes);
}

void * leerCliente(ifstream &arch){
    void ** cliente;
    int * dni, dniTemp;
    char * nombre;
    arch>>dniTemp;
    if(arch.eof()) return nullptr;
    arch.get(); //,
    nombre=leerCadena(arch, '\n');
    //GUARDAMOS
    dni=new int;
    *dni=dniTemp;
    cliente=new void*[2]{};
    cliente[DNI]=dni;
    cliente[NOMBRE]=nombre;
    return cliente;
}

char * leerCadena(ifstream &arch, char delim){
    char aux[100]{}, * cad;
    arch.getline(aux, 100, delim);
    if(arch.eof()) return nullptr;
    cad=new char[strlen(aux)+1]{};
    strcpy(cad, aux);
    return cad;
}

void * memoriaExacta(void ** buffer, int numDatos){
    void ** exacto=new void*[numDatos+1]{};
    for(int i=0; i<numDatos; i++){
        exacto[i]=buffer[i];
    }
    return exacto;
}

//IMPRESION DE CLIENTES
void imprimirClientes(const char * nombArch, void * clientes){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);
    void ** arrClientes=(void ** )clientes;
    arch<<"DNI"<<setw(14)<<"NOMBRE"<<endl;
    for(int i=0; arrClientes[i]; i++){
        imprimeCliente(arch, arrClientes[i]);
    }
}

void imprimeCliente(ofstream &arch, void * cliente){
    void ** datosCliente=(void ** )cliente;
    int * dni=(int * )datosCliente[DNI];
    char * nombre=(char * )datosCliente[NOMBRE];
    arch<<*dni<<" - "<<nombre<<endl;
}

//CARGA DE PEDIDOS
void cargarPedidos(const char * nombArch, void * &pedidos, void * clientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    void * buffPedidos[100]{};
    int numPedidos=0, num, dni;
    char * cod;
    //000011,60740809,XTM9385
    while(true){
        leerPedido(arch, num, dni, cod);
        if(arch.eof()) break;
        buffPedidos[num-1]=generarPedido(dni, cod, clientes, num);
        numPedidos++;
    }
    //ELIMINAMOS EL TEMPORAL DE LIBROS
    guardarLibrosExactos(buffPedidos);
    //MEMORIA EXACTA
    pedidos=memoriaExacta(buffPedidos, numPedidos);
}

void leerPedido(ifstream &arch, int &num, int &dni, char * &cod){
    arch>>num;
    if(arch.eof()) return;
    arch.get(); //,
    arch>>dni;
    arch.get(); //,
    cod=leerCadena(arch, '\n');
}

void * generarPedido(int dni, char * cod, void * clientes, int num){
    void ** arrClientes=(void ** )clientes, ** pedido;
    int pos=buscarCliente(dni, arrClientes);
    if(pos!=NOTFOUND){
        pedido=new void*[5]{};
        guardarDatos(pedido, cod, arrClientes[pos], num);
    }
    else return nullptr;
    return pedido;
}

int buscarCliente(int dni, void ** arrClientes){
    for(int i=0; arrClientes[i]; i++){
        if(comparaCliente(dni, arrClientes[i])) return i;
    }
    return NOTFOUND;
}

bool comparaCliente(int dni, void * cliente){
    void ** datosCliente=(void ** )cliente;
    int * dniCliente=(int * )datosCliente[DNI];
    return dni==*dniCliente;
}

void guardarDatos(void ** pedido, char * cod, void * cliente, int num){
    void ** datosCliente=(void ** )cliente;
    void ** listaLibros=new void*[50]{}; //BUFFER TEMPORAL
    int * dni=(int * )datosCliente[DNI];
    char * nombre=(char * )datosCliente[NOMBRE];
    int * numPed=new int, * numLibros=new int;
    *numPed=num;
    *numLibros=1;
    //GUARDADO PREVIO
    listaLibros[0]=cod;
    //GUARDAMOS
    pedido[0]=numPed;
    pedido[1]=dni;
    pedido[2]=nombre;
    pedido[3]=listaLibros;
    pedido[4]=numLibros;
}

void guardarLibrosExactos(void ** buffPedidos){
    for(int i=0; buffPedidos[i]; i++){
        finalizarExacto(buffPedidos[i]);
    }
}

void finalizarExacto(void * pedido){
    void ** datosPedido=(void ** )pedido, ** arrLibrosExacto;
    void ** listaTemporal=(void ** )datosPedido[3];
    int * numLibrosPed=(int * )datosPedido[4];
    //NUEVO
    arrLibrosExacto=new void*[(*numLibrosPed)+1]{};
    for(int i=0; i<*numLibrosPed; i++){
        arrLibrosExacto[i]=listaTemporal[i];
    }
    delete listaTemporal;
    datosPedido[3]=arrLibrosExacto;
}

//IMPRESION FINAL
void imprmirPedidos(const char * nombArch, void * pedidos, void * clientes){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);
    void ** arrPedidos=(void ** )pedidos;
    void ** arrClientes=(void ** )clientes;
    for(int i=0; arrClientes[i]; i++){
        imprimePedido(arch, arrClientes[i], arrPedidos);
    }
}


void imprimePedido(ofstream &arch, void * cliente, void ** arrPedidos){
    bool encontro=false;
    void ** datosCliente=(void ** )cliente;
    int * dni=(int * )datosCliente[DNI];
    char * nombre=(char * )datosCliente[NOMBRE];
    
    arch<<"DNI: "<<setw(12)<<*dni<<setw(15)<<"Nombre:  "<<left<<setw(60)<<nombre
            <<right<<endl;
    arch<<"Lista de pedidos:"<<endl;
    imprimirLinea(arch, MAXLINEA, '-');
    
    for(int i=0; arrPedidos[i]; i++){
        if(encuentraPedido(*dni, arrPedidos[i])){
            imprimePedido(arch, arrPedidos[i]);
            encontro=true;
        }
    }
    if(not encontro) arch<<"NO HAY PEDIDOS"<<endl;
    imprimirLinea(arch, MAXLINEA, '=');
}

bool encuentraPedido(int dni, void * pedido){
    void ** datosPedido=(void ** )pedido;
    int * dniPed=(int * )datosPedido[1];
    return dni==*dniPed;
}

void imprimePedido(ofstream &arch, void * pedido){
    void ** datosPedido=(void ** )pedido;
    int * numLibros=(int * )datosPedido[4], * num=(int * )datosPedido[0];
    void ** listaPedidos=(void ** )datosPedido[3];
    
    arch<<"Pedido:  "<<setfill('0')<<setw(6)<<*num<<setfill(' ')<<endl;
    arch<<"Lista de libros:"<<endl;
    if(listaPedidos!=nullptr){
        for(int i=0; i<*numLibros; i++) 
            imprimeLibroPedido(arch, listaPedidos[i]);
    }
    else arch<<"NO HAY LIBROS EN ESTE PEDIDO"<<endl;
    imprimirLinea(arch, MAXLINEA/4, '.');
}

void imprimeLibroPedido(ofstream &arch, void * libro){
    char * cod=(char * )libro;
    arch<<cod<<endl;
}

void imprimirLinea(ofstream &arch, int largo, char car){
    for(int i=0; i<largo; i++) arch<<car;
    arch<<endl;
}

