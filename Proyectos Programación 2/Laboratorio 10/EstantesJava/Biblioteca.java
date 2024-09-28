import java.util.Scanner;
import java.util.ArrayList;

class Biblioteca{
	private ArrayList <Estante> estantes;
	private ArrayList <Libro> libros;
	
	public Biblioteca(){
		estantes=new ArrayList<Estante>();
		libros=new ArrayList<Libro>();
	}
	
	public void cargaEstantes(Scanner arch){
		Estante auxEst;
		while(true){
			auxEst=new Estante();
			if(!auxEst.leeEst(arch)) break;
			estantes.add(auxEst);
		}
	}
	
	public void imprimeEstantes(){
		for(Estante aux:estantes){
			aux.imprimeEst();
		}
	}
	
	public void cargaLibros(Scanner arch){
		Libro auxLib;
		while(true){
			auxLib=new Libro();
			if(!auxLib.leeLib(arch)) break;
			libros.add(auxLib);
		}
	}
	
	public void imprimeLibros(){
		for(Libro aux:libros){
			aux.imprimeLib();
		}
	}
	
	public void posicionarLibros(){
		for(Estante auxEst: estantes){
			for(Libro auxLib: libros){
				if(!auxLib.IsColocado()){
					auxEst.agregarLibro(auxLib);
				}
			}
		}
	}
}