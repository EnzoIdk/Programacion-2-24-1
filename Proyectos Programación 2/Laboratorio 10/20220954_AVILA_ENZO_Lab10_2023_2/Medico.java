import java.util.Scanner;

class Medico{
	private int codigo;
	private String nombre;
	private String especialidad;
	private double tarifa;
	private double tiempoTotal;
	private double ingresosTotales;
	private int cantidadDeConsultas;
	
	//Constructor por defecto:
	public Medico(){
		tiempoTotal=0;
		ingresosTotales=0;
		cantidadDeConsultas=0;
	}
	//Constructor con parametros:
	public Medico(int codigo,String nombre,String especialidad,double tarifa){
		this.codigo=codigo;
		this.nombre=nombre;
		this.especialidad=especialidad;
		this.tarifa=tarifa;
		this.tiempoTotal=0;
		this.ingresosTotales=0;
		this.cantidadDeConsultas=0;
	}
	
	//Métodos selectores
	public void setCodigo(int codigo){
		this.codigo=codigo;
	}
	public int getCodigo(){
		return codigo;
	}
	
	public void setNombre(String nombre){
		this.nombre=nombre;
	}
	public String getNombre(){
		return nombre;
	}
	
	public void setEspecialidad(String especialidad){
		this.especialidad=especialidad;
	}
	public String getEspecialidad(){
		return especialidad;
	}
	
	public void setTarifa(double tarifa){
		this.tarifa=tarifa;
	}
	public double getTarifa(){
		return tarifa;
	}
	
	public void setTiempoTotal(double tiempoTotal){
		this.tiempoTotal=tiempoTotal;
	}
	public double getTiempoTotal(){
		return tiempoTotal;
	}
	
	public void setIngresosTotales(double ingresosTotales){
		this.ingresosTotales=ingresosTotales;
	}
	public double getIngresosTotales(){
		return ingresosTotales;
	}
	
	public void setCantidadDeConsultas(int cantidadDeConsultas){
		this.cantidadDeConsultas=cantidadDeConsultas;
	}
	public int getCantidadDeConsultas(){
		return cantidadDeConsultas;
	}
	
	//Método de lectura
	public void leerMed(Scanner arch){
		codigo=arch.nextInt();
		if(codigo==0) return;
		nombre=arch.next();
		especialidad=arch.next();
		tarifa=arch.nextDouble();
	}
	
	//Método de impresión
	public void imprimirMed(){
		System.out.printf("%-10d %-40s %-20s %7.2f %7.2f %10.2f %4d \n",codigo,nombre,
			especialidad,tarifa,tiempoTotal,ingresosTotales,cantidadDeConsultas);
	}
	
	public void actualizarMed(double tiempo){
		tiempoTotal+=tiempo;
		ingresosTotales+=tiempo*tarifa;
		cantidadDeConsultas++;
	}
}

