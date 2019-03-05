#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class reemplazar{
	private: 
		char caracter; 
		string texto;
	public: 
	reemplazar(char caracter, string texto){
		this->caracter= caracter;
		this->texto = texto;	
	}
	string generar(){
		
	  	for(int i=0;i<texto.length();i++){
	  		if(texto.at(i)==caracter){
	  			printf("%c fue encontrado en la posicion %d\n",caracter,i);
				texto.at(i)= '_';		
			}
		}
		printf("Nuevo texto: %s\n", texto.c_str());
		
	}

};
int main(){
	reemplazar r(' ',"descripcion del producto");
	r.generar();
	return 0;
}
