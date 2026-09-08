/* C program to find the GCD using recursive function */

#include <stdio.h>

int gcd(int n1, int n2);

int main()
{
    int n1, n2, g;

    printf("Enter two numbers\n");
    if (scanf("%d%d", &n1, &n2) != 2)
    {
        fprintf(stderr, "Please enter two integers.\n");
        return 1;
    }

    g = gcd(n1, n2);

    printf("GCD of %d and %d is:%d\n", n1, n2, g);

    return 0;
}

int gcd(int n1, int n2)
{
    if (n2 == 0)
        return n1 < 0 ? -n1 : n1;

    return gcd(n2, n1 % n2);
}