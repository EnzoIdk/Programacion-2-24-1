import java.util.ArrayList;
import java.util.Scanner;

class Omnibus{
	private String placa;
	private String chofer;
	private ArrayList <String> ruta;
	private int asientosPC;
	private int asientosCT;
	private ArrayList <Pasajero> pasajeros;
	
	public Omnibus(){
		ruta=new ArrayList <String> ();
		pasajeros=new ArrayList <Pasajero> ();
	}
	
	public void SetPlaca(String placa){
		this.placa=placa;
	}
	
	public String GetPlaca(){
		return placa;
	}
	
	public void SetChofer(String chofer){
		this.chofer=chofer;
	}
	
	public String GetChofer(){
		return chofer;
	}
	
	public void SetAsientosPC(int asientosPC){
		this.asientosPC=asientosPC;
	}
	
	public int GetAsientosPC(){
		return asientosPC;
	}
	
	public void SetAsientosCT(int asientosCT){
		this.asientosCT=asientosCT;
	}
	
	public int GetAsientosCT(){
		return asientosCT;
	}
	
	public void leerBus(Scanner arch){
		placa=arch.next();
		if(placa.compareTo("FIN")==0) return;
		chofer=arch.next();
		while(!arch.hasNextInt()){
			String lugar;
			lugar=arch.next();
			ruta.add(lugar);
		}
		asientosPC=arch.nextInt();
		asientosCT=arch.nextInt();
	}
	
	public Boolean agregarPasajero(Pasajero auxPas){
		String destino;
		char tipo;
		destino=auxPas.GetDestino();
		tipo=auxPas.GetTipo();
		if(tipo=='P' && asientosPC>0){
			if(dentroDeRuta(destino)){
				pasajeros.add(auxPas);
				asientosPC--;
				return true;
			}
		}
		else if(tipo=='T' && asientosCT>0){
			if(dentroDeRuta(destino)){
				pasajeros.add(auxPas);
				asientosCT--;
				return true;
			}
		}
		return false;
	}
	
	public Boolean dentroDeRuta(String destino){
		for(String aux: ruta){
			if(aux.compareTo(destino)==0) return true;
		}
		return false;
	}
	
	public void imprimirBus(){
		imprimeLinea(120,'=');
		System.out.println("Placa      Chofer                               PC  CT");
		imprimeLinea(120,'-');
		System.out.printf("%-10s %-40s %2d %4d\n",placa,chofer,asientosPC,asientosCT);
		System.out.printf("Ruta: ");
		for(int i=0;i<ruta.size();i++){
			System.out.printf("%-15s ",ruta.get(i));
		}
		System.out.printf("\nLista de pasajeros:\n");
		for(Pasajero aux: pasajeros){
			aux.imprime();
		}
	}
	
	public void imprimeLinea(int n,char simb){
		for(int i=0;i<n;i++) System.out.printf("%c",simb);
		System.out.println();
	}
}