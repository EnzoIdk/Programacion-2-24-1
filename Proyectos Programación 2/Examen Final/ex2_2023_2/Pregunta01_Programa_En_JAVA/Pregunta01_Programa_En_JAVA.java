import java.util.Scanner;

class Pregunta01_Programa_En_JAVA{
	public static void main(String []arg){
		Empresa reporte=new Empresa();
		Scanner arch = new  Scanner(System.in);
		 
		reporte.LeerCamiones(arch);
		reporte.SentarPasajeros(arch);
		reporte.Imprimir();
	}
}