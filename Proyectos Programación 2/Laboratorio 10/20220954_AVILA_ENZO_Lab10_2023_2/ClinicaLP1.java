import java.util.Scanner;
import java.util.ArrayList;

class ClinicaLP1{
	//atributos privados
	private ArrayList <Medico> medicos;
	private ArrayList <Paciente> pacientes;
	
	//constructor
	public ClinicaLP1(){
		medicos=new ArrayList <Medico> ();
		pacientes=new ArrayList <Paciente> ();
	}
	
	public void leerMedicos(Scanner arch){
		Medico auxMed;
		while(true){
			auxMed=new Medico();
			auxMed.leerMed(arch);
			if(auxMed.getCodigo()==0) break;
			medicos.add(auxMed);
		}
	}
	
	public void leerPacientes(Scanner arch){
		Paciente auxPac;
		while(true){
			auxPac=new Paciente();
			auxPac.leerPac(arch);
			if(auxPac.getDni()==0) break;
			pacientes.add(auxPac);
		}
	}
	
	public void imprimirArrayMedicos(){
		System.out.println("Lista de medicos");
		for(Medico auxMed: medicos){
			auxMed.imprimirMed();
		}
		System.out.println();
	}
	
	public void imprimirArrayPacientes(){
		System.out.println("Lista de pacientes");
		for(Paciente auxPac: pacientes){
			auxPac.imprimirPac();
		}
		System.out.println();
	}
	
	public void leerConsultas(Scanner arch){
		int dni,codigo;
		double tiempo;
		while(arch.hasNext()){
			//leerDatos(arch,dni,codigo,tiempo);
			int hhI,mmI,ssI,hhF,mmF,ssF;
			dni=arch.nextInt();
			codigo=arch.nextInt();
			hhI=arch.nextInt();mmI=arch.nextInt();ssI=arch.nextInt();
			hhF=arch.nextInt();mmF=arch.nextInt();ssF=arch.nextInt();
			int tiempoIni=hhI*3600+mmI*60+ssI;
			int tiempoFin=hhF*3600+mmF*60+ssF;
			tiempo=(double)(tiempoFin-tiempoIni)/3600;
			int posMed,posPac;
			for(posMed=0;posMed<medicos.size();posMed++){
				if(medicos.get(posMed).getCodigo()==codigo) break;
			}
			for(posPac=0;posPac<pacientes.size();posPac++){
				if(pacientes.get(posPac).getDni()==dni) break;
			}
			medicos.get(posMed).actualizarMed(tiempo);
			pacientes.get(posPac).actualizarPac(tiempo,medicos.get(posMed).getTarifa());
		}
	}
}