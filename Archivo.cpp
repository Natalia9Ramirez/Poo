#include <iostream>
#include<string>
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
			string codigo="", producto="", cantidad="";
			for(int i=0; i<linea.length(); i++)
			{
				if(i<=2)
				{
					codigo=codigo + linea.at(i);
				}
				if(i>2 && i<=7)
				{
					producto= producto + linea.at(i);
				}
				if(i>7)
				{
					cantidad=cantidad + linea.at(i);
				}
			}
			salida= codigo + ","+producto+","+ cantidad;
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
