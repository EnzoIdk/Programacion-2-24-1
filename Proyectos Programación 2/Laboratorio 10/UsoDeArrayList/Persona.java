import java.util.Scanner;

class Persona{
	private int dni;
	private char sexo;
	private String nombre;
	private double sueldo;
	//Constructores
	public Persona(){
		//no es necesario inicializarlos, es solo un ejemplo
		sueldo = 0.0;
	}
	//con parámetros
	public Persona(int dni,char sexo,String nombre,double sueldo){
		//todo es punteros
		this.dni=dni;
		this.sexo=sexo;
		this.nombre=nombre;
		this.sueldo=sueldo;
	}
	public Persona(Persona per){
		asignar(per);
	}
	//Destructor
	//NO SE IMPLEMENTAN (de eso se encarga el recolector de basura :v)
	//Métodos selectores
	public void SetDni(int d){
		dni=d;
	}
	public int GetDni(){
		return dni;
	}
	public void SetNombre(String nomb){
		nombre=nomb;
	}
	public String GetNombre(){
		return nombre;
	}
	public void SetSueldo(double s){
		sueldo=s;
	}
	public double GetSueldo(){
		return sueldo;
	}
	public void imprimirDatos(){
		System.out.printf("%10d %2c %-40s %10.2f\n",dni,sexo,nombre,sueldo);
	}
	public void asignar(Persona per){
		this.dni=per.dni;
		this.sexo=per.sexo;
		this.nombre=per.nombre;
		this.sueldo=per.sueldo;
	}
	public void leerDatos(Scanner arch){
		String aux;
		dni=arch.nextInt();
		aux=arch.next();
		sexo=aux.charAt(0);
		nombre=arch.next();
		sueldo=arch.nextDouble();
	}
}