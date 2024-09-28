import java.util.Scanner;

class RedireccionamientoE_S_ConClases{
	public static void main(String []arg){
		Scanner arch=new Scanner(System.in);
		Persona persona=new Persona();
		while(arch.hasNext()){
			persona.leerDatos(arch);
			persona.imprimirDatos();
		}
	}
}