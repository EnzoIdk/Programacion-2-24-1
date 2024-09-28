import java.util.Scanner;
import java.util.ArrayList;

class Biblioteca{
	private ArrayList <Libro> libros;
	private ArrayList <Cliente> clientes;
	
	public Biblioteca(){
		libros=new ArrayList<Libro>();
		clientes=new ArrayList<Cliente>();
	}
	
	public void leerLibros(Scanner arch){
		Libro auxLibro;
		while(true){
			auxLibro=new Libro();
			if(!auxLibro.leeLibro(arch)) break;
			libros.add(auxLibro);
		}
	}
	
	public void mostrarLibros(){
		System.out.println("LIBROS");
		for(Libro aux: libros){
			aux.imprimeLibro();
		}
	}
	
	public void leerClientes(Scanner arch){
		Cliente auxCliente;
		while(true){
			auxCliente=new Cliente();
			if(!auxCliente.leeCliente(arch)) break;
			clientes.add(auxCliente);
		}
	}
	
	public void mostrarClientes(){
		System.out.println("CLIENTES");
		for(Cliente aux: clientes){
			aux.imprimeCliente();
			for(int i=0;i<40;i++) System.out.print("-");
			System.out.println();
		}
	}
	
	public void cargarPedidos(Scanner arch){
		int numPed,dni,posCli,posLib;
		String codigo;
		LibroSolicitado lib;
		while(true){
			numPed=arch.nextInt();
			if(numPed==0) break;
			dni=arch.nextInt();
			while(!arch.hasNextInt()){
				codigo=arch.next();
				lib=new LibroSolicitado(numPed,codigo);
				posCli=buscarPosCli(dni);
				posLib=buscarPosLib(codigo);
				if(posLib!=-1) libros.get(posLib).agregarLibro(lib);
				if(posCli!=-1) clientes.get(posCli).agregarLibro(lib);
			}
		}
	}
	
	public int buscarPosCli(int dni){
		for(int i=0;i<clientes.size();i++){
			if(clientes.get(i).GetDni()==dni) return i;
		}
		return -1;
	}
	
	public int buscarPosLib(String codigo){
		for(int i=0;i<libros.size();i++){
			if((libros.get(i).GetCodigo()).compareTo(codigo)==0) return i;
		}
		return -1;
	}
}