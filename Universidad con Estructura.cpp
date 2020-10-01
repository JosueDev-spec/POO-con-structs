#include <iostream>
#include <cstdlib>
#include <fstream>
#include<sstream>
using namespace std;

//Este programa almacena los datos de n alumnos mediante una clase, y el uso de estructura.Examen

class Universidad
{

private:
	int cantidad;
	struct Estudiante
	{
		char nombre[32];
		char grupo[5];
		long int boleta;
		float cal1,cal2,cal3,prom;
	};
	Estudiante datos[30];
	
	
public:
	Universidad(int cant){
		cantidad=cant;
	}
	Universidad (){
		cout<<"\n\t\tUNIVERSIDAD DE LA  COMPUTACION Y LAS MATEMATICAS"<<endl;
		cout<<"Ingresa el numero de estudiante para guardar que va a registrar : ";
		cin>>cantidad;
	}
	void setCantidad(int _cantidad){
		cantidad=_cantidad;
	}
		
	int getCantidad(){
		return cantidad;
	}
	void Leer_datos ()
	{
		for(int i=0; i<cantidad; i++)
		{
			
			system("cls");
			cout<<"\n\tNombre del Estudiante: \n"<<endl;
			cin.ignore(100,'\n');
			cin.getline(datos[i].nombre,32);
			cout<<"\n\tGrupo: \n"<<endl;
			cin>>datos[i].grupo;
			cout<<"\n\tBoleta: \n"<<endl;
			cin>>datos[i].boleta;
			cout<<"\n\tPrimer Calificacion: \n"<<endl;
			cin>>datos[i].cal1;
			cout<<"\n\tSegunda Caliicacion: \n"<<endl;
			cin>>datos[i].cal2;
			cout<<"\n\tTercera Calificacion: \n"<<endl;
			cin>>datos[i].cal3;
		}
		return;
		
	}
	
	void Calcular_promedio (){
		for(int i=0; i<cantidad; i++)
		{
			
			datos[i].prom=(datos[i].cal1+datos[i].cal2+datos[i].cal3)/3;
		}
		return;
		
	}
	void Mostrar_datos(){
		stringstream s;
		for(int i=0; i<cantidad; i++)
		{
			
			s<<"Los datos del Alumno "<<i+1<<" son los siguentes:"<<endl;
				s<<"\t\tNombre: "<<datos[i].nombre<<endl;
				s<<"\t\tBoleta: "<<datos[i].boleta<<endl;
				s<<"\t\tGrupo: "<<datos[i].grupo<<endl;
				s<<"\t\tPrimera calificacion: "<<datos[i].cal1<<endl;
				s<<"\t\tSegunda calificacion: "<<datos[i].cal2<<endl;
				s<<"\t\tTercera calificacion: "<<datos[i].cal3<<endl;
				s<<"\t\tPromedio final: "<<datos[i].prom<<endl;
			
			if(datos[i].prom>=70)
			{
				s<<"\t\nNOTA: El Alumno "<<i+1<<" tiene un promedio aprobatorio, es un estudiantes inteligente\n\n"<<endl;
			}
			else
			{
				s<<"\t\nNOTA: El Alumno "<<i+1<<" tiene un promedio reprobatorio RECURSAMIENTO OBLIGATORIO\n\n"<<endl;
			}
		}
		cout<<s.str();
		
	}
	void Guardar_datos(){
		const int MAXCARACTERES=15;
		char nombrearchivo[MAXCARACTERES]="registro.dat";
		ofstream archivo_sale;
		archivo_sale.open(nombrearchivo);
		if(archivo_sale.fail())
		{
			
			cout<<"El archivo no se abrio exitosamente"<<endl;
			exit(1);
		}
		for (int i=0; i<cantidad; i++)
		{	archivo_sale<<"DATOS DEL ESTUDIANTE "<<i+1<<endl;
			archivo_sale<<"Nombre del Estudiante "<<datos[i].nombre<<endl;
			archivo_sale<<"Boleta : "<<datos[i].boleta<<endl;
			archivo_sale<<"Grupo :"<<datos[i].grupo<<endl;
			archivo_sale<<"Calificacion 1 : "<<datos[i].cal1<<endl;
			archivo_sale<<"Calificacion 2 : "<<datos[i].cal2<<endl;
			archivo_sale<<"Calificacion 3 : "<<datos[i].cal3<<endl;
			archivo_sale<<"Promedio Obtenido :"<<datos[i].prom<<endl;
		}
		//cierro la ediccion del archivo
		archivo_sale.close();
		//doy mensaje de confirmacion//
		cout<<"Los datos fueron guardados correctamente en [ "<<nombrearchivo<<" ]"<<endl;
		system("PAUSE");
		return;
	}
	void Cargar_datos (){
		const int MAXCARACTERES=15;
		char nombrearchivo[MAXCARACTERES]="registro.dat";//nombre del archivo que voy a guardar la info;
		ifstream archivo_entra;
		//abro para lectura con una variable de input
		archivo_entra.open(nombrearchivo);
		if (!archivo_entra)
		{
			
			cout<<"El archivo "<<nombrearchivo<<"no se abrio exitosamente \n verifique si existe"<<endl;
			system("PAUSE");
			exit(1);
		}
		cout<<"Los datos del registro de Estudiantes son: \n";
		for (int i=0; i<cantidad; i++)
		{	cout<<"------------------------------------------\n";
			cout<<endl<<"\t\t\t DATOS DEL ESTUDIANTE "<<i+1<<endl;
			archivo_entra>>datos[i].nombre;
			cout<<"Nombre del Estudiante : "<<datos[i].nombre<<endl;
			archivo_entra>>datos[i].boleta;
			cout<<"Boleta: "<<datos[i].boleta<<endl;
			archivo_entra>>datos[i].grupo;
			cout<<"Grupo: "<<datos[i].grupo<<endl;
			archivo_entra>>datos[i].cal1;
			cout<<"Calificacion 1: "<<datos[i].cal1<<endl;
			archivo_entra>>datos[i].cal2;
			cout<<"Califsicacion 2: "<<datos[i].cal2<<endl;
			archivo_entra>>datos[i].cal3;
			cout<<"Calificacion 3: "<<datos[i].cal3<<endl;
			archivo_entra>>datos[i].prom;
			cout<<"Promedio: "<<datos[i].prom<<endl;
			
		}
		system("PAUSE");
		return;
	}
	
	
	
};


int main ()
{
	
	Universidad Mi_registro;
	
	
	system ("CLS");
	
	if(Mi_registro.getCantidad()>=30)
	{
		cout<<" Maximo pueden ser 30 estudiantes asi que introduce un numero menor  a 30"<<endl;
	}
	else
	{
		
		
		Mi_registro.Leer_datos();
		Mi_registro.Calcular_promedio();
		Mi_registro.Guardar_datos();
		
		system("CLS");
		
		Mi_registro.Mostrar_datos();
		
		
		cout<<"\nLos datos cargados desde el archivo:"<<endl<<endl;
		
		Mi_registro.Cargar_datos();
		
		
	}
	
	
	system ("PAUSE");
	return 0;
}
