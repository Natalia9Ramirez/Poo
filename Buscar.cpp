#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class buscarCar{
   private:
   	  string datos;
   	  string car;   	  
   public:
      buscarCar(string datos, string car){
      	 this->car= car;
		 this->datos=datos;
	  }	   
	  
	  void buscar(){
	  	int encontrado=0;
	  	for(int i=0;i<datos.length();i++){
	  		for(int j=0; j<car.length();j++)
	  		{
	  		if(datos.at(i)==car.at(j)){
	  			//printf("%c fue encontrado en la posicion %d\n");
	  			encontrado = j;
				int k = i; 
	  			printf("posicion %d i %d \n",j,k,encontrado);
			}
		}
		}
	  }
}
;

int main() {
	buscarCar b("HostName:localhost","localhost");
	b.buscar();
	return 0;
}

