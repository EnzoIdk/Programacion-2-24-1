
/*/ 
 * Projecto:  AsignacionDinamicaMemoriaExacta-2023-2
 * Nombre del Archivo:  AsignacionDinamicaMemoriaExacta.h
 * Autor: new Candy ****[sizeof(urMom)]{};
/*/

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

// Declaracion de Enumeracion
enum Prod {PROD_COD,PROD_NOMB};
enum Ped {PED_DNI,PED_CANT};

// Declaracion de Funciones
void lecturaDeProducto(const char *,char ***&,int *&,double *&);

char **obtenerBuff_Prod(ifstream &);

void pruebaDeLecturaDeProductos(const char *,char ***,int *,double *);

void lecturaDePedidos(const char *,int *&,char ***&,int ***&);

int *obtenerBuff_Ped(ifstream &);

void insertarDatosPorFecha(char **&,int **&,char *,int *);

void almacenarDatosComprimidos(char ***,int ***,int *,char ***&,int ***&,int *&,
                               int);

void comprimirPedidosDeFecha(char **&,int **&);

void pruebaDeLecturaDePedidos(const char *,int *,char ***,int ***);

void reporteDeEnvioDePedidos(const char *,char ***,int *,double *,int *,
                             char ***,int ***);

void procesarPedidos(ofstream &,char ***,int *,double *,char **,int **,double &,
                     double &);

void procesarResumenParcial(ofstream &,double,double);

void procesarResumenTotal(ofstream &,double,double);

ifstream abrirArchivo_IFS(const char *);

ofstream abrirArchivo_OFS(const char *);

char *obtenerCadenaExacta(ifstream &,char);

int compactarFecha(int,int,int);

void descompactarFecha(int,int &,int &,int &);

void imprimirFecha(ofstream &,int,int,int);

int obtenerPosFecha(int,int *,int);

int obtenerPosProd(char *,char ***);

void imprimirEncabezado(ofstream &,char,int);

void imprimirLinea(ofstream &,int,char);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */
