#include <stdio.h>

int factorial(int n);
int main()
{
    int n,resultado;
    do
    {
        printf("Dime un numero... ");
        scanf("%d", &n);
        if (n<0)
        {
            printf("Error, el numero ha de ser positivo.\n");
        }
    } while (n<0);
    resultado = factorial(n);
    printf("El factorial de %d es %d\n", n, resultado);
    return 0;
}

int factorial(int n)
{
    int resultado = 1;
    for (int i = 1; i <= n; i++)
    {
        resultado *= i;
    }
    return resultado;
}