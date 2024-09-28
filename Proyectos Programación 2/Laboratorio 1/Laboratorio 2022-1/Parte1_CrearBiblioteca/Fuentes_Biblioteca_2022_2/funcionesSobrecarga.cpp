/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <fstream>
#include <cstring>

using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesSobrecarga.h"

/*
 }
 cuándo devolvía algo difernete?
 
 */

bool operator >>(ifstream &arch, struct StMedico &medico ){
    //506117   EDGAR_MUNOZ_VERGEL_Urologia   337.03
    char nombreEsp[300];
    arch>>medico.codigo;
    if (arch.eof()) false;
    arch>>nombreEsp;
    obtenerNOmbreEsp(nombreEsp, medico.nombre, medico.especialidad);
    arch>>medico.tarifaPoxConsulta;
    return true;
}
void obtenerNOmbreEsp(char cadena[], char nombre[], char especialidad[]){
    int tamanio=strlen(cadena); //cómo funcionaba strlen cuneta el cero?
    int i,j,k,h,y;
    for ( i = tamanio;i>0; i--) {
        if (cadena[i]=='_'){  
            break;
        }
    }
    for ( k = 0; k<i; k++) {
       nombre[k]=cadena[k];
    }
    nombre[k]=0;
    for ( h = i+1,y=0; h<=tamanio; h++,y++) {
       especialidad[y]=cadena[h];
    }
    especialidad[y]=0;
    
}
bool operator >>(ifstream &arch, struct StPaciente &p ){
    
//43704548   Vizcardo/Maribel   960851431
    
    arch>>p.dni;
    if (arch.eof()) false;
    arch>>ws; 
    arch.getline(p.nombre, 60, ' ');
    arch>>p.telefono;
//    p.citas{}; //cómo se inicializaba el arreglo de citas? 
    
    p.numeroDeCitas=0;
    p.totalGastado=0.0;
    return true;
}

int  operator >>(ifstream &arch, struct StCita &c ){
    int dnipaciente, dd, mm, aa;
    char k;
    arch>>dnipaciente;
    if (arch.eof()) return -1;
    arch>>c.codigoDelMedico;
    arch>>dd>>k>>mm>>k>>aa;
    c.fecha=obtenerFecha(dd, mm ,aa);
    c.tarifaPorConsulta=0.0;
//    cout<<dnipaciente<<endl;
    return dnipaciente;
}
int obtenerFecha(int dd, int mm , int aa){
    return aa*10000+mm*100+dd;
}
bool operator <=(struct StCita &cita, struct StMedico medico[]){
    int codigo=buscarCodMedico(cita.codigoDelMedico, medico);
    if (codigo != -1){
        cita.tarifaPorConsulta=medico[codigo].tarifaPoxConsulta;
        strcpy(cita.especialidad, medico[codigo].especialidad);
//        cout<< cita.especialidad<<endl;
        return true;
    }else{ 
        cout<<"no encontré al médico"<<endl;
        return false;
    }
}

int buscarCodMedico(int cod,  struct StMedico medico[]){
    for (int i = 0; medico[i].codigo!=0; i++) {
//         cout<<medico[i].codigo<<' '<<cod<<endl;
        if (medico[i].codigo==cod) return i;
    }
    return -1;
}

void operator+=(struct StPaciente &pac,struct StCita &cita){
    int numCita=pac.numeroDeCitas;
  
    pac.citas[numCita].codigoDelMedico= cita.codigoDelMedico;
    strcpy(pac.citas[numCita].especialidad,cita.especialidad);
    pac.citas[numCita].fecha= cita.fecha;
    pac.citas[numCita].tarifaPorConsulta=cita.tarifaPorConsulta;
//   cout<<pac.citas[numCita].tarifaPorConsulta<<cita.fecha<<endl;
//   cout<<cita.tarifaPorConsulta<<endl;
    pac.numeroDeCitas++;
//    cout<<pac.numeroDeCitas<<endl;
    
}
void operator ++ (struct StPaciente &pac){
    int i;
    double total=0;
    for ( i = 0; i < pac.numeroDeCitas; i++) {
        total+=pac.citas[i].tarifaPorConsulta;
    }
    pac.totalGastado=total;
//   cout<<pac.totalGastado<<' '<<pac.citas[i].tarifaPorConsulta<<endl;
}

void operator <<(ofstream &impre, struct  StPaciente &pac){
    impre<<setw(5)<<"DNI" <<setw(36)<<"NOMBRE"<<setw(25)<<"TELEFONO"<<endl;
    impre<<fixed;
    impre<<setprecision(2);
    impre<<pac.dni<<setw(39)<<pac.nombre<<setw(21)<<pac.telefono<<endl;
    impre<<"RELACIÓN DE CITAS: "<<endl;
    impre<<"No Fecha"<<setw(26)<<"CODIGO DEL MEDICO"<<setw(18)<<"ESPECIALIDAD"<<setw(16)<<"TARIFA"<<endl;
    for (int i = 0; i < pac.numeroDeCitas; i++) {
        impre<<setfill('0')<<setw(2)<<i+1<<')'<<setfill(' ');
        impresFecha(pac.citas[i].fecha, impre);
        impre<<setw(11)<<' '<<pac.citas[i].codigoDelMedico;
        impre<<setw(10)<<' '<<pac.citas[i].especialidad;
        impre<<setw(10)<<' '<<pac.citas[i].tarifaPorConsulta<<endl;
    }
    impre<<"MONTO TOTAL GASTADO: "<<pac.totalGastado<<endl;
    

}
void impresFecha(int fecha, ofstream &impre){
    int aa=fecha/10000;
    int dd=(fecha%10000)/100;
    int mm=((fecha%10000)%100);
    impre<<setfill('0')<<setw(2)<<dd<<'/'<<setfill('0')<<setw(2)<<mm<<'/'<<aa<<setfill(' ');
}