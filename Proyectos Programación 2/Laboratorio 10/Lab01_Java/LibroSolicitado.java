import java.util.Scanner;

class LibroSolicitado{
	private int numPed;
	private String codigo;
	private double precio;
	private Boolean atendido;
	
	public LibroSolicitado(){
		atendido=false;
		precio=0;
	}
	
	public LibroSolicitado(int numPed,String codigo){
		SetNumPed(numPed);
		SetCodigo(codigo);
		atendido=false;
	}
	
	public void SetNumPed(int numPed){
		this.numPed=numPed;
	}
	
	public int GetNumPed(){
		return numPed;
	}
	
	public void SetCodigo(String codigo){
		this.codigo=codigo;
	}
	
	public String GetCodigo(){
		return codigo;
	}
	
	public void SetPrecio(double precio){
		this.precio=precio;
	}
	
	public double GetPrecio(){
		return precio;
	}
	
	public void SetAtendido(Boolean atendido){
		this.atendido=atendido;
	}
	
	public Boolean IsAtendido(){
		return atendido;
	}
	
}