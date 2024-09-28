import java.util.Scanner;

class Principal{
	private static ClinicaLP1 clinica;
	public static void main(String [] arg){
		//ClinicaLP1 aux=new ClinicaLP1();
		//clinica=aux;
		clinica = new ClinicaLP1();
		Scanner arch=new Scanner (System.in);
		clinica.leerMedicos(arch);
		clinica.leerPacientes(arch);
		clinica.leerConsultas(arch);
		clinica.imprimirArrayMedicos();
		clinica.imprimirArrayPacientes();
	}
}