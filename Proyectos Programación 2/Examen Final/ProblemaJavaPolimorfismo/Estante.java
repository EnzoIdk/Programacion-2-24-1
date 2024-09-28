import java.util.Scanner;
import java.util.ArrayList;

class Estante{
	private int codigo;
	private double capacidad;
	private double disponible;
	private ArrayList<Libro> libros;
	
	/*constructor*/
	public Estante(){
		codigo=0;
		capacidad=0;
		disponible=0;
		libros=new ArrayList<Libro>();
	}
	
	public void SetCodigo(int codigo){
		this.codigo=codigo;
	}
	
	public int GetCodigo(){
		return codigo;
	}
	
	public void SetCapacidad(double capacidad){
		this.capacidad=capacidad;
	}
	
	public double GetCapacidad(){
		return capacidad;
	}
	
	public void SetDisponible(double disponible){
		this.disponible=disponible;
	}
	
	public double GetDisponible(){
		return disponible;
	}
	
	public Boolean leerEst(Scanner arch){
		codigo=arch.nextInt();
		if(codigo==0) return false;
		capacidad=arch.nextDouble();
		SetDisponible(capacidad);
		return true;
	}
	
	public void colocar(Libro lib){
		libros.add(lib);
		disponible-=lib.GetPeso();
	}
	
	public void imprimeEst(){
		imprimeLinea(60,'=');
		System.out.printf("Codigo: %d\n",codigo);
		System.out.printf("Capacidad: %.2f\n",capacidad);
		System.out.printf("Disponible: %.2f\n",disponible);
		System.out.println("Listado de libros: ");
		imprimeLinea(60,'-');
		for(Libro aux:libros){
			aux.imprimeLib();
		}
	}
	
	public void imprimeLinea(int tam,char simb){
		for(int i=0;i<tam;i++){
		System.out.printf("%c",simb);
		}
		System.out.println();
	}
}