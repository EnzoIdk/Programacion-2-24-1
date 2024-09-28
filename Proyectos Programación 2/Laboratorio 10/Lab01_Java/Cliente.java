import java.util.Scanner;
import java.util.ArrayList;

class Cliente{
	private int dni;
	private String nombre;
	private ArrayList <LibroSolicitado> librosSolicitados;
	private int cantDeLibros;
	private double pagoTotal;
	
	public Cliente(){
		librosSolicitados=new ArrayList<LibroSolicitado> ();
		cantDeLibros=0;
		pagoTotal=0;
	}
	
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
	
	public void SetCantDeLibros(int cantDeLibros){
		this.cantDeLibros=cantDeLibros;
	}
	
	public int GetCantDeLibros(){
		return cantDeLibros;
	}
	
	public void SetPagoTotal(double pagoTotal){
		this.pagoTotal=pagoTotal;
	}
	
	public double GetPagoTotal(){
		return pagoTotal;
	}
	
	public Boolean leeCliente(Scanner arch){
		dni=arch.nextInt();
		if(dni==0) return false;
		nombre=arch.next();
		return true;
	}
	
	public void imprimeCliente(){
		System.out.printf("%d  %s\n",dni,nombre);
		System.out.println("Libros entregados:");
		System.out.println("    Pedido No.     Codigo     Precio");
		for(LibroSolicitado aux: librosSolicitados){
			if(aux.IsAtendido())
				System.out.printf("%15d     %s     %7.2f\n",aux.GetNumPed(),aux.GetCodigo(),aux.GetPrecio());
		}
		System.out.printf("Total a pagar: %10.2f\n",pagoTotal);
		System.out.println("Libros no entregados por falta de stock:");
		System.out.println("    Pedido No.     Codigo");
		for(LibroSolicitado aux: librosSolicitados){
			if(!aux.IsAtendido())
				System.out.printf("%15d     %s\n",aux.GetNumPed(),aux.GetCodigo());
		}
	}
	
	public void agregarLibro(LibroSolicitado lib){
		librosSolicitados.add(lib);
		cantDeLibros++;
		pagoTotal+=lib.GetPrecio();
	}
}