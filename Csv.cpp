#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

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
			string salida = "";
			string anios="", sueldo="";
			for(int i=0; i<linea.length(); i++)
			{
				if(i<42 && i>33){
					sueldo= sueldo + linea.at(i);
				}
				if(i<45 && i>42)
				{
					
					anios=anios + linea.at(i);
					printf("%s",anios.c_str());
				}
			}
			salida= sueldo+"anios:"+anios;
			return (salida);
		}  
}
;

class procesar 
{
	private: 
	public:
		procesar(){}
		void procesarLinea()
		{
			string linea ="";
			ifstream archivo("C:\\Prueba/linea.txt");
			string salida ="";
			while(getline(archivo, linea)){
				extraer e(linea);
				salida = e.generar();
				printf("%s \n", salida.c_str());  
			}	
		}
};

int main(int argc, char** argv) {
	procesar p; 
	p.procesarLinea(); 
	}
