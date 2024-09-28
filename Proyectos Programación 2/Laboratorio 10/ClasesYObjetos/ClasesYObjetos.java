class ClasesYObjetos{
	public static void main(String [] arg){
		Persona persona;
		persona = new Persona(111111,"Juan Perez",335.12);
		persona.imprimirDatos();
		Persona persona2;
		persona2=new Persona();
		persona2.SetDni(123014);
		persona2.SetNombre("Maria Quispe");
		persona2.SetSueldo(321.21);
		persona2.imprimirDatos();
		Persona persona3;
		persona3=new Persona(persona2);
		persona3.imprimirDatos();
	}
}