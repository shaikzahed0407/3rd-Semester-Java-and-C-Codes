//1] Develop a Java Program to add two matrices of suitable order N(The value of N should be read from command line arguments)

import java.util.Scanner;

class Javaprog1
{
    public static void main(String[] args) 
    {

        // Read matrix order N from command-line argument
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the value of N: ");
        int n = input.nextInt();

        int[][] A = new int[n][n];
        int[][] B = new int[n][n];
        int[][] C = new int[n][n];


        // Read first matrix
        System.out.println("Enter elements of Matrix A:");
        for (int i = 0; i< n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                A[i][j] = input.nextInt();
            }
        }

        // Read second matrix
        System.out.println("Enter elements of Matrix B:");
        for (int i = 0; i< n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                B[i][j] = input.nextInt();
            }
        }

        // Add matrices
        for (int i = 0; i< n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                C[i][j] = A[i][j] + B[i][j];
            }
        }

        // Display result
        System.out.println("Addition of Matrices A and B:");
        for (int i = 0; i< n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                System.out.print(C[i][j] + "\t");
            }
            System.out.println();
        }

        input.close();
    }
}

/*
Output:

Enter the value of N: 2
Enter elements of Matrix A:
1 	2
3 	4
Enter elements of Matrix B:
5 	6
7 	8
Addition of Matrices A and B:
6       8
10      12
*/