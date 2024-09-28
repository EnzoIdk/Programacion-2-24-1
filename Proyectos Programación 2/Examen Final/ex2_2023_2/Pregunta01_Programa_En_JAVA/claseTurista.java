
import java.util.Scanner;
class claseTurista extends Pasajero{
	private Boolean valija;
	private Boolean almuerzo;
	private double tarifaExtra;
	
	public Boolean getValija(){
		return valija;
	}
	public void setValija(Boolean valija){
		this.valija = valija;
	}
	public Boolean getAlmuerzo(){
		return almuerzo;
	}
	public void setAlmuerzo(Boolean almuerzo){
		this.almuerzo = almuerzo;
	}
	public double getTarifa(){
		return tarifaExtra;
	}
	public void setTarifa(double tarifaExtra){
		this.tarifaExtra = tarifaExtra;
	}
	public claseTurista(){
		valija=false;
		almuerzo=false;
	}
	@Override
	public void Leer(Scanner arch){
		//T    22899205    SALAZAR/CORRALES/LORENA-IRMA    Huanuco    S    N
		super.setDni(arch.nextInt());
		super.setNombre(arch.next());
		super.setDestino(arch.next());
		String Vaux = arch.next();
		String Caux= arch.next();
		if (Vaux.charAt(0)=='S'){
			valija=true;
		}
		if (Caux.charAt(0)=='S'){
			almuerzo=true;
		}
	}
	@Override
	public void Imprimir(){
		//P    33132202    DE-LA-CUBA/PAIRAZAMAN/ALBERTO    Pisco    2    Almohada    Gaseosa
		System.out.println("     Nombre: "+super.getNombre());
		System.out.println("     DNI: "+super.getDni());
		System.out.println("     Destino: "+super.getDestino());
		System.out.printf("     Valija: ");
		if (valija==true){
			System.out.printf("Sí");
		}else{
			System.out.printf("No");
		}
		System.out.println(" ");
		System.out.printf("     Almuerzo: ");
		if (almuerzo==true){
			System.out.printf("Sí");
		}else{
			System.out.printf("No");
		}
		System.out.println(" ");
		
	}
}