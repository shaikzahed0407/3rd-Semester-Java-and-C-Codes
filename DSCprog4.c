//4.Write a C program to implement a singly linked list with insertion, deletion, searching, and traversal operations.

#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to insert a node at the end
void insert() {
    int value;
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted successfully.\n");
}

// Function to delete a node
void deleteNode() {
    int value;
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;

    // If first node is to be deleted
    if (temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted successfully.\n");
}

// Function to search an element
void search() {
    int value, position = 1;
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n",
                   value, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Value not found.\n");
}

// Function to traverse the list
void traverse() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Singly Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Searching\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                search();
                break;

            case 4:
                traverse();
                break;

            case 5:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/*
output
===== SINGLY LINKED LIST =====
1. Insert at Beginning
2. Insert at End
3. Delete a Node
4. Search an Element
5. Traverse / Display
6. Exit

Enter your choice: 2
Enter value: 10
10 inserted at the end.

Enter your choice: 2
Enter value: 20
20 inserted at the end.

Enter your choice: 1
Enter value: 5
5 inserted at the beginning.

Enter your choice: 5
Linked List: 5 -> 10 -> 20 -> NULL

Enter your choice: 4
Enter value to search: 10
10 found at position 2.

Enter your choice: 3
Enter value to delete: 10
10 deleted successfully.

Enter your choice: 5
Linked List: 5 -> 20 -> NULL
*/