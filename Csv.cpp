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
			string dato="";
			string salida = "";
			string cc="", nombre="", cargo="";
			int band=0; int coma=0;
			
			for(int i=0; i<linea.length(); i++)
			{			
				if(linea.at(i)==','){
					coma++;
					
					switch(coma)
					{
						case 1:
							cc=dato;
							printf("%s\n", dato.c_str());
							dato="";
							i++;
							break;
						case 2:
							nombre=dato;
							printf("%s\n",nombre.c_str());
						break;						
							
					}
					
					/*for	(int j=0;j<i;j++)
					{	band= i;
						cc=cc+linea.at(j);
					}*/
				
				}else
				{
					dato=dato+linea.at(i);
				}
		}
			
			/*salida= cc;
			return (salida);*/
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
