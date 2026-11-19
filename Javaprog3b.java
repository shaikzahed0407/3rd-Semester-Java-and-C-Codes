//3(b) Write a Java program to iterate over Arrays using for-each loop to compute average of n natural numbers using Scanner class.

import java.util.Scanner;

public class Javaprog3b
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter n: ");
        int n = input.nextInt();

        int[] numbers = new int[n];
        System.out.println("Enter " + n + " natural numbers:");
        for (int i = 0; i< n; i++) 
        {
            numbers[i] = input.nextInt();
        }

        // Calculate sum using for-each loop
        int sum = 0;
        for (int num : numbers) 
        {
            sum += num;
        }

        // Calculate average
        double average = (double) sum / n;

        System.out.println("Sum = " + sum);
        System.out.println("Average = " + average);

        input.close();
    }
}
/* 
Output:

Enter n: 5
Enter 5 natural numbers:
10
20
30
40
50
Sum = 150
Average = 30.0
*/