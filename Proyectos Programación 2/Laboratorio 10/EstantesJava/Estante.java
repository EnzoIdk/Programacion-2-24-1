import java.util.Scanner;
import java.util.ArrayList;

class Estante{
	private int id;
	private int capacidad;
	private int disponible;
	private ArrayList <Libro> librosEst;
	
	public Estante(){
		librosEst=new ArrayList <Libro> ();
		disponible=0;
	}
	
	public void SetId(int id){
		this.id=id;
	}
	
	public int GetId(){
		return id;
	}
	
	public void SetCapacidad(int capacidad){
		this.capacidad=capacidad;
	}
	
	public int GetCapacidad(){
		return capacidad;
	}
	
	public void SetDisponible(int disponible){
		this.disponible=disponible;
	}
	
	public int GetDisponible(){
		return disponible;
	}
	
	public Boolean leeEst(Scanner arch){
		id=arch.nextInt();
		if(id==0) return false;
		capacidad=arch.nextInt();
		SetDisponible(capacidad);
		return true;
	}
	
	public void imprimeEst(){
		imprimeLinea(120,'=');
		System.out.printf("%d %d %d\n",id,capacidad,disponible);
		imprimeLinea(120,'-');
		System.out.println("Libros asignados: ");
		imprimeLinea(120,'-');
		for(Libro auxLib: librosEst){
			auxLib.imprimeLib();
		}
	}
	
	public void agregarLibro(Libro libro){
		if(libro.GetEspacio()<=disponible){
			SetDisponible(disponible-libro.GetEspacio());
			libro.SetColocado(true);
			librosEst.add(libro);
		}
	}
	
	public void imprimeLinea(int n,char simb){
		for(int i=0;i<n;i++){
			System.out.printf("%c",simb);
		}
		System.out.println();
	}
}