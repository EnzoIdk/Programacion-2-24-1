import java.util.Scanner;

class Enciclopedia extends Libro{
	private int anho;
	
	public Enciclopedia(){
	}
	
	public void SetAnho(int anho){
		this.anho=anho;
	}
	
	public int GetAnho(){
		return anho;
	}
	
	@Override
	public void leerLib(Scanner arch){
		anho=arch.nextInt();
		super.leerLib(arch);
	}
	
	@Override
	public void imprimeLib(){
		super.imprimeLib();
		System.out.printf("Anho: %d\n",anho);
		System.out.println();
	}
}