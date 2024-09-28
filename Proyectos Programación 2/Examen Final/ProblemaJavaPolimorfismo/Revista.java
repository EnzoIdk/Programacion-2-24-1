import java.util.Scanner;

class Revista extends Libro{
	private int anho;
	private int numero;
	
	public Revista(){
	}
	
	public void SetAnho(int anho){
		this.anho=anho;
	}
	
	public int GetAnho(){
		return anho;
	}
	
	public void SetNumero(int numero){
		this.numero=numero;
	}
	
	public int GetNumero(){
		return numero;
	}
	
	@Override
	public void leerLib(Scanner arch){
		anho=arch.nextInt();
		numero=arch.nextInt();
		super.leerLib(arch);
	}
	
	@Override
	public void imprimeLib(){
		super.imprimeLib();
		System.out.printf("Anho: %d\n",anho);
		System.out.printf("Numero: %d\n",numero);
		System.out.println();
	}
}