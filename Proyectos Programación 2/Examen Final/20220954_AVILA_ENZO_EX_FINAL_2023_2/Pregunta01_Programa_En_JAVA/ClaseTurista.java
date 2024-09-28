import java.util.Scanner;

class ClaseTurista extends Pasajero{
	private Boolean valija;
	private Boolean almuerzo;
	private double tarifaExtra;
	
	public ClaseTurista(){
		valija=false;
		almuerzo=false;
		tarifaExtra=0;
	}
	
	public void SetValija(Boolean valija){
		this.valija=valija;
	}
	
	public Boolean GetValija(){
		return valija;
	}
	
	public void SetAlmuerzo(Boolean almuerzo){
		this.almuerzo=almuerzo;
	}
	
	public Boolean GetAlmuerzo(){
		return almuerzo;
	}
	
	public void SetTarifaExtra(double tarifaExtra){
		this.tarifaExtra=tarifaExtra;
	}
	
	public double GetTarifaExtra(){
		return tarifaExtra;
	}
	
	@Override
	public void leeDatos(Scanner arch){
		super.leeDatos(arch);
		char llevaV,llevaA;
		llevaV=arch.next().charAt(0);
		llevaA=arch.next().charAt(0);
		if(llevaV=='S'){
			valija=true;
			tarifaExtra+=85.5;
		}
		if(llevaA=='S'){
			almuerzo=true;
			tarifaExtra+=55.9;
		}
	}
	
	@Override
	public char GetTipo(){
		return 'T';
	}
	
	@Override
	public void imprime(){
		super.imprime();
		System.out.printf("Valija: ");
		if(valija) System.out.printf("Si ");
		else System.out.printf("No ");
		System.out.printf("Almuerzo: ");
		if(almuerzo) System.out.printf("Si ");
		else System.out.printf("No ");
		System.out.printf("Tarifa extra: %.2f\n",tarifaExtra);
	}
}