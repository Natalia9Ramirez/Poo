/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kruskal;

import java.util.Scanner;

/**
 *
 * @author Natalia.RamirezA
 */
public class Kruskal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int[][] matriz = new int[5][5];
        cargarMatriz(matriz);
        listarIndices(matriz);
    }

    static void cargarMatriz(int [][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz.length; j++) {
                if (i != j) {
                    matriz[i][j] = 3;
                    matriz[j][i] = matriz[i][j];
                } else {
                    matriz[i][j] = 0;
                }
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    static void listarIndices(int [][] matriz){
        for (int i = 0; i <matriz.length; i++) {
            
        }
    }
    
    class Nodo
    {
        private int peso;
        private Nodo sig;

        public Nodo() {
        }

        public Nodo(int peso) {
            this.peso = peso;
            this.sig = null;
        }
        

        /**
         * @return the peso
         */
        public int getPeso() {
            return peso;
        }

        /**
         * @param peso the peso to set
         */
        public void setPeso(int peso) {
            this.peso = peso;
        }

        /**
         * @return the sig
         */
        public Nodo getSig() {
            return sig;
        }

        /**
         * @param sig the sig to set
         */
        public void setSig(Nodo sig) {
            this.sig = sig;
        }
        

    }
}
