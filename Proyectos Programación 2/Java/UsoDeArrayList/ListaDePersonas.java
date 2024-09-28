import java.util.Scanner;
import java.util.ArrayList;
//para el sort 
import java.util.Comparator;

class ListaDePersonas{
	private ArrayList <Persona> listaDePersonas;
	//constructor
	public ListaDePersonas(){
		listaDePersonas=new ArrayList<Persona>();
	}
	
	public void leerPersonas(){
		Scanner arch=new Scanner(System.in);
		Persona persona;
		while(arch.hasNext()){
			persona=new Persona();
			persona.leerDatos(arch);
			//como el push back
			listaDePersonas.add(persona);
		}
	}
	
	public void mostrarDatos(){
		for(Persona per: listaDePersonas){
			per.imprimirDatos();
		}
	}
	
	public void ordenar(){
		listaDePersonas.sort(Comparator.comparing(Persona::GetDni));
		//listaDePersonas.sort(Comparator.comparing(Persona::GetNombre));
	}
}