#include <stdio.h>
#define MAX 5

char q[MAX][20];
int front = -1, rear = -1;

void add()
{
    if (rear == MAX - 1)
        printf("Queue Full\n");
    else {
        if (front == -1) front = 0;
        printf("Enter job name: ");
        scanf("%s", q[++rear]);
        printf("Job added\n");
    }
}

void print()
{
    if (front == -1)
        printf("Queue Empty\n");
    else {
        printf("Printing: %s\n", q[front++]);
        if (front > rear) front = rear = -1;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue Empty\n");
    else {
        for (i = front; i <= rear; i++)
            printf("%s\n", q[i]);
    }
}

int main()
{
    int ch;
    do {
        printf("\n1.Add Job  2.Print Job  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: add(); break;
            case 2: print(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}
/*
1.Add Job  2.Print Job  3.Display  4.Exit
Enter choice: 1
Enter job name: Doc1
Job added

Enter choice: 1
Enter job name: Doc2
Job added

Enter choice: 3
Doc1
Doc2

Enter choice: 2
Printing: Doc1

Enter choice: 3
Doc2

Enter choice: 2
Printing: Doc2

Enter choice: 4
Exiting...
*/