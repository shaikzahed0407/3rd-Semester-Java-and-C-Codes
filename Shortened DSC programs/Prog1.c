#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/' || ch == '%') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void convert(char infix[])
{
    char postfix[MAX], ch;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main()
{
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    convert(infix);
    return 0;
}
/*
Output: 
Enter an infix expression: a+b*c
Postfix Expression: abc*+
*/