import java.util.Scanner;

class Paciente{
	private int dni;
	private String nombre;
	private String distrito;
	private double tiempoTotal;
	private double gastosTotales;
	private int cantidadDeConsultas;
	
	public Paciente(){
		tiempoTotal=0;
		gastosTotales=0;
		cantidadDeConsultas=0;
	}
	public Paciente(int dni,String nombre,String distrito){
		this.dni=dni;
		this.nombre=nombre;
		this.distrito=distrito;
		tiempoTotal=0;
		gastosTotales=0;
		cantidadDeConsultas=0;
	}
	
	public void setDni(int dni){
		this.dni=dni;
	}
	public int getDni(){
		return dni;
	}
	
	public void setNombre(String nombre){
		this.nombre=nombre;
	}
	public String getNombre(){
		return nombre;
	}
	
	public void setDistrito(String distrito){
		this.distrito=distrito;
	}
	public String getDistrito(){
		return distrito;
	}
	
	public void setTiempoTotal(double tiempoTotal){
		this.tiempoTotal=tiempoTotal;
	}
	public double getTiempoTotal(){
		return tiempoTotal;
	}
	
	public void setGastosTotales(double gastosTotales){
		this.gastosTotales=gastosTotales;
	}
	public double getGastosTotales(){
		return gastosTotales;
	}
	
	public void setCantidadDeConsultas(int cantidadDeConsultas){
		this.cantidadDeConsultas=cantidadDeConsultas;
	}
	public int getCantidadDeConsultas(){
		return cantidadDeConsultas;
	}
	
	public void leerPac(Scanner arch){
		dni=arch.nextInt();
		if(dni==0) return;
		nombre=arch.next();
		distrito=arch.next();
	}
	
	public void imprimirPac(){
		System.out.printf("%-13d %-40s %-40s %7.2f %10.2f %4d\n",dni,nombre,distrito,
			tiempoTotal,gastosTotales,cantidadDeConsultas);
	}
	
	public void actualizarPac(double tiempo,double tarifa){
		tiempoTotal+=tiempo;
		gastosTotales+=tiempo*tarifa;
		cantidadDeConsultas++;
	}
}