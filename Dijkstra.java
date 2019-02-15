/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dijkstra;

import java.util.Scanner;

/**
 *
 * @author Natalia.RamirezA
 */
public class Dijkstra {

    /**
     * @param args the command line arguments
     */
    public int[] distancia = new int[10];
    public int[][] peso = new int[10][10];

    public void calc(int n, int s) {
        int flag[] = new int[n + 1];
        int i, minpos = 1, k, c, minimum;

        for (i = 1; i <= n; i++) {
            flag[i] = 0;
            this.distancia[i] = this.peso[s][i];
        }
        c = 2;
        while (c <= n) {
            minimum = 99;
            for (k = 1; k <= n; k++) {
                if (this.distancia[k] < minimum && flag[k] != 1) {
                    minimum = this.distancia[i];
                    minpos = k;
                }
            }
            flag[minpos] = 1;
            c++;
            for (k = 1; k <= n; k++) {
                if (this.distancia[minpos] + this.peso[minpos][k] < this.distancia[k] && flag[k] != 1) {
                    this.distancia[k] = this.distancia[minpos] + this.peso[minpos][k];
                }
            }

        }
    }

    public static void main(String[] args) {
        int nodes, source, i, j;
        Scanner in = new Scanner(System.in);
        System.out.println("Número de nodos\n");
        nodes = in.nextInt();
        Dijkstra d = new Dijkstra();
        System.out.println("Peso de los nodos de la matriz: \n");
        for (i = 1; i <= nodes; i++) {
            for (j = 1; j <= nodes; j++) {
                d.peso[i][j] = in.nextInt();
                if (d.peso[i][j] == 0) {
                    d.peso[i][j] = 999;
                }
            }
        }
        System.out.println("Vértice origen:\n");
        source = in.nextInt();

        d.calc(nodes, source);
        System.out.println("Camino mas corto desde:\t" + source + "\t al vertice : \n");
        for (i = 1; i <= nodes; i++) {
            if (i != source) {
                System.out.println("origen:" + source + "\t destino:" + i + "\t peso minimo:" + d.distancia[i] + "\t");
            }
        }

    }

}
