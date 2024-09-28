import java.util.Scanner;

class Libro{
	private String codigo;
	private String titulo;
	private String autor;
	private int stock;
	private double precio;
	
	public Libro(){
		stock=0;
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
	
	public Boolean leeLibro(Scanner arch){
		codigo=arch.next();
		if(codigo.compareTo("0")==0) return false;
		titulo=arch.next();
		autor=arch.next();
		stock=arch.nextInt();
		precio=arch.nextDouble();
		return true;
	}
	
	public void imprimeLibro(){
		System.out.printf("%-10s %-60s %-40s %2d %7.2f\n",
			codigo,titulo,autor,stock,precio);
	}
	
	public void agregarLibro(LibroSolicitado lib){
		if(stock>0){
			lib.SetAtendido(true);
			lib.SetPrecio(precio);
			stock--;
		}
		else{
			lib.SetAtendido(false);
		}
	}
}