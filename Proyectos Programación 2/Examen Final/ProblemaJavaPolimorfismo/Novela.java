import java.util.Scanner;

class Novela extends Libro{
	private String autor;
	
	public Novela(){
	}
	
	public void SetAutor(String autor){
		this.autor=autor;
	}
	
	public String GetAutor(){
		return autor;
	}
	
	@Override
	public void leerLib(Scanner arch){
		autor=arch.next();
		//super es como hacer Libro::leerLib(arch);
		super.leerLib(arch);
	}
	
	@Override
	public void imprimeLib(){
		super.imprimeLib();
		System.out.printf("Autor: %s\n",autor);
		System.out.println();
	}
}