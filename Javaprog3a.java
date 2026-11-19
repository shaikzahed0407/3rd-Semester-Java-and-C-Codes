//3. (a) Write a Java program to illustrate Type Casting of the data type and type conversion.
public class Javaprog3a
{
    public static void main(String[] args) 
    {

        // Type Conversion (Widening)
        int a = 25;
        double b = a;   // int converted to double automatically

        System.out.println("Type Conversion:");
        System.out.println("Integer value: " + a);
        System.out.println("Converted double value: " + b);

        // Type Casting (Narrowing)
        double x = 25.75;
        int y = (int) x;   // double explicitly cast to int

        System.out.println("\nType Casting:");
        System.out.println("Double value: " + x);
        System.out.println("Casted integer value: " + y);
    }
}
/* 
Output:

Type Conversion:
Integer value: 25
Converted double value: 25.0

Type Casting:
Double value: 25.75
Casted integer value: 25
*/