import java.util.ArrayList;
import java.util.Scanner;

class Empresa{
	private static ArrayList <Omnibus> flota;
	
	// public Empresa(){
		// flota = new ArrayList <Omnibus> ();
	// }
	
	// public void cargarOmnibuses(Scanner arch){
		// class Omnibus auxBus;
		// while(true){
			// auxBus=new Omnibus();
			// auxBus.leerBus(arch);
			// if((auxBus.GetPlaca()).compareTo("FIN")==0) break;
			// flota.add(auxBus);
		// }
	// }
	
	public static void main(String [] arg){
		flota=new ArrayList <Omnibus> ();
		Scanner arch= new Scanner(System.in);
		// cargarOmnibuses(arch);
		Omnibus auxBus;
		while(true){
			auxBus=new Omnibus();
			auxBus.leerBus(arch);
			if((auxBus.GetPlaca()).compareTo("FIN")==0) break;
			flota.add(auxBus);
		}
		char tipo;
		Pasajero auxPasajero;
		while(arch.hasNext()){
			tipo=arch.next().charAt(0);
			if(tipo=='P') auxPasajero=new PrimeraClase();
			else auxPasajero=new ClaseTurista();
			auxPasajero.leeDatos(arch);
			for(Omnibus bus: flota){
				if(bus.agregarPasajero(auxPasajero)) break;
			}
		}
		System.out.println("EMPRESA DE TRANSPORTE TURISTICO");
		for(Omnibus bus: flota){
			bus.imprimirBus();
		}
	}
}