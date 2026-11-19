//5) Develop a JAVA program to create an abstract class Shape with abstract methods calculate Area () and calculate Perimeter (). Create subclasses Circle and Triangle that extend the Shape class and implement the respective methods to calculate the area and perimeter of each shape.

// Abstract class
abstract class Shape 
{
    abstract double calculateArea();
    abstract double calculatePerimeter();
}

// Circle class
class Circle extends Shape 
{
    double radius;

    Circle(double radius) 
    {
        this.radius = radius;
    }
    double calculateArea() 
    {
        return 3.14 * radius * radius;
    }
    double calculatePerimeter() 
    {
        return 2 * 3.14 * radius;
    }
}

// Triangle class
class Triangle extends Shape 
{
    double base, height;
    double side1, side2, side3;

    Triangle(double base, double height, double side1, double side2, double side3) 
    {
        this.base = base;
        this.height = height;
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }
    double calculateArea() 
    {
        return 0.5 * base * height;
    }
    double calculatePerimeter()
    {
        return side1 + side2 + side3;
    }
}

// Main class
public class Javaprog5 
{
    public static void main(String[] args) 
    {

        Circle c = new Circle(5);

        System.out.println("Circle");
        System.out.println("Area = " + c.calculateArea());
        System.out.println("Perimeter = " + c.calculatePerimeter());

        Triangle t = new Triangle(4, 3, 3, 4, 5);

        System.out.println("\nTriangle");
        System.out.println("Area = " + t.calculateArea());
        System.out.println("Perimeter = " + t.calculatePerimeter());
    }
}
/* 
Output:

Circle
Area = 78.5
Perimeter = 31.4

Triangle
Area = 6.0
Perimeter = 12.0
*/