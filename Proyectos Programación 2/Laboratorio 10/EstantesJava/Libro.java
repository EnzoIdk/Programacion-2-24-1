import java.util.Scanner;

class Libro{
	private String codigo;
	private String titulo;
	private String autor;
	private int stock;
	private double precio;
	private int espacio;
	private Boolean colocado;
	
	public Libro(){
		espacio=0;
		colocado=false;
	}
	
	public void SetCodigo(String codigo){
		this.codigo=codigo;
	}
	
	public String GetCodigo(){
		return codigo;
	}
	
	public void SetTitulo(String titulo){
		this.titulo=titulo;
	}
	
	public String GetTitulo(){
		return titulo;
	}
	
	public void SetAutor(String autor){
		this.autor=autor;
	}
	
	public String GetAutor(){
		return autor;
	}
	
	public void SetStock(int stock){
		this.stock=stock;
	}
	
	public int GetStock(){
		return stock;
	}
	
	public void SetPrecio(double precio){
		this.precio=precio;
	}
	
	public double GetPrecio(){
		return precio;
	}
	
	public void SetEspacio(int espacio){
		this.espacio=espacio;
	}
	
	public int GetEspacio(){
		return espacio;
	}
	
	public void SetColocado(Boolean colocado){
		this.colocado=colocado;
	}
	
	public Boolean IsColocado(){
		return colocado;
	}
	
	public Boolean leeLib(Scanner arch){
		codigo=arch.next();
		if(codigo.compareTo("FIN")==0) return false;
		titulo=arch.next();
		autor=arch.next();
		stock=arch.nextInt();
		precio=arch.nextDouble();
		espacio=arch.nextInt();
		return true;
	}
	
	public void imprimeLib(){
		System.out.printf("%-10s %-60s %-40s %2d %7.2f %2d\n",
			codigo,titulo,autor,stock,precio,espacio);
	}
}