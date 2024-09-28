/* 
 * File:   PunterosGenericos.cpp
 * Author: Lucas
 *
 * Created on 21 de abril de 2024, 19:28
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "PunterosGenericos.h"

#define NOTFOUND -1

enum Producto{COD, DESC, PREC, TIPO};
enum Cliente{DNI, NOMB, LISTA, LINEA};
enum Pedido{CANT=1, TOTAL};

void cargarProductos(const char * nombArch, void * &productos){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    int numProd=0; //USAREMOS EL METODO EXACTO
    void * arrProductos[200]{}, ** productosFinal;
    //EUZ-452,Impresora Mutifuncional Led Color,3623.88,N
    while(true){
        arrProductos[numProd]=leerProducto(arch);
        if(arch.eof()) break;
        numProd++;
    }
    //METODO EXACTO
    productosFinal=new void*[numProd+1]{};
    for(int i=0; i<numProd; i++){
        productosFinal[i]=arrProductos[i];
    }
    productos=productosFinal;
}

void * leerProducto(ifstream &arch){
    void ** producto;
    char * cod, * descripcion, * tipo, tipoTemp;
    double * precio, precioTemp;
    //EUZ-452,Impresora Mutifuncional Led Color,3623.88,N
    cod=leerCadena(arch, ',');
    if(arch.eof()) return nullptr;
    descripcion=leerCadena(arch, ',');
    arch>>precioTemp;
    arch.get(); //,
    arch>>tipoTemp;
    arch.get(); //\n
    //GUARDAMOS
    precio=new double;
    *precio=precioTemp;
    tipo=new char;
    *tipo=tipoTemp;
    producto=new void*[4]{};
    producto[COD]=cod;
    producto[DESC]=descripcion;
    producto[PREC]=precio;
    producto[TIPO]=tipo;
    return producto;
}

char * leerCadena(ifstream &arch, char delim){
    char aux[100]{}, * cad;
    arch.getline(aux, 100, delim);
    if(arch.eof()) return nullptr;
    cad=new char[strlen(aux)+1]{};
    strcpy(cad, aux);
    return cad;
}

void cargaClientes(const char * nombArch, void * &clientes){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    int numClientes=0;
    void * arrClientes[200]{}, ** clientesFinal;
    //43043986,LOZADA VALVERDE MOISES HENRRY,8816113,10000
    while(true){
        arrClientes[numClientes]=leerCliente(arch);
        if(arch.eof()) break;
        numClientes++;
    }
    //METODO EXACTO
    clientesFinal=new void*[numClientes+1]{};
    for(int i=0; i<numClientes; i++){
        clientesFinal[i]=arrClientes[i];
    }
    clientes=clientesFinal;
}

void * leerCliente(ifstream &arch){
    void ** cliente;
    int * dni, dniTemp;
    double * linea, lineaTemp;
    char * nombre;
    arch>>dniTemp;
    if(arch.eof()) return nullptr;
    arch.get(); //,
    nombre=leerCadena(arch, ',');
    while(arch.get()!=','); //NO NECESITAMOS EL TELEFONO
    arch>>lineaTemp;
    //GUARDAMOS
    linea=new double;
    dni=new int;
    *linea=lineaTemp;
    *dni=dniTemp;
    cliente=new void*[4]{};
    cliente[DNI]=dni;
    cliente[NOMB]=nombre;
    cliente[LISTA]=nullptr;
    cliente[LINEA]=linea;
    return cliente;
}

void cargaPedidos(const char * nombArch, void * productos, void * clientes){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    //IHG-413,33397650,3
    char * cod;
    int dni, cant, numPedidos[200]{};
    while(true){
        leerPedido(arch, cod, dni, cant);
        if(arch.eof()) break;
        procesarPedido(cod, dni, cant, productos, clientes, numPedidos);
    }
    //MEMORIA EXACTA
    memoriaExacta(clientes, numPedidos);
}

void leerPedido(ifstream &arch, char * &cod, int &dni, int &cant){
    cod=leerCadena(arch, ',');
    if(arch.eof()) return;
    arch>>dni;
    arch.get(); //,
    arch>>cant;
    arch.get(); //\n
}

void procesarPedido(char * cod, int dni, int cant, void * productos, 
        void * clientes, int * numPedidos){
    void ** arrProd=(void ** )productos, ** arrClientes=(void ** )clientes;
    int posProd, posCli;
    posProd=buscarProductos(cod, arrProd);
    posCli=buscaCliente(dni, arrClientes);
    if(posProd!=NOTFOUND and posCli!=NOTFOUND){
//        cout<<posCli<<" "<<posProd<<endl;
        agregarPedido(arrClientes[posCli], arrProd[posProd], cant, 
                numPedidos[posCli]);
    }
}

int buscarProductos(char * cod, void ** arrProd){
    for(int i=0; arrProd[i]; i++){
        if(comparaCodigo(cod, arrProd[i])) return i;
    }
    return NOTFOUND;
}

bool comparaCodigo(char * cod, void * producto){
    void ** prodAux=(void ** )producto;
    char * aux=(char * )prodAux[COD];
    return strcmp(cod, aux)==0;
}

int buscaCliente(int dni, void ** arrClientes){
    for(int i=0; arrClientes[i]; i++){
        if(comparaDni(dni, arrClientes[i])) return i;
    }
    return NOTFOUND;
}

bool comparaDni(int dni, void * cliente){
    void ** clienteAux=(void ** )cliente;
    int * aux=(int * )clienteAux[DNI];
    return (*aux)==dni;
}

void agregarPedido(void * cliente, void * producto, int cant, int &numPedidos){
    void ** auxCliente=(void ** )cliente;
    void ** auxProducto=(void ** )producto;
    double * precio=(double * )auxProducto[PREC], 
            * linea=(double * )auxCliente[LINEA];
    char * tipo=(char * )auxProducto[TIPO], * cod=(char * )auxProducto[COD];
    //INICIALIZACION - CREAMOS UN BUFFER TEMPORAL
    if(numPedidos==0) auxCliente[LISTA]=new void*[100]{}; 
//    cout<<auxCliente[LISTA]<<endl;
    //YA TENEMOS LOS DATOS, AHORA AGREGAMOS EL PEDIDO
    if((*tipo)=='S'){
        if((*linea)>=(*precio)*cant){
            (*linea)-=(*precio)*cant;
            finalizarPedido(auxCliente[LISTA], numPedidos, cod, cant, 
                    (*precio)*cant);
            numPedidos++;
        }
    }
    else{ //NO ES NECESARIO VERIFICAR LA LINEA
        finalizarPedido(auxCliente[LISTA], numPedidos, cod, cant, 
                    (*precio)*cant);
        numPedidos++;
    }   
}

void finalizarPedido(void * listaCliente, int numPedidos, char * cod, int cant, 
        double total){
    void ** auxListaCliente=(void ** )listaCliente;
    auxListaCliente[numPedidos]=guardarPedido(cod, cant, total);
}

void * guardarPedido(char * cod, int cant, double total){
    void ** pedido;
    int * cantTemp;
    double * totalTemp;
    //INICIALIZAMOS
    cantTemp=new int;
    totalTemp=new double;
    pedido=new void*[3]{};
    *cantTemp=cant;
    *totalTemp=total;
    //GUARDAMOS
    pedido[COD]=cod;
    pedido[CANT]=cantTemp;
    pedido[TOTAL]=totalTemp;
    return pedido;
}

void memoriaExacta(void * clientes, int * numPedidos){
    void ** arrClientes=(void ** )clientes;
    for(int i=0; arrClientes[i]; i++){
        asignarMemoriaExacta(arrClientes[i], numPedidos[i]);
    }
}

void asignarMemoriaExacta(void * cliente, int numPedidos){
    void ** auxCliente=(void ** )cliente;
    void ** lista=(void ** )auxCliente[LISTA];
    void ** arrPedidos=new void*[numPedidos+1]{};
    for(int i=0; i<numPedidos; i++){
        arrPedidos[i]=lista[i];
    }
    //DEBEMOS HACER delete A UN void ** Y NO A UN void *
    delete lista;
    auxCliente[LISTA]=arrPedidos;
}
