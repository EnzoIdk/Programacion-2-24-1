
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <cstring>

using namespace std;

#include "AperturaDeArchivos.h"
#include "funciones.h"
#define TAM_LINEA 70
#define NO_ENCONTRADO -1

enum Lib{COD,TIT,AUT};
enum Cli{DNI,NOMB,LISTA,CANT};

void leerLibros(const char *nombArch,void *&lib){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    void *bufferLib[300]{},**libros;
    int numDat=0;
    while(true){
        leerRegLib(arch,bufferLib[numDat]);
        if(arch.eof()) break;
        numDat++;
    }
    libros=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) libros[i]=bufferLib[i];
    lib=libros;
//    imprimirLibros(lib);
}

void leerRegLib(ifstream &arch,void *&reg){
    void **registro=new void*[3]{};
    char *codigo,*titulo,*autor;
    codigo=leerCadena(arch,',');
    if(arch.eof()) return;
    titulo=leerCadena(arch,',');
    autor=leerCadena(arch,',');
    while(arch.get()!='\n');
    registro[COD]=codigo;
    registro[TIT]=titulo;
    registro[AUT]=autor;
    reg=registro;
}

char *leerCadena(ifstream &arch,char delim){
    char cadena[60],*ptr;
    arch.getline(cadena,60,delim);
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void imprimirLibros(void *lib){
    void **libros=(void**)lib;
    for(int i=0;libros[i];i++){
        imprimirLibro(libros[i]);
    }
}

void imprimirLibro(void *lib){
    void **libro=(void**)lib;
    char *codigo=(char*)libro[COD],*titulo=(char*)libro[TIT],*autor=(char*)libro[AUT];
    cout<<left<<setw(10)<<codigo<<setw(60)<<titulo<<setw(40)<<autor<<endl;
}

void leerClientes(const char *nombArch,void *&cli){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    void *bufferCli[100]{},**clientes;
    int numDat=0;
    while(true){
        leerRegCli(arch,bufferCli[numDat]);
        if(arch.eof()) break;
        numDat++;
    }
    clientes=new void*[numDat+1]{};
    for(int i=0;i<numDat;i++) clientes[i]=bufferCli[i];
    cli=clientes;
}

void leerRegCli(ifstream &arch,void *&reg){
    void **registro=new void*[4]{};
    int *dni=new int,*cant=new int;
    char *nombre;
    void **lista;
    arch>>*dni;
    if(arch.eof()) return;
    arch.get();
    nombre=leerCadena(arch,'\n');
    *cant=0;
    lista=new void*[100]{};
    registro[DNI]=dni;
    registro[NOMB]=nombre;
    registro[LISTA]=lista;
    registro[CANT]=cant;
    reg=registro;
}

void imprimirClientes(const char *nombArch,void *cli){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    void **clientes=(void**)cli;
    for(int i=0;clientes[i];i++){
        imprimirCliente(arch,clientes[i]);
    }
}

void imprimirCliente(ofstream &arch,void *cli){
    void **cliente=(void**)cli;
    int *dni=(int*)cliente[DNI],*cant=(int*)cliente[CANT];
    char *nombre=(char*)cliente[NOMB];
    imprimirLinea(arch,TAM_LINEA,'=');
    arch<<"DNI: "<<*dni<<setw(3)<<' '<<"NOMBRE: "<<nombre<<endl;
    /*forma como estará el módulo para imprimir según Cueva*/
    imprimirListaPed(arch,cliente[LISTA],*cant);
}

void imprimirListaPed(ofstream &arch,void *listaPed,int cant){
    void **pedidos=(void**)listaPed;
    for(int i=0;i<cant;i++){
        if(i==0){
            imprimirLinea(arch,TAM_LINEA,'-');
            arch<<setw(2)<<' '<<"LISTA DE LIBROS PEDIDOS"<<endl;
            imprimirLinea(arch,TAM_LINEA,'-');
        }
        imprimirPed(arch,pedidos[i]);
    }
}

void imprimirPed(ofstream &arch,void *ped){
    void **pedido=(void**)ped;
    char *codigo=(char*)pedido[0],*nombre=(char*)pedido[1];
    arch<<setw(3)<<' '<<codigo<<setw(3)<<' '<<nombre<<endl;
}

void analizarPedidos(const char *nombArch,void *lib,void *cli){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    void **libros=(void**)lib,**clientes=(void**)cli;
    int dni,posLib,posCli;
    char *codPed;
    while(true){
        leerDatos(arch,dni,codPed);
        if(arch.eof()) break;
//        cout<<dni<<' '<<pedido<<endl;
        posCli=buscarCliente(clientes,dni);
        posLib=buscarLibro(libros,codPed);
        if(posCli!=NO_ENCONTRADO and posLib!=NO_ENCONTRADO){
            agregarPedido(clientes[posCli],libros[posLib],codPed);
        }
    }
    for(int i=0;clientes[i];i++){
        memoriaExacta(clientes[i]);
    }
}

void memoriaExacta(void *cli){
    void **cliente=(void**)cli;
    int *cant=(int*)cliente[CANT];
    void **pedidos=(void**)cliente[LISTA];
    void **aux=new void*[*cant+1]{};
    for(int i=0;i<*cant;i++) aux[i]=pedidos[i];
    delete pedidos;
    cliente[LISTA]=aux;
}

void leerDatos(ifstream &arch,int &dni,char *&pedido){
    arch>>dni;
    if(arch.eof()) return;
    arch.get();
    pedido=leerCadena(arch,'\n');
}

int buscarCliente(void **clientes,int dni){
    for(int i=0;clientes[i];i++){
        if(esCliente(clientes[i],dni)) return i;
    }
    return NO_ENCONTRADO;
}

bool esCliente(void *cli,int dni){
    void **cliente=(void**)cli;
    int *dniCli=(int*)cliente[DNI];
    return dni==*dniCli;
}

int buscarLibro(void **libros,char *codPed){
    for(int i=0;libros[i];i++){
        if(esLibro(libros[i],codPed)) return i;
    }
    return NO_ENCONTRADO;
}

bool esLibro(void *lib,char *codPed){
    void **libro=(void**)lib;
    char *codigo=(char*)libro[COD];
    return strcmp(codPed,codigo)==0;
}

void agregarPedido(void *cli,void *lib,char *codPed){
    void **cliente=(void**)cli,**libro=(void**)lib;
    int *cant=(int*)cliente[CANT];
    char *titulo=(char*)libro[TIT];
    agregarDatosALista(cliente[LISTA],*cant,codPed,titulo);
    (*cant)++;
}

void agregarDatosALista(void *lis,int cant,char *codPed,char *titulo){
    void **lista=(void**)lis,**auxLista;
    lista[cant]=new void*[2]{};
    auxLista=(void**)lista[cant];
    auxLista[0]=codPed;
    auxLista[1]=titulo;
}

void imprimirLinea(ofstream &arch,int longitud,char simbolo){
    for(int i=0;i<longitud;i++) arch.put(simbolo);
    arch<<endl;
}