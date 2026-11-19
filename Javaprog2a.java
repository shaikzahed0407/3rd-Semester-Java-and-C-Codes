//2a) Program to demonstrate class mechanism and object creation
class Student 
{
    // Data members
    int rollNo;
    String name;
    double marks;

    // Member method
    void display() 
    {
        System.out.println("Roll Number: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("Marks: " + marks);
    }
}

public class Javaprog2a 
{
    public static void main(String[] args) 
    {

        // Creating an object of Student class
        Student s1 = new Student();

        // Accessing and assigning values to data members
        s1.rollNo = 101;
        s1.name = "Rahul";
        s1.marks = 85.5;

        // Calling member method using object
        s1.display();
    }
}
/* 
Output :

Roll Number: 101
Name: Rahul
Marks: 85.5 
*/