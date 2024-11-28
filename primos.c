#include <stdio.h>
int calculadivisores(int n);
int primos(int n,int divisores);
int main()
{
    int n,divisores,primo;
    do
    {
        printf("Escribe un numero... ");
        scanf("%d",&n);
        if (n<0)
        {
            printf("Error, ha de ser positivo.\n");
        }
    }while (n<0);
    divisores=calculadivisores(n);
    primo=primos(n,divisores);
    if (primo==1)
    {
        printf("El número es primo.\n");
    }
    if (primo==0)
    {
        printf("El número no es primo.\n");
    }
    return 0;
}

int calculadivisores(int n)
{
    int i,contador;
    for (i=1;i<=n;i++)
    {
        if (n%i==0)
        {
            contador+=1;
        }
    }
    return contador;
}

int primos(int n,int divisores)
{
    if (divisores<=2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}