#include <stdio.h>
int calculadivisores(int n);
int main()
{
    int n,divisores;
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
    printf("El numero de divisores es %d.\n",divisores);
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