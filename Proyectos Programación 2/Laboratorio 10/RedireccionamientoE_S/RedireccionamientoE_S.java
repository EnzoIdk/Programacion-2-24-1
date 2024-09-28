import java.util.Scanner;

class RedireccionamientoE_S{
	public static void main(String [] arg){
		Scanner arch=new Scanner(System.in);
		int dni;
		String nombre,aux;
		double sueldo;
		char sexo;
		while(arch.hasNext()){
			dni=arch.nextInt();
			//lee una palabra
			aux=arch.next();
			//te saca la primera letra
			sexo=aux.charAt(0);
			nombre=arch.next();
			sueldo=arch.nextDouble();
			System.out.printf("%10d %c %-20s %10.2f\n",dni,sexo,nombre,sueldo);
		}
	}
}