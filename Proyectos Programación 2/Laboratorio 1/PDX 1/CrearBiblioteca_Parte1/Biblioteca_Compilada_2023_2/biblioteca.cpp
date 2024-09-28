
/*/ 
 * Projecto:  Fuentes_Biblioteca_2023_2
 * Nombre del Archivo:  biblioteca.cpp
 * Autor: El Real Candy
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "biblioteca.h"
#define MAXLINEA 230

// Modulo de Sobrecarga de Operador '>>' [Lectura de 'Cliente']
bool operator >>(ifstream &archEntrada,struct Cliente &cli){
    // Proceso de Lectura de Datos
    archEntrada>>cli.dni;
    // Validacion de Fin de Archivo
    if(archEntrada.eof()){
        cli.dni = 0;                                                            // Indicador de Limite de Arreglo.
        return false;
    }
    archEntrada.get();                                                          // Descarte de 'Coma'.
    archEntrada.getline(cli.nombre,100,',');                                    // La Proxima 'Coma' se autodescarta aqui.
    archEntrada>>cli.telefono;                                                  // No es necesario descartar el 'Enter', pues el dato de nueva linea es entero.
    // Proceso de Inicializacion de Otros Atributos
    cli.cantidadProductosEntrgados = 0;
    cli.montoTotal = 0;
    return true;
}
// Modulo de Sobrecarga de Operador '>>' [Lectura de 'Producto']
bool operator >>(ifstream &archEntrada,struct Producto &prod){
    // Proceso de Lectura de Datos
    archEntrada.getline(prod.codigo,100,',');                                   // La Proxima 'Coma' se autodescarta aqui.
    // Validacion de Fin de Archivo
    if(archEntrada.eof()){
        strcpy(prod.codigo,"XXXXXXX");                                          // Indicador de Limite de Arreglo.
        return false;
    }
    archEntrada.getline(prod.descripcion,100,',');                              // La Proxima 'Coma' se autodescarta aqui.
    archEntrada>>prod.precio;
    archEntrada.get();                                                          // Descarte de 'Coma'.
    archEntrada>>prod.stock;                                                    // Si es necesario descartar el 'Enter', pues el dato de nueva linea es una cadena de caracteres.
    archEntrada.get();                                                          // Descarte de 'Enter'.
    // Proceso de Inicializacion de Otros Atributos
    prod.cantidadClientesServidos = 0;
    prod.cantidadClientesNoServidos = 0;
    return true;
}
// Modulo de Sobrecarga de Operador '>>' [Lectura de 'Pedido']
bool operator >>(ifstream &archEntrada,struct Pedido &ped){
    // Proceso de Lectura de Datos
    archEntrada.getline(ped.CodigoProducto,100,',');                            // La Proxima 'Coma' se autodescarta aqui.
    // Validacion de Fin de Archivo
    if(archEntrada.eof()){
        strcpy(ped.CodigoProducto,"XXXXXXX");
        return false;
    }
    archEntrada>>ped.dniCliente;                                                // Si es necesario descartar el 'Enter', pues el dato de nueva linea es una cadena de caracteres.
    archEntrada.get();                                                          // Descarte de 'Enter'
    return true;
}
// Modulo de Sobrecarga de Operador '+=' [Proceso: 'Clientes - Pedido']
void operator +=(struct Cliente *arrCli,struct Pedido ped){
    // Iterativa del Proceso de Busqueda y Actualizacion de Cliente Respecto al Pedido [i == Posicion de Producto] [p == Variable Auxiliar de SubPosiciones]
    for(int p,i = 0;arrCli[i].dni != 0;i++){
        if(arrCli[i].dni == ped.dniCliente){                                    // Validacion de Hallazgo de Cliente Respectivo al Pedido
            p = arrCli[i].cantidadProductosEntrgados++;                         // p == Posicion de Producto Entregado [Para insercion al final] | Incremento de Cantidad de Elementos 'Posterior' a Asignacion
            arrCli[i].productosEntregados[p].precio = ped.precioProducto;
            strcpy(arrCli[i].productosEntregados[p].codigo,ped.CodigoProducto);
            arrCli[i].montoTotal += ped.precioProducto;
            return;
        }
    }
    // Warning de Fallo de Busqueda
    cout<<"Warning: No se encontro el cliente respectivo a un pedido."<<endl;
    cout<<setw(38)<<"Procediendo con el programa.."<<endl;
}
// Modulo de Sobrecarga de Operador '+=' [Proceso: 'Productos - Pedido']
void operator +=(struct Producto *arrProd,struct Pedido &ped){
    // Iterativa del Proceso de Busqueda y Actualizacion de Cliente Respecto al Pedido [i == Posicion de Producto] [c == Variable Auxiliar de SubPosiciones]
    for(int c,i = 0;strcmp(arrProd[i].codigo,"XXXXXXX") != 0;i++){
        if(strcmp(arrProd[i].codigo,ped.CodigoProducto) == 0){                  // Validacion de Hallazgo de Producto Respectivo al Pedido
            if(arrProd[i].stock > 0){                                           // Validacion de Existencia de Stock
                c = arrProd[i].cantidadClientesServidos++;                      // c == Posicion de Cliente Servido [Para insercion al final] | Incremento de Cantidad de Elementos 'Posterior' a Asignacion
                arrProd[i].clientesServidos[c] = ped.dniCliente;
                arrProd[i].stock--;
                ped.precioProducto = arrProd[i].precio;
            }else{
                c = arrProd[i].cantidadClientesNoServidos++;                    // c == Posicion de Cliente No Servido [Para insercion al final] | Incremento de Cantidad de Elementos 'Posterior' a Asignacion
                arrProd[i].clientesNoServidos[c] = ped.dniCliente;
            }
            return;
        }
    }
    // Warning de Fallo de Busqueda
    cout<<"Warning: No se encontro el producto respectivo a un pedido."<<endl;
    cout<<setw(38)<<"Procediendo con el programa.."<<endl;
}
// Modulo de Sobrecarga de Operador '<<' [Impresion de 'Cliente']
bool operator <<(ofstream &archSalida,const struct Cliente &cli){
    // Validacion de Fin de Elementos
    if(cli.dni == 0) return false;
    // Proceso de Impresion de Atributos en Formato de Reporte
    archSalida<<setw(12)<<cli.dni<<setw(4)<<' ';
    archSalida<<left<<setw(50)<<cli.nombre<<right;
    archSalida<<setw(13)<<cli.telefono<<setw(11)<<cli.montoTotal<<setw(4)<<' ';
    archSalida<<"Productos Entregados:";
    // Validacion de Existencia de Productos Entregados
    if(cli.cantidadProductosEntrgados > 0){
        for(int i = 0,lim = cli.cantidadProductosEntrgados;i < lim;i++)
            archSalida<<setw(11)<<cli.productosEntregados[i].codigo;
    } else archSalida<<setw(37)<<"[ NO SE LE ENTREGARON PRODUCTOS ]";
    archSalida<<endl;
    return true;
}
// Modulo de Sobrecarga de Operador '<<' [Impresion de 'Producto']
bool operator <<(ofstream &archSalida,const struct Producto &prod){
    // Validacion de Fin de Elementos
    if(strcmp(prod.codigo,"XXXXXXX") == 0) return false;
    // Proceso de Impresion de Atributos en Formato de Reporte
    archSalida<<endl<<setw(11)<<prod.codigo<<setw(4)<<' ';
    archSalida<<left<<setw(60)<<prod.descripcion<<right;
    archSalida<<setw(10)<<prod.precio<<setw(10)<<prod.stock<<endl;
    archSalida<<setw(4)<<' '<<left<<setw(22)<<"Clientes atendidos: "<<right;
    // Validacion de Existencia de Clientes Servidos
    if(prod.cantidadClientesServidos > 0){
        for(int i = 0,lim = prod.cantidadClientesServidos;i < lim;i++)
            archSalida<<setw(10)<<prod.clientesServidos[i];
    } else archSalida<<setw(30)<<"[ NO SE ATENDIERON PEDIDOS ]";
    archSalida<<endl<<setw(4)<<' '<<"Clientes no atendidos:";
    // Validacion de Existencia de Clientes No Servidos
    if(prod.cantidadClientesNoServidos > 0){
        for(int i = 0,lim = prod.cantidadClientesNoServidos;i < lim;i++)
            archSalida<<setw(10)<<prod.clientesNoServidos[i];
    } else archSalida<<setw(33)<<"[ NO HAY CLIENTES SIN ATENDER ]";
    archSalida<<endl;
    return true;
}
