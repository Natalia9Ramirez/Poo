#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class extraer{
   private:
   	  string linea;	  
   public:
      extraer(string linea){
      	 this->linea=linea;
	  }	   
	  string generar()
		{
			string dato="", salida="", cc="", nombre="", cargo="",sueldo="",anios="";
			int coma=0,sueldoNeto=0, descuento=0, auxilio=0;
			
			for(int i=0; i<linea.length(); i++)
			{			
				if(linea.at(i)==','){
					coma++;					
					switch(coma)
					{
						case 1:
							cc=dato;
							printf("Documento: %s\n",dato.c_str());
							dato="";
							i++;
							break;
							
						case 2:
							nombre=dato;
							printf("Nombre: %s\n",nombre.c_str());
							dato="";
							i++;
							break;
							
						case 3:
							cargo=dato;
							printf("Cargo: %s\n",cargo.c_str());
							dato="";
							i++;
							break;
							
						case 4:
							sueldo=dato;
							printf("Sueldo base: %s\n",sueldo.c_str());
							descuento = (toInt(sueldo)*8)/100;
							sueldoNeto = toInt(sueldo) - descuento;
							printf("Valor descuento: %d\n", descuento);
							printf("Sueldo neto: %d\n", sueldoNeto);
							dato="";
							i++;
							break;
							
						case 5:
							anios=dato;
							printf("Antiguedad: %s\n",anios.c_str());
							if(toInt(anios)>=3)
							{
								auxilio = (toInt(sueldo)*8)/100;
								sueldoNeto = toInt(sueldo) + auxilio;
								printf("Auxilio por antiguedad: %d\n", auxilio);
								printf("Sueldo neto: %d\n", sueldoNeto);
							}
							else
							{
								printf("No aplica auxilio por antiguedad\n");
							}
							dato="";
							i++;
							break;
						break;					
							
					}		
				}else
				{
					dato=dato+linea.at(i);
				}
				
				
		}
		salida=cc+";"+cargo+";"+ toString(descuento)+";"+toString(auxilio)+";"+toString(sueldoNeto);
		return(salida);
		}
	
		int toInt(string valor)
		{
			int i;
			std :: stringstream ss;
			std :: string s = valor;
			ss << s;
			ss >> i;
			return (i);
		}
		
		string toString(int valor)
		{
			string s1;
			ostringstream ss;
			ss << valor;
			s1=ss.str();
			return (s1);
		}
};

class procesar 
{
	private: 
	public:
		procesar(){}
		void generarSalida(){
		ofstream destino;
		destino.open ("c:\\Prueba\\salida.csv");
		
		ifstream origen("c:\\Prueba\\linea.txt");
		string linea;
		string salida=""; 
		
		destino<<"DOCUMENTO;CARGO;DESCUENTO SALUD Y PENSION;AUXILIO ANTIGUEDAD;SUELDO NETO\n";
		
		while (getline(origen, linea))
		{
		   extraer e(linea);
		   salida=e.generar();
		   destino <<salida+"\n";	
			
		}
		origen.close();
		destino.close(); 
		printf("Proceso finalizado!");
  }
};

int main(int argc, char** argv) {
	procesar p; 
	p.generarSalida(); 
	}
