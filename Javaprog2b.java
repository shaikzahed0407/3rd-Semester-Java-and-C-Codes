//2b) Write a Java Program to Implement Shift Operators
public class Javaprog2b
 {
    public static void main(String[] args) 
    {
        int a = 8;
        int b = -8;
        int n = 2;

        System.out.println("Original value a = " + a);

        // Left Shift
        System.out.println("a << 2  = " + (a << n));

        // Right Shift
        System.out.println("a >> 2  = " + (a >> n));

        // Unsigned Right Shift
        System.out.println("a >>> 2 = " + (a >>> n));

        System.out.println("\nOriginal value b = " + b);

        // Right Shift for negative number
        System.out.println("b >> 2  = " + (b >> n));

        // Unsigned Right Shift for negative number
        System.out.println("b >>> 2 = " + (b >>> n));
    }
}
/*  
Output : 

Original value a = 8
a << 2  = 32
a >> 2  = 2
a >>> 2 = 2

Original value b = -8
b >> 2  = -2
b >>> 2 = 1073741822
*/