/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define MAXLINEA 131

void    lecturaProductos(const char *nombarch, char ***&productos,int *& stock, double *&precios){
    ifstream arch(nombarch, ios::in);
    if (not arch.is_open()){
        cout<<"error con el archivo: "<<nombarch<<endl;
        exit(1);
    }
    char cadena[500], **bufferProductos[200];
    int canProduc=0, nd[200], buffstock[200];
    double buffprecios[200];
    while(true){
        colocarProductos(arch,bufferProductos[canProduc]);
        if (arch.eof()) break;
        arch>>buffprecios[canProduc];
        arch.get();
        arch>>buffstock[canProduc];
        arch.get();
        canProduc++;
    }
    stock = new int[canProduc+1]{};
    precios = new double[canProduc+1]{};
    char ***auxiliar = new char **[canProduc+1]{};
    for (int i = 0; i < canProduc; i++) {
        stock[i]=buffstock[i];
        precios[i]=buffprecios[i];
        auxiliar[i]=bufferProductos[i];
    }
    productos=auxiliar;
}
void colocarProductos(ifstream &arch, char **&bufferProductos){
    bufferProductos=new char *[3]{};
    bufferProductos[0]=lecturaExacta(arch);
    if (arch.eof()) return;
    bufferProductos[1]=lecturaExacta(arch);
}
char *lecturaExacta(ifstream &arch){
    char *aux, cadena[500];
    arch.getline(cadena, 500, ',');
    aux = new char [strlen(cadena)+1]{};
    strcpy(aux,cadena);
    return aux;
    
}

void  pruebaDeLecturaDeProductos(const char *nombarch, char ***productos, int *stock, double *precios){
    ofstream arch(nombarch, ios::out);
    if (not arch.is_open()){//is open
        cout<<"error con la impresion de: "<<nombarch<<endl;
        exit(1);
    }
    arch<<setw((MAXLINEA+19)/2)<<"IMPRESION PRODUCTOS"<<endl;
       linea(MAXLINEA, arch,'=');
    arch<<fixed<<setprecision(2);
    arch<<setw(31)<<"Producto"<<setw(50)<<"Cantidad"<<setw(12)
                 <<"Precio"<<endl;
    for (int i = 0; productos[i]; i++) {
        imprimirProd(arch,productos[i], stock[i], precios[i]);
    }

}
void imprimirProd(ofstream &arch, char**productos, int stock, double precio ){
    arch<<setw(5)<<' '<<productos[0]<<setw(5)<<' '<<left<<productos[1]<<setw(60-strlen(productos[1]))<<' '<<
            stock<<setw(15)<<right<<precio<<endl;
}
void     lecturaDePedidos(const char *nombarch, int *&fechaPedidos, char ***&codigoPedidos, 
        int ***&dniCantPedidos){
    ifstream arch(nombarch, ios::in);
    if (not arch.is_open()){
        cout<<"error con el archivo: "<<nombarch<<endl;
        exit(1);
    }
   char **bufferCodPed[300];
   int **bufferDniCantPedidos[300];
   for (int i = 0; i < 300; i++) {
        bufferCodPed[i]=new char *[100];
        bufferDniCantPedidos[i]=new int *[100];
    }
   int bufferFechas[500]{}, nd[500]{},cant=0, dd,mm,aa, dni,fecha,idFecha,numero;
   char c, codigo[8];
   while(true){
       arch.getline(codigo, 8,',');
       if (arch.eof()) break;
       arch>>dni>>c>>numero>>c>>dd>>c>>mm>>c>>aa;
       fecha=aa*10000+mm*100+dd;
       arch.get();
        idFecha=buscarFecha(fecha, bufferFechas,cant);
       if (idFecha!=-1) colocarCodDni(bufferCodPed[idFecha],nd[idFecha], bufferDniCantPedidos[idFecha],codigo, dni,numero);
       else{
           bufferFechas[cant]=fecha;
           colocarCodDni(bufferCodPed[cant],nd[cant], bufferDniCantPedidos[cant],codigo, dni,numero);
           cant++;
       }
   }
   fechaPedidos=new int [cant+1]{};
   codigoPedidos=new char** [cant+1]{};
   dniCantPedidos=new int** [cant+1]{}; //no olvidar
   for (int i = 0; i < cant; i++) {
       fechaPedidos[i]=bufferFechas[i];
       gestarMemoriaCodPedidos(bufferCodPed[i],codigoPedidos[i], nd[i]);
       gestarMemoriaDniCant(bufferDniCantPedidos[i],dniCantPedidos[i], nd[i]);
   }
}
int buscarFecha(int fecha, int bufferFechas[], int cant){
    for (int i = 0;i<cant ; i++) {
        if (fecha==bufferFechas[i]) return i;
    }
    return -1;
}
void colocarCodDni( char **&bufferCodPed,int &datos,int **&bufferDniCantPedidos, char codigo[],
        int dni, int cant){
    bufferCodPed[datos]=new char[7 + 1]{};
    strcpy(bufferCodPed[datos],codigo);
    bufferDniCantPedidos[datos]=new int [2 + 1]{};
    colocarCantDni(bufferDniCantPedidos[datos], dni, cant);
    datos++;
}
void colocarCantDni(int *dniCantPedidos,int dni, int cant){
    dniCantPedidos[0]=dni;
    dniCantPedidos[1]=cant;
}
void gestarMemoriaCodPedidos(char **&bufferCodPed,char **&codigoPedidos, int nd){
    char **carry;
    if (nd>0){
         carry= new char*[nd +1]{};
         for (int i = 0; i < nd; i++) {
            carry[i]=bufferCodPed[i];
        }
          delete bufferCodPed;
        codigoPedidos = carry;
    }else{
        delete bufferCodPed;
        codigoPedidos=nullptr;
    }
}
void gestarMemoriaDniCant(int **&bufferDniCantPedidos,int **&dniCantPedidos, int nd){
    int **carry;//se necesita el &?
     if (nd>0){
        carry= new int*[nd +1]{};
        for (int i = 0; i < nd; i++) {
            carry[i]=bufferDniCantPedidos[i];
        }
        delete bufferDniCantPedidos;
        dniCantPedidos = carry;    
     }else{
         delete bufferDniCantPedidos;
         dniCantPedidos=nullptr;
     }
}
void pruebaDeLecturaDePedidos(const char *nombarch, int *fechaPedidos, char ***codigoPedidos, 
        int ***dniCantPedidos){
      ofstream arch(nombarch, ios::out);
    if (not arch.is_open()){//is open
        cout<<"error con la impresion de: "<<nombarch<<endl;
        exit(1);
    }
      arch<<setw((MAXLINEA+17)/2)<<"IMPRESION PEDIDOS"<<endl;
       linea(MAXLINEA, arch,'=');
    for (int i = 0; fechaPedidos[i]; i++) {
        arch<<"Fecha: "<<fechaPedidos[i]<<endl;
        arch<<setw(15)<<"DNI"<<setw(15)<<"Producto"<<setw(8)<<"Stock"<<endl;
        impresionCodDniCant(codigoPedidos[i],dniCantPedidos[i], arch);
    }
}
void impresionCodDniCant(char **codigoPedidos, int **dniCantPedidos, ofstream &arch){
    for (int i = 0; codigoPedidos[i]; i++) {
        impresionDniCant(dniCantPedidos[i], arch, i,codigoPedidos[i] );
    }
}
void  impresionDniCant(int *dniCantPedidos, ofstream &arch, int num, char *codigoPedidos){
    arch<<setw(2)<<num+1<<')'<<setw(5)<<' '<<dniCantPedidos[0]<<setw(5)<<' '<<
            codigoPedidos<<setw(10)<<dniCantPedidos[1]<<endl;
}
void reporteDeEnvioDePedidos(const char *nombarch, char ***productos,int *stock, double* precios,
        int* fechaPedidos,char ***codigoPedidos, int ***dniCantPedidos){
     ofstream arch(nombarch, ios::out);
    if (not arch.is_open()){//is open
        cout<<"error con la impresion de: "<<nombarch<<endl;
        exit(1);
    }
     double totalngresos, totalPerdida;
     arch<<fixed<<setprecision(2);
     arch<<setw((31+MAXLINEA)/2)<<"REPORTE DE ENTREGA DE PRODUCTOS"<<endl;
     for (int i = 0; fechaPedidos[i]; i++) {
          linea(MAXLINEA, arch,'=');
         impresionFecha(fechaPedidos[i], arch);
         totalngresos=totalPerdida=0;
          linea(MAXLINEA, arch,'=');
         arch<<setw(13)<<right<<"DNI"<<setw(31)<<"Producto"<<setw(55)<<"Cantidad"<<setw(12)
                 <<"Precio"<<setw(20)<<"Total de ingresos"<<endl;
         linea(MAXLINEA, arch,'-');
         impresionPedidos(arch,productos,codigoPedidos[i],dniCantPedidos[i],precios, stock,totalngresos, 
                 totalPerdida);
          linea(MAXLINEA, arch,'-');
         arch<<setw(39)<<left<<"Total ingresado: "<<setw(92)<<right<<totalngresos<<endl;
         arch<<setw(39)<<left<<"Total perdido por falta de stock: "<<setw(92)<<right<<totalPerdida<<endl;
    }
}
void impresionFecha(int pedidos, ofstream &arch){
    arch<<"Fecha: "<<(pedidos%10000)%100<<'/'<<(pedidos%10000)/100<<'/'<<pedidos/10000<<endl;
}
void impresionPedidos(ofstream &arch,char ***productos,char **codigoPedidos,int **dniCantPedidos,
        double *precios,int *stock,double &totalngresos,double&totalPerdida){
    int idPro;
    for (int r = 0;codigoPedidos[r] ; r++) {
        idPro=buscarProd(productos,codigoPedidos[r]);
        imprimiProdCant(dniCantPedidos[r], productos[idPro], arch,stock[idPro], precios[idPro], r,totalngresos,
                totalPerdida);
    }
}
int buscarProd(char ***productos, char *codigoPedidos){
    for (int i = 0; productos[i]; i++) {
        if (condicionPro(productos[i],codigoPedidos)) return i;
    }
    return -1;
}
int condicionPro(char **productos, char *codigoPedidos){
    if (strcmp(productos[0],codigoPedidos)==0){
        return 1;
    }else{
        return 0;
    }
}
void imprimiProdCant(int *dniCantPedidos,char **productos, ofstream &arch, int &stock, double precios, int cont,
        double &totalIngresos, double &totalPerdida){
    arch<<setw(2)<<right<<cont+1<<')'<<setw(12)<<right<<dniCantPedidos[0]<<setw(15)<<right
            <<productos[0]<<setw(5)<<' '<<productos[1]<<setw(60-strlen(productos[1]))<<' '<<dniCantPedidos[1]
            <<setw(15)<<right<<precios;
      if (stock>dniCantPedidos[1]){
        arch<<setw(20)<<right<<precios*dniCantPedidos[1]<<endl;
        stock-=dniCantPedidos[1];
        totalIngresos+=precios*dniCantPedidos[1];
    }else{
        arch<<setw(20)<<right<<"SIN STOCK"<<endl;
        totalPerdida+=precios*dniCantPedidos[1];
    }
}
void linea(int cant, ofstream &arch, char simb){
    for (int i = 0; i < cant; i++) {
        arch<<simb;
    }
    arch<<endl;
}
