import java.util.ArrayList;
import java.util.Scanner;

class PrimeraClase extends Pasajero{
	private ArrayList <String>articulosSolicitados;
	public PrimeraClase(){
		articulosSolicitados = new ArrayList <String>();
	}
	@Override
	public void Leer(Scanner arch){
		//P    33132202    DE-LA-CUBA/PAIRAZAMAN/ALBERTO    Pisco    2    Almohada    Gaseosa
		super.setDni(arch.nextInt());
		super.setNombre(arch.next());
		super.setDestino(arch.next());
		int iteraciones = arch.nextInt();
		for (int i=0;i<iteraciones;i++){
			String articulos=arch.next();
			articulosSolicitados.add(articulos);
			//System.out.printf("%s ", articulos);
		}
		//System.out.println("");
	}
	@Override
	public void Imprimir(){
		//P    33132202    DE-LA-CUBA/PAIRAZAMAN/ALBERTO    Pisco    2    Almohada    Gaseosa
		System.out.println("     Nombre: "+super.getNombre());
		System.out.println("     DNI: "+super.getDni());
		System.out.println("     Destino: "+super.getDestino());
		System.out.printf("     Ariticulos: ");
		for(int i=0;i<articulosSolicitados.size();i++){
			System.out.printf("%s ", articulosSolicitados.get(i));
		}
		System.out.println(" ");
		
	}
}