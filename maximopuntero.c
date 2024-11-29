#include <stdio.h>
#include <stdlib.h>
int calculamaximo(int *numeros, int n);
int main()
{
    int n,maximo;
    printf("Introduzca la cantidad de numeros que desee... ");
    scanf("%d",&n);

    int *numeros = (int *)malloc(n * sizeof(int));
    printf("Introduzca los %d enteros:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&numeros[i]);
    }

    maximo=calculamaximo(numeros,n);
    printf("El maximo es: %d.\n",maximo);
    printf("Los números leídos son:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", numeros[i]);
    }
    return 0;
}

int calculamaximo(int *numeros, int n)
{
    int maximo=numeros[0],i;
    for(i=1;i<n;i++)
    {
        if(numeros[i]>maximo)
        {
            maximo=numeros[i];
        }
    }
    return maximo;
}