import java.util.Scanner;

abstract class Pasajero{
	private int dni;
	private String nombre;
	private String destino;
	
	public void SetDni(int dni){
		this.dni=dni;
	}
	
	public int GetDni(){
		return dni;
	}
	
	public void SetNombre(String nombre){
		this.nombre=nombre;
	}
	
	public String GetNombre(){
		return nombre;
	}
	
	public void SetDestino(String destino){
		this.destino=destino;
	}
	
	public String GetDestino(){
		return destino;
	}
	
	//como un método puro
	public abstract char GetTipo();
	
	public void leeDatos(Scanner arch){
		dni=arch.nextInt();
		nombre=arch.next();
		destino=arch.next();
	}
	
	public void imprime(){
		System.out.printf("%d  %-40s %-15s",dni,nombre,destino);
	}
}