#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class convertir{
   public:
      convertir(){
	  }	   
	  
	  void reemplazar(){
	  	int numero, resultado, modulo, aux = 0, aux1 = 0;
        int vector[50];
        int vecr[50];
        printf("Digite numero entero decimal a convertir: ");
        scanf("%d",&numero);
        //se divide el numero sobre la base(2)
        resultado = numero / 2;
                modulo = numero % 2;
                //se asigna el valor del mod en la primera posicion del vector[0]
                vector[aux] = modulo;
                aux = aux + 1;
				//comparacion del resultado con la base, y asignacion en el vector[+1]
                if (resultado < 2) {
                    vector[aux] = resultado;
                }
            //mientras que el resultado sea menor o igual a la base, se realiza el proceso de nuevo para obtener el valor requerido (1-0)
            while (2 <= resultado) {
                modulo = resultado % 2;
                resultado = resultado / 2;
                vector[aux] = modulo;
                aux = aux + 1;
                //el valor del modulo se va asignando en la sig posicion del vector
                if (resultado < 2) {
                    vector[aux] = resultado;

                }
            }
            //se crea el ciclo para recorrer los valores contenido en el vector del fin al inicio, para tomar los valores correspondientes a la conversión
            aux1 = aux;
            for (int i = 0; i <= aux; i++) {
                vecr[aux1] = vector[i];
                aux1 = aux1 - 1;
            }
            //impresion final 
            printf("El numero en base 2 es:");
            for (int i = 0; i <= aux; i++) {
                printf(" %d", vecr[i] , " ");
            }
            //se reestablecen los valores de la variables para hacer el proceso de la siguiente base(16)
           	resultado=0, modulo=0, aux = 0, aux1 = 0;
           	int vector1[50];
        	int vecr1[50];
           	
           	//se divide el numero sobre la base(8)
            resultado = numero / 8;
                modulo = numero % 8;
                //se asigna el valor del mod en la primera posicion del vector[0]
                vector1[aux] = modulo;
                aux = aux + 1;
				//comparacion del resultado con la base, y asignacion en el vector[+1]
                if (resultado < 8) {
                    vector1[aux] = resultado;
                }
            //mientras que el resultado sea menor o igual a la base, se realiza el proceso de nuevo para obtener el valor requerido (1-0)
            while (8 <= resultado) {
                modulo = resultado % 8;
                resultado = resultado / 8;
                vector1[aux] = modulo;
                aux = aux + 1;
                //el valor del modulo se va asignando en la sig posicion del vector
                if (resultado < 8) {
                    vector1[aux] = resultado;

                }
            }
            aux1 = aux;
            //se crea el ciclo para recorrer los valores contenido en el vector del fin al inicio, para tomar los valores correspondientes a la conversión
            for (int i = 0; i <= aux; i++) {
                vecr1[aux1] = vector1[i];
                aux1 = aux1 - 1;
            }
            //impresion final
            printf("\nEl numero en base 8 es:");
            for (int i = 0; i <= aux; i++) {
                printf(" %d", vecr1[i] , " ");
            }
            
			//se reestablecen los valores de las variables            
            resultado=0, modulo=0, aux = 0, aux1 = 0;
            int vector2[50];
        	int vecr2[50];
            resultado = numero / 16;
                modulo = numero % 16;
                //si el # ingresado es igual al mod y menor o igual a 9, se imprime el mod
                if (numero == modulo && numero <= 9) {
                    printf("\nEl numero hexadecimal es:%d" , modulo);
                }
                
				//si la dision del # entre la base es menor a 16 y el numero esta entre 9 y 15, se asigna el valor de la letra
                if (resultado < 16) {
                    if (numero > 9 && numero <= 15) {
                        printf("\nEl numero hexadecimal es: ");
                        if (modulo == 10) {
                            printf("A");
                        }
                        if (modulo == 11) {
                            printf("B");
                        }
                        if (modulo == 12) {
                            printf("C");
                        }
                        if (modulo == 13) {
                            printf("D");
                        }
                        if (modulo == 14) {
                           	printf("E");
                        }
                        if (modulo == 15) {
                            printf("F");
                        }
                    }
                    //se guarda en la primera posción del vector[0] el resultado, en la sig el mod
                    vector2[aux] = resultado;
                    aux = aux + 1;
                    vector2[aux] = modulo;
					
					//si el # esta entre 16 y 256, y el valor del mod es menor o igual a 9, se compara el valor para hacer la combinación de valor y letra
                    if (numero > 15 && numero <= 256) {
                        printf("\nEl numero hexadecimal es: ");
                        for (int i = 0; i <= aux; i++) {
                            if (vector2[i] <= 9) {
                                printf("%d", vector2[i]);
                            }
                            if (vector2[i] == 10) {
                               printf("A");
                            }
                            if (vector2[i] == 11) {
                                printf("B");
                            }
                            if (vector2[i] == 12) {
                                printf("C");
                            }
                            if (vector2[i] == 13) {
                                printf("D");
                            }
                            if (vector2[i] == 14) {
                               	printf("E");
                            }
                            if (vector2[i] == 15) {
                                printf("F");
                            }
                        }
                    }
                //si no la posición del vector toma el valor del mod
                } else {
                    vector2[aux] = modulo;
                    aux = aux + 1;
                    //mientras que el resultado sea menor o igual a la base, se realiza el proceso de nuevo para obtener el valor requerido
                    while (16 <= resultado) {
                        modulo = resultado % 16;
                        resultado = resultado / 16;
                        vector2[aux] = modulo;
                        aux = aux + 1;
                        //el valor del modulo se va asignando en la sig posicion del vector
                        if (resultado < 16) {
                            vector2[aux] = resultado;
                        }
                    }
                    aux1 = aux;
                    for (int i = 0; i <= aux; i++) {
                        vecr2[aux1] = vector2[i];
                        aux1 = aux1 - 1;
                    }
                    printf("\nEl numero en hexadecimal es :");
                    for (int i = 0; i <= aux; i++) {
                        if (vecr2[i] == 10) {
                           	printf("A");
                        }
                        if (vecr2[i] == 11) {
                           	printf("B");
                        }
                        if (vecr2[i] == 12) {
                        	printf("C");
                        }
                        if (vecr2[i] == 13) {
                            printf("D");
                        }
                        if (vecr2[i] == 14) {
                            printf("E");
                        }
                        if (vecr2[i] == 15) {
                            printf("F");
                        }
                        if (vecr2[i] >= 0 && vecr2[i] <= 9) {
                            printf("%d", vecr2[i]);
                        }
                    }
                }
            }
};

int main() {
	convertir c;
	c.reemplazar();
	getch();
}
