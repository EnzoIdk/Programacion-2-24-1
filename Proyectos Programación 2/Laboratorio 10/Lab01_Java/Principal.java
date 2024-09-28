import java.util.Scanner;
import java.util.ArrayList;

class Principal{
	public static void main (String [] arg){
		Biblioteca biblioteca=new Biblioteca();
		Scanner arch=new Scanner(System.in);
		biblioteca.leerLibros(arch);
		biblioteca.leerClientes(arch);
		biblioteca.cargarPedidos(arch);
		biblioteca.mostrarLibros();
		System.out.println();
		biblioteca.mostrarClientes();
	}
}