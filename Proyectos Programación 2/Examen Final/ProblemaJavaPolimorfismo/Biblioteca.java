import java.util.ArrayList;
import java.util.Scanner;

class Biblioteca{
	private ArrayList <Estante> estantes;
	
	public Biblioteca(){
		estantes=new ArrayList<Estante>();
	}
	
	public void carga(){
		Scanner arch=new Scanner(System.in);
		Estante auxEst;
		while(true){
			auxEst=new Estante();
			if(!auxEst.leerEst(arch)) break;
			estantes.add(auxEst);
		}
		llena(arch);
	}
	
	public void llena(Scanner arch){
		Libro aux;
		char tipo;
		while(arch.hasNext()){
			tipo=arch.next().charAt(0);
			if(tipo=='N')
				aux=new Novela();
			else if(tipo=='R')
				aux=new Revista();
			else
				aux=new Enciclopedia();
			aux.leerLib(arch);
			for(int i=0;i<estantes.size();i++){
				if(aux.GetPeso()<=estantes.get(i).GetDisponible()){
					estantes.get(i).colocar(aux);
					break;
				}
			}
		}
	}
	
	public void imprime(){
		for(Estante aux:estantes){
			aux.imprimeEst();
		}
	}
}