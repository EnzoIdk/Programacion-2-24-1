
import java.util.ArrayList;
import java.util.Scanner;

class Omnibus{
	private String placa;
	private String chofer;
	private ArrayList <String>ruta;
	private int asientosPC;
	private int asientosCT;
	private ArrayList <Pasajero>pasajeros;
	
	public Omnibus(){
		ruta = new ArrayList<String>();
		pasajeros = new ArrayList<Pasajero>();
	}
	
	public void setPlaca(String placa){
		this.placa = placa;
	}
	public String getPlaca(){
		return placa;
	}
	public void setChofer(String chofer){
		this.chofer= chofer;
	}
	public String getChofer(){
		return chofer;
	}
	public void setAsientosPC(int asientosPC){
		this.asientosPC=asientosPC;
	}
	public int getAsientosPC(){
		return asientosPC;
	}
	public void setAsientosCT(int asientosCT){
		this.asientosCT=asientosCT;
	}
	public int getAsientosCT(){
		return asientosCT;
	}
	public Boolean EncontrarRuta(String buscar){
		for(int i=0;i<ruta.size();i++){
			if (ruta.get(i).compareTo(buscar)==0) return true;
		}
		return false;
	}
	public void AgregarPasajero(Pasajero cliente){
		pasajeros.add(cliente);
	}
	//P9A-528   CASTILLO/MEJIA/GUSTAVO-ALONSO   Lima   Ica   Arequipa   Moquegua   Tacna   3   10
	public void Leer(Scanner arch){
		placa = arch.next();
		chofer = arch.next();
		while(!arch.hasNextInt()){
			String ciudad;
			ciudad = arch.next();
			ruta.add(ciudad);
			
		} 
		
		asientosPC = arch.nextInt();
		asientosCT=arch.nextInt();
	}
	public void Imprimir(){
		System.out.println("Placa: "+placa);
		System.out.println("Chofer: "+chofer);
		System.out.printf("Ciudades: ");
		for(int i=0;i<ruta.size();i++){
			System.out.printf("%s ", ruta.get(i));
		}
		System.out.println(" ");
		System.out.println("----------------------------------------------");
		
		for(Pasajero x: pasajeros){
			x.Imprimir();
			System.out.println("******************************************");
		}
		System.out.println("----------------------------------------------");
	}
}