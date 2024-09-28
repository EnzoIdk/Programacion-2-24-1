#include <iostream>
#include <iomanip>

#include <cstring>

#include "funcionesMemoriaIncrementos.h"

#define INCREMENTO 5
#define NOTFOUND -1

enum Libro{COD, TIT, AUT};
enum Persona{DNI, CANT};

void lecturaDeLibros(const char * nombArch, char *** &libros, int ** &stock){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    char ** libroAux;
    int * stockTemp, cap=0, nd=0;
    //PUEDE HACERSE TAMBIEN UNA INICIALIZACION
    libros=nullptr;
    stock=nullptr;
    //LECTURA
    while(true){
        libroAux=leerLibro(arch);
        if(arch.eof()) break;
        stockTemp=leerStock(arch);
        if(cap==nd) incrementarEspacios(libros, stock, cap, nd);
        //PORQUE DEJAMOS EL ESPACIO FINAL PARA EL 0
        libros[nd-1]=libroAux;
        stock[nd-1]=stockTemp;
        nd++;
    }
}

char ** leerLibro(ifstream &arch){
    char * cod, * titulo, * autor, ** aux;
    cod=leerCadena(arch, ',');
    if(arch.eof()) return nullptr;
    titulo=leerCadena(arch, ',');
    autor=leerCadena(arch, ',');
    //GUARDAMOS
    aux=new char*[3];
    aux[COD]=cod;
    aux[TIT]=titulo;
    aux[AUT]=autor;
    return aux;
}

char * leerCadena(ifstream &arch, char delim){
    char aux[100]{}, * cad;
    int lenAux;
    arch.getline(aux, 100, delim);
    if(arch.eof()) return nullptr;
    lenAux=strlen(aux);
    cad=new char[lenAux+1]{};
    strcpy(cad, aux);
    return cad;
}

int * leerStock(ifstream &arch){
    int temp, * stock;
    arch>>temp;
    while(arch.get()!='\n'); //QUITAMOS EL PRECIO
    //GUARDAMOS
    stock=new int[2]{};
    stock[0]=temp;
    return stock;
}

void incrementarEspacios(char *** &libros, int ** &stock, int &cap, int &nd){
    char *** auxLib;
    int ** auxStock;
    cap+=INCREMENTO;
    if(nd==0){ //O SEA, ES LA PRIMERA LECTURA
        libros=new char**[cap]{};
        stock=new int*[cap]{};
        nd=1;
    }
    else{
        auxLib=new char**[cap]{};
        auxStock=new int*[cap]{};
        for(int i=0; i<nd; i++){
            auxLib[i]=libros[i];
            auxStock[i]=stock[i];
        }
        delete libros;
        delete stock;
        libros=auxLib;
        stock=auxStock;
    }
}

void pruebaDeLecturaDeLibros(const char* nombArch, char*** libros, int** stock){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    char ** auxLibro;
    int * auxStock;
    for(int i=0; libros[i]; i++){
        auxLibro=libros[i];
        auxStock=stock[i];
        arch<<auxLibro[COD]<<" - "<<left<<setw(60)<<auxLibro[TIT]<<setw(40)<<
                auxLibro[AUT]<<right<<setw(10)<<auxStock[0]<<" - "<<
                auxStock[1]<<endl;
    }
}

void atencionDePedidos(const char * nombArch, char *** libros, int ** stock, 
        int ** &pedidosClientes, char *** &pedidosLibros, 
        bool ** &pedidosAtendidos){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR con archivo: "<<nombArch;
        exit(1);
    }
    int ndClientes=0, capClientes=0, capPedidos=0, dni, num, pos, nP[2000]{}, 
            capLibPorPed[2000]{}, capLibrPorCli[2000]{};
    //000090,14268463   BZY0235    PQZ1316      IFL0150     JNC0786
    while(true){
        leerDatosPedido(arch, num, dni);
        if(arch.eof()) break;
        //AUMENTAMOS ESPACIOS
        if(ndClientes==capClientes) incrementarEspacios(pedidosClientes, 
                ndClientes, capClientes);
        if(num>=capPedidos) incrementarEspacios(pedidosLibros, pedidosAtendidos, 
                num, capPedidos);
        pos=buscarPersona(dni, pedidosClientes);
        if(pos==NOTFOUND){
            agregarPersona(dni, pedidosClientes[ndClientes], 
                    capLibrPorCli[ndClientes]);
            pos=ndClientes;
            ndClientes++;
        }
        procesarPedidos(arch, libros, stock, pedidosClientes[pos], 
                pedidosLibros[num-1], pedidosAtendidos[num-1], nP[num-1], 
                capLibPorPed[num-1], capLibrPorCli[pos], num);
    }
}

void leerDatosPedido(ifstream &arch, int &num, int &dni){
    arch>>num;
    if(arch.eof()) return;
    arch.get(); //COMA
    arch>>dni;
}

void incrementarEspacios(int ** &pedidosClientes, int &ndClientes, 
        int &capClientes){
    int ** aux;
    capClientes+=INCREMENTO;
    if(ndClientes==0){
        pedidosClientes=new int*[capClientes]{};
        ndClientes=1;
    }
    else{
        aux=new int*[capClientes]{};
        for(int i=0; i<ndClientes; i++) aux[i]=pedidosClientes[i];
        delete pedidosClientes;
        pedidosClientes=aux;
    }
}

void incrementarEspacios(char *** &pedidosLibros, bool ** &pedidosAtendidos, 
        int num, int &capPedidos){
    char *** auxLib;
    bool ** auxAten;
    if(capPedidos==0){
        pedidosLibros=new char**[num+1]{};
        pedidosAtendidos=new bool*[num+1]{};
        capPedidos=num;
    }
    else if(num>capPedidos){
        auxLib=new char**[num+1]{};
        auxAten=new bool*[num+1]{};
        for(int i=0; i<capPedidos; i++){
            auxAten[i]=pedidosAtendidos[i];
            auxLib[i]=pedidosLibros[i];
        }
        delete pedidosAtendidos;
        delete pedidosLibros;
        pedidosAtendidos=auxAten;
        pedidosLibros=auxLib;
        capPedidos=num;
    }
}

int buscarPersona(int dni, int ** pedidosCliente){
    int * aux;
    for(int i=0; pedidosCliente[i]; i++){
        aux=pedidosCliente[i];
        if(aux[DNI]==dni) return i;
    }
    return NOTFOUND;
}

void agregarPersona(int dni, int * &pedidoCliente, int &capLibCli){
    capLibCli=2;
    pedidoCliente=new int[capLibCli]{}; //PARA LA CANTIDAD DE PEDIDOS QUE 
                                           //PODRIA TENER
    pedidoCliente[0]=dni;
    pedidoCliente[1]=1;
}

void procesarPedidos(ifstream &arch, char *** libros, int ** stock, 
        int * &pedidoCliente, char ** &pedidoLibro, bool * &pedidosAtendidos, 
        int &numLibrosPorPedido, int &capLibPorPed, int &capLibrPorCli, 
        int num){
    char codTemp[8], * cod=new char[8];
    int pos, * auxStock, cant;
    //000090,14268463   BZY0235    PQZ1316      IFL0150     JNC0786
    while(true){
        if(arch.get()=='\n') break;
        arch>>codTemp;
        pos=buscarLibro(codTemp, libros);
        if(capLibPorPed==numLibrosPorPedido) incrementarEspacios(pedidoLibro, 
                pedidosAtendidos, numLibrosPorPedido, capLibPorPed);
        if((capLibrPorCli-2)==(pedidoCliente[CANT]-1)) 
            incrementarEspacios(pedidoCliente, capLibrPorCli);
        if(pos!=NOTFOUND){
            cant=pedidoCliente[CANT];
            strcpy(cod, codTemp);
            auxStock=stock[pos];
            pedidoCliente[cant-1+2]=num;
            pedidoCliente[CANT]++;
            pedidoLibro[numLibrosPorPedido-1]=cod;
            if(auxStock[0]>0){
                auxStock[0]--;
                pedidosAtendidos[numLibrosPorPedido-1]=true;
            }
            else{
                auxStock[1]++;
                pedidoCliente[numLibrosPorPedido-1]=false;
            }
        }
    }
}

int buscarLibro(char * codTemp, char *** libros){
    char ** aux;
    for(int i=0; libros[i]; i++){
        aux=libros[i];
        if(strcmp(codTemp, aux[COD])==0) return i;
    }
    return NOTFOUND;
}

void incrementarEspacios(char ** &pedidoLibro, bool * &pedidosAtendidos, 
        int &numLibrosPorPedido, int &capLibPorPed){
    char ** auxPed;
    bool * auxAten;
    capLibPorPed+=INCREMENTO;
    if(numLibrosPorPedido==0){
        pedidoLibro=new char*[capLibPorPed]{};
        pedidosAtendidos=new bool[capLibPorPed]{};
        numLibrosPorPedido=1;
    }
    else{
        auxPed=new char*[capLibPorPed]{};
        auxAten=new bool[capLibPorPed]{};
        for(int i=0; i<numLibrosPorPedido; i++){
            auxPed[i]=pedidoLibro[i];
            auxAten[i]=pedidosAtendidos[i];
        }
        delete pedidoLibro;
        delete pedidosAtendidos;
        pedidoLibro=auxPed;
        pedidosAtendidos=auxAten;
    }
}

void incrementarEspacios(int * &pedidoCliente, int &capLibrPorCli){
    int * aux;
    capLibrPorCli+=INCREMENTO;
    aux=new int[capLibrPorCli]{};
    for(int i=0; i<pedidoCliente[CANT]-1+2; i++){
        aux[i]=pedidoCliente[i];
    }
    delete pedidoCliente;
    pedidoCliente=aux;
}

void pruebaDePedidos(const char *nombArch,int **pedidosClientes){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int *aux;
    for(int i=1;pedidosClientes[i];i++){
        aux=pedidosClientes[i];
        arch<<aux[0]<<setw(6)<<' '<<aux[1]<<endl;
        for(int j=2;aux[i];j++){
            arch<<aux[j]<<' ';
        }
        arch<<endl<<endl;
    }
}