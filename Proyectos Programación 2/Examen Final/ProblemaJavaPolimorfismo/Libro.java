import java.util.Scanner;
import java.util.ArrayList;

class Libro{
	private String nombre;
	private double peso;
	
	public void SetNombre(String nombre){
		this.nombre=nombre;
	}
	
	public String GetNombre(){
		return nombre;
	}
	
	public void SetPeso(double peso){
		this.peso=peso;
	}
	
	public double GetPeso(){
		return peso;
	}
	
	public void leerLib(Scanner arch){
		nombre=arch.next();
		peso=arch.nextDouble();
	}
	
	public void imprimeLib(){
		System.out.printf("Titulo: %s\n",nombre);
		System.out.printf("Peso: %.2f\n",peso);
	}
}