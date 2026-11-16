//2.  Write a C program to solve the Tower of Hanoi problem using recursion and display the sequence of moves.

#include <stdio.h>
// Recursive function to solve Tower of Hanoi puzzle
void towerOfHanoi(int n, char source_rod, char dest_rod, char aux_rod) {
    // Base Case: If only 1 disk is left, move it directly
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source_rod, dest_rod);
        return;
    }

    // Step 1: Move top (n-1) disks from source to auxiliary rod
    towerOfHanoi(n - 1, source_rod, aux_rod, dest_rod);

    // Step 2: Move the remaining nth disk from source to destination rod
    printf("Move disk %d from rod %c to rod %c\n", n, source_rod, dest_rod);

    // Step 3: Move the (n-1) disks from auxiliary to destination rod
    towerOfHanoi(n - 1, aux_rod, dest_rod, source_rod);
}

int main() {
    int num_disks;

    printf("Enter the number of disks: ");
    if (scanf("%d", &num_disks) != 1 || num_disks <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printf("\nThe sequence of moves involved in the Tower of Hanoi are:\n");
    // A, B, and C are the names of the three rods
    towerOfHanoi(num_disks, 'A', 'C', 'B');

    return 0;
}


/*
OUTPUT:
Enter the number of disks: 3

The sequences of moves involved in the Tower of Hanoi are:
Move disk 1 from rod A to rod C
Move disk 2 from rod A to rod B
Move disk 1 from rod C to rod B
Move disk 3 from rod A to rod C
Move disk 1 from rod B to rod A
Move disk 2 from rod B to rod C
Move disk 1 from rod A to rod C
*/