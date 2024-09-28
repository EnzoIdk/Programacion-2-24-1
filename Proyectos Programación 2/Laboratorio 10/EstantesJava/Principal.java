import java.util.Scanner;
import java.util.ArrayList;

class Principal{
	
	public static void main (String [] arg){
		Biblioteca biblioteca=new Biblioteca();
		Scanner arch=new Scanner (System.in);
		biblioteca.cargaEstantes(arch);
		// biblioteca.imprimeEstantes();
		biblioteca.cargaLibros(arch);
		// System.out.println();
		// biblioteca.imprimeLibros();
		biblioteca.posicionarLibros();
		biblioteca.imprimeEstantes();
	}
}