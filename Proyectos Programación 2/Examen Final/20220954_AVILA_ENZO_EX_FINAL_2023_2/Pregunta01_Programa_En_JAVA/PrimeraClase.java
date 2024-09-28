import java.util.ArrayList;
import java.util.Scanner;

class PrimeraClase extends Pasajero{
	private ArrayList <String> articulosSolicitados;
	
	public PrimeraClase(){
		articulosSolicitados=new ArrayList<String>();
	}
	
	@Override
	public void leeDatos(Scanner arch){
		int numArticulos;
		String articulo;
		super.leeDatos(arch);
		numArticulos=arch.nextInt();
		for(int i=0;i<numArticulos;i++){
			articulo=arch.next();
			articulosSolicitados.add(articulo);
		}
	}
	
	@Override
	public char GetTipo(){
		return 'P';
	}
	
	@Override
	public void imprime(){
		super.imprime();
		System.out.printf("Articulos: ");
		for(String aux: articulosSolicitados){
			System.out.printf("%-10s ",aux);
		}
		System.out.println();
	}
}