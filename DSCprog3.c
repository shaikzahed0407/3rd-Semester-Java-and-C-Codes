//3. Write a C program to implement a queue using arrays and simulate a printer spooling system
#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];
int front = -1;
int rear = -1;

// Add a print job to the queue
void enqueue()
{
    char job[50];

    if (rear == MAX - 1)
    {
        printf("\nPrinter Queue is FULL!\n");
        return;
    }

    printf("Enter print job name: ");
    scanf("%s", job);

    if (front == -1)
        front = 0;

    rear++;
    strcpy(queue[rear], job);

    printf("Print job '%s' added to the queue.\n", job);
}

// Process the first print job
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nPrinter Queue is EMPTY!\n");
        return;
    }

    printf("\nPrinting job: %s\n", queue[front]);

    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

// Display all print jobs
void display()
{
    int i;

    if (front == -1)
    {
        printf("\nPrinter Queue is EMPTY!\n");
        return;
    }

    printf("\nPrint Jobs in Queue:\n");

    for (i = front; i <= rear; i++)
    {
        printf("%d. %s\n", i - front + 1, queue[i]);
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n===== PRINTER SPOOLING SYSTEM =====\n");
        printf("1. Add Print Job\n");
        printf("2. Print Job\n");
        printf("3. Display Print Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting Printer Spooling System...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}

/*
Output:
--- Printer Spooling System ---
1. Add Print Job
2. Print Document
3. Display Pending Jobs
4. Exit
Enter your choice: 1
Enter document number: 101
Print job added: 101

Enter your choice: 1
Enter document number: 102
Print job added: 102

Enter your choice: 1
Enter document number: 103
Print job added: 103

Enter your choice: 3

Pending print jobs:
1. 101
2. 102
3. 103

Enter your choice: 2
Printing document: 101

Enter your choice: 3

Pending print jobs:
1. 102
2. 103

Enter your choice: 2
Printing document: 102

Enter your choice: 2
Printing document: 103

Enter your choice: 2
No print jobs available!

Enter your choice: 4
Exiting printer system.
*/