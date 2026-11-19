//4] A class called Employee, which models an employee with an ID, name and salary, is designed as  shown in the following class diagram. The method raise Salary (percent) increases the salary by the given percentage. Develop the Employee class and suitable main method for demonstration. import java.util.Scanner;

import java.util.Scanner;
class Employee
{
    int id;
    String name;
    double salary;

    static Scanner sc = new Scanner(System.in);

    void getDetails()
    {
        System.out.print("Enter Employee ID: ");
        id = sc.nextInt();

        sc.nextLine();

        System.out.print("Enter Employee Name: ");
        name = sc.nextLine();

        System.out.print("Enter Salary: ");
        salary = sc.nextDouble();
    }

    void raiseSalary()
    {
        System.out.print("Enter salary raise percentage: ");
        double percent = sc.nextDouble();

        salary = salary + (salary * percent / 100);
    }

    void display()
    {
        System.out.println("\nEmployee Details:");
        System.out.println("Employee ID : " + id);
        System.out.println("Name        : " + name);
        System.out.println("Salary      : " + salary);
    }
}

public class Javaprog4
{
    public static void main(String[] args)
    {
        Employee emp = new Employee();

        emp.getDetails();

        System.out.println("\nBefore Salary Raise:");
        emp.display();

        emp.raiseSalary();

        System.out.println("\nAfter Salary Raise:");
        emp.display();
    }
}

/* 
Output:

Enter Employee ID: 101
Enter Employee Name: Raj
Enter Salary: 10000

Before Salary Raise:

Employee Details:
Employee ID : 101
Name        : Raj
Salary      : 10000.0

Enter salary raise percentage: 10

After Salary Raise:

Employee Details:
Employee ID : 101
Name        : Raj
Salary      : 11000.0
*/