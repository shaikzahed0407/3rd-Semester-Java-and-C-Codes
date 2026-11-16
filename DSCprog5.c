//5.Write a C program to represent two polynomials using linked lists and perform polynomial addition.

#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial node
struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

// Insert a term into the polynomial
struct Node* insertTerm(struct Node *head, int coeff, int exp) {
    struct Node *newNode, *temp;

    newNode = createNode(coeff, exp);

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    // Insert at beginning if exponent is greater
    if (exp > head->exp) {
        newNode->next = head;
        return newNode;
    }

    temp = head;

    // Find the correct position
    while (temp->next != NULL && temp->next->exp > exp) {
        temp = temp->next;
    }

    // If same exponent exists, add coefficients
    if (temp->exp == exp) {
        temp->coeff = temp->coeff + coeff;
        free(newNode);
    }
    else if (temp->next != NULL && temp->next->exp == exp) {
        temp->next->coeff = temp->next->coeff + coeff;
        free(newNode);
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

// Display polynomial
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }

    printf("\n");
}

// Add two polynomials
struct Node* addPolynomials(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL) {

        if (p1->exp == p2->exp) {
            result = insertTerm(result,
                                p1->coeff + p2->coeff,
                                p1->exp);

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            result = insertTerm(result,
                                p1->coeff,
                                p1->exp);

            p1 = p1->next;
        }
        else {
            result = insertTerm(result,
                                p2->coeff,
                                p2->exp);

            p2 = p2->next;
        }
    }

    // Copy remaining terms of first polynomial
    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Copy remaining terms of second polynomial
    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Main function
int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *sum = NULL;

    int n, coeff, exp, i;

    // First polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        poly1 = insertTerm(poly1, coeff, exp);
    }

    // Second polynomial
    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        poly2 = insertTerm(poly2, coeff, exp);
    }

    // Display polynomials
    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    // Addition
    sum = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    display(sum);

    return 0;
}

/*
Output

Enter number of terms in first polynomial: 4
Enter coefficient and exponent:
5 3
4 2
2 1
7 0

Enter number of terms in second polynomial: 4
Enter coefficient and exponent:
3 3
2 2
6 1
5 0

First Polynomial: 5x^3 + 4x^2 + 2x^1 + 7x^0
Second Polynomial: 3x^3 + 2x^2 + 6x^1 + 5x^0
Sum of Polynomials: 8x^3 + 6x^2 + 8x^1 + 12x^0
*/