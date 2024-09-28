
import java.util.Scanner;

abstract class Pasajero{
	private int dni;
	private String nombre;
	private String destino;
	
	public Pasajero(){
		
	}
	public void setDni(int dni){
		this.dni=dni;
	}
	public int getDni(){
		return dni;
	}
	public void setNombre(String nombre){
		this.nombre= nombre;
	}
	public String getNombre(){
		return nombre;
	}	
	public void setDestino(String destino){
		this.destino= destino;
	}
	public String getDestino(){
		return destino;
	}
	public abstract  void Leer(Scanner arch);
	public abstract  void Imprimir();
}