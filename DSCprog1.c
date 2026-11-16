//1. Write a C program to implement a stack using arrays and perform the conversion of an infix expression to postfix expression.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push an element into stack
void push(char ch)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = ch;
}

// Pop an element from stack
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Return precedence of operators
int precedence(char ch)
{
    switch (ch)
    {
        case '^':
            return 3;

        case '*':
        case '/':
        case '%':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

// Convert infix expression to postfix
void infixToPostfix(char infix[])
{
    char postfix[MAX];
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        // If opening parenthesis, push into stack
        else if (ch == '(')
        {
            push(ch);
        }

        // If closing parenthesis
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            pop(); // Remove '('
        }

        // If operator
        else
        {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main()
{
    char infix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}

/*
Output:
Enter an infix expression: a+b*c
Postfix Expression: abc*+
*/