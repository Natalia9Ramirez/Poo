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
			string salida = "";
			string cc="", nombre="", cargo="";
			int anios[3];
			int sueldo[10];
			string datos[100];
			int band=0;int coma=0;
			
			for(int i=0; i<linea.length(); i++)
			{			
				if(linea.at(i)==','){
					coma++;
					for	(int j=0;j<i;j++)
					{	band= i;
						cc=cc+linea.at(j);
						for(int k=i; k<i;k++)
						{
						nombre=nombre+linea.at(k);	
						}
					}
				
				}
		}
			
			salida= cc+nombre;
			return (salida);
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
};

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
