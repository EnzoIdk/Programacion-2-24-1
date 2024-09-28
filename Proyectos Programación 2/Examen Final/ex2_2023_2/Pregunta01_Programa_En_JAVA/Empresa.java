
import java.util.ArrayList;
import java.util.Scanner;

class Empresa{
	private ArrayList <Omnibus>flota;
	// private ArrayList <String>flota;
	
	 public Empresa(){
		 flota = new ArrayList<Omnibus>();
	 }
	 void LeerCamiones(Scanner arch){
	Omnibus Oaux;
		 while(!arch.hasNext("FIN")){
			 Oaux = new Omnibus();
			 Oaux.Leer(arch);
			 flota.add(Oaux);
			 
		 }
		 String fin = arch.next();
	 }
	 public void SentarPasajeros(Scanner arch){
		 //P    89429489    SERRANO/IPARRAGUIRRE/VIRGINIA    Cimbote    4    Almohada    Antifaz    Whisky    Vino
		
		 while(arch.hasNext()){
			String aux = arch.next();
			char tipo = aux.charAt(0);//tomo el primer char
			Pasajero Paux;
			if (tipo=='P'){
				Paux = new PrimeraClase();
			}else{
				Paux = new claseTurista();
			}
			Paux.Leer(arch);
			int idCamion=BuscarCamion(Paux.getDestino(), flota, tipo);
			//System.out.println("ID: "+idCamion);
			if (tipo=='P' && idCamion!=-1) {
				flota.get(idCamion).AgregarPasajero(Paux);
				flota.get(idCamion).setAsientosPC(flota.get(idCamion).getAsientosPC()-1);
			}else if (tipo=='T' && idCamion!=-1){
				flota.get(idCamion).AgregarPasajero(Paux);
				flota.get(idCamion).setAsientosCT(flota.get(idCamion).getAsientosCT()-1);
			}
		 }
	 }
	 public int BuscarCamion(String destino, ArrayList<Omnibus>flota, char tipo){
		 int i=0;
		 for(Omnibus x:flota){
			 if (x.EncontrarRuta(destino) ) {
				 if (tipo=='P' &&  x.getAsientosPC()-1>0 ){
					 return i;
				 }else if (tipo=='T' && x.getAsientosCT()-1>0){
					 return i;
				 }
			 }
			 i++;
		 }
		 return -1;
	 }
	 public void Imprimir(){
		 for(Omnibus x:flota){
			 x.Imprimir();
		 }
	 }
}