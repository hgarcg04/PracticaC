#include <stdio.h>

int suma_n_primeros_numeros(int n);
int main()
{
    int n,suma;
    do
    {
        printf("Dime un numero... ");
        scanf("%d",&n);
        if (n<0)
        {
            printf("Error, el número ha de ser positivo.\n");
        }
    }while (n<0);
    suma=suma_n_primeros_numeros(n);
    printf("La suma es %d\n",suma);
    return 0;
}

int suma_n_primeros_numeros(int n)
{
    int suma=0,i;
    for (i=1;i<=n;i++)
    {
        suma+=i;
    }
    return suma;
}