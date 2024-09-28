#include "FlotaGenerica.h"
enum pila{INICIO,PESO};
enum camion{DATO,SIGUIENTE};

void cargacamiones(void *&flota,const int numcamiones,const double pesomaximo,
    void*(*lee)(ifstream &),double(*calcula)(double,void*),const char*nomArch){
    ifstream arch(nomArch,ios::in);
    if(!arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    
    void **camiones=new void*[numcamiones]{}; //arreglo de void
    for (int i = 0; i < numcamiones; i++) {
        void**pila=new void*[2]{};//inicializo cada pila
        pila[INICIO]=nullptr;
        double *zero=new double{0};
        pila[PESO]=zero; 
        camiones[i]=pila;
    }

    void *dato;
    int i=0;//indica el numero del camion dentro del arreglo void*
    while(1){
        dato=lee(arch);
        if(arch.eof()) break;
        if(i<numcamiones) push(camiones,i,dato,calcula,pesomaximo,numcamiones);
    }
    flota=camiones;
}
    
void push(void **&camiones,int &i,void *dato,double(*calcula)(double,void*),
        const double pesomaximo,const int numcamiones){
    
    void *aux=(void**)camiones[i];
//    casteaPila(camiones,i);   
    void **pila=(void**)aux;
    
    void**nuevonodo=new void*[2]{};
    nuevonodo[DATO]=dato;
    nuevonodo[SIGUIENTE]=nullptr;
    
    if(pilavacia(pila)){
        pila[INICIO]=nuevonodo;
    }
    else{
        double peso=pesomaximo-calcula(pesomaximo,dato);
        double *pesoAnterior=(double *)pila[PESO];
        if(*pesoAnterior+peso<=pesomaximo){
            //agrego a mi pila
            agregarDatoPila(pila,nuevonodo);
        }
        else{
            i++;//lo guardo en la pila siguiente
            if(i==numcamiones) return;//ya llené todas mis pilas
            else{
                //agregoPila
                aux=casteaPila(camiones,i);
                pila=(void**)aux;
                agregarDatoPila(pila,nuevonodo);
            }
        }
    }
    double valor=pesomaximo-calcula(pesomaximo,dato);//valor del peso de dato
    double *pesoAnt=(double *)pila[PESO];
    double *pesoPtr=new double{valor+*pesoAnt};
    delete pesoAnt;
    pila[PESO]=pesoPtr;
}

bool pilavacia(void **pila){
    return pila[INICIO]==nullptr;    
}

void *casteaPila(void **&camiones,int i){
    void **pila=(void**)camiones[i];//accedo al arreglo
    //accedo a la pila para un camion en la posicion "i" 
    return pila;
}

void agregarDatoPila(void **&pila,void **&nuevonodo){
    void **aux=(void**)pila[INICIO];
    void **ant=nullptr;
    while(aux){
        ant=aux;
        aux=(void**)aux[SIGUIENTE];//busco hasta el último dato
    }
    
    if(ant==nullptr){
        pila[INICIO]=nuevonodo;
    }
    else{
        ant[SIGUIENTE]=nuevonodo;
    }   
}

void muestracamiones(void *flota,const int numcamiones,void(*imprime)(ofstream &,void*)
,const char*nomArch){
    ofstream arch(nomArch,ios::out);
    if(!arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    void**camiones=(void**)flota;
    void **pila;
    double *peso;
    for (int i = 0; i < numcamiones; i++) {
        pila=(void**)camiones[i];
        peso=(double *)pila[PESO];
        arch<<"Camión "<<i+1<<":    PESO: "<<*peso<<endl;
        imprime(arch,pila[INICIO]);
    }
}