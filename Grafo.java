/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Grafo;

import java.util.Scanner;

/**
 *
 * @author Natalia.RamirezA
 */
public class Grafo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int graph;
        
        graph = Grafo.readSize(sc);
        int[][] matriz;
        matriz = Grafo.loadAdjancency(graph, sc);
        Grafo.printMatriz(matriz, graph);
        Grafo.shortestPath(matriz, graph);
        Grafo.printMatriz(matriz, graph);
        Grafo.printPath(matriz, graph);

    }

    //Métodos
    static int readSize(Scanner sc) {
        int num = 0;
        boolean band;
        do {
            try {
                band = false;
                System.out.println("Digite el numero de grafos");
                num = sc.nextInt();

            } catch (Exception e) {
                System.out.println("Digite un numero entero por favor");
                band = true;
                sc.nextLine();
            }
        } while (band);
        return num;
    }

    static int[][] loadAdjancency(int graph, Scanner sc) {
        int matriz[][] = new int[graph][graph];
        boolean band;
        System.out.println("Ingrese la Matriz de Adyacencia, NOTA: en vez de infinito digite 1000");
        for (int i = 0; i < graph; i++) {
            for (int j = 0; j < graph; j++) {
                do {
                    try {
                        band = false;
                        if (i != j) {
                            System.out.print(" Posicion [" + (i + 1) + "][" + (j + 1) + "]= ");
                            matriz[i][j] = sc.nextInt();
                        } else {
                            matriz[i][j] = 0;
                        }
                    } catch (Exception e) {
                        System.out.println("Solo se aceptan numeros enteros");
                        band = true;
                        sc.nextLine();
                    }
                } while (band);

            }
        }
        return matriz;
    }

    static void shortestPath(int[][] matriz, int graph) {
        for (int k = 0; k < graph; k++) {
            for (int i = 0; i < graph; i++) {
                for (int j = 0; j < graph; j++) {
                    if ((matriz[i][k] + matriz[k][j]) < matriz[i][j]) {
                        matriz[i][j] = matriz[i][k] + matriz[k][j];
                    }
                }
            }
        }
    }

    static void printMatriz(int[][] matriz, int graph) {
        System.out.println("Impresión matriz");
        System.out.printf("  %d" , 0);
		for (int i = 1; i < matriz.length; i++) {
			System.out.printf(" %d" , i);
		}
		System.out.println();
        for (int i = 0; i < graph; i++) {
            System.out.printf("%d ",i);
            for (int j = 0; j < graph; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void printPath(int[][] matriz, int graph) {
        for (int i = 0; i < graph; i++) {
            for (int j = 0; j < graph; j++) {
                if (i != j) {

                    System.out.print("Camino mas corto: " + (i + 1) + " a " + (j + 1) + " = " + matriz[i][j]+ "\n");
                }
            }
        }
    }
}
