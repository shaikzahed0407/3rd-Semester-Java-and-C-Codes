//2.  Write a C program to solve the Tower of Hanoi problem using recursion and display the sequence of moves.
#include<stdio.h>
void ToH(int n,char rod1,char rod2,char rod3)
{
    if(n==1)
    {
        printf("\nMove disk 1 from rod %c to rod %c",rod1,rod2);
        return;
    }
    ToH(n-1,rod1,rod3,rod2);
    printf("\nMove disk %d frrom rod %c to rod %c",n,rod1,rod2);
    ToH(n-1,rod3,rod2,rod1);
}
void main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    ToH(n,'A','B','C');
}
/*
Enter number of disks: 3
The sequence of moves involved in the Tower of Hanoi are:
Move disk 1 from rod A to rod B
Move disk 2 frrom rod A to rod C
Move disk 1 from rod B to rod C
Move disk 3 frrom rod A to rod B
Move disk 1 from rod C to rod A
Move disk 2 frrom rod C to rod B
Move disk 1 from rod A to rod B
*/