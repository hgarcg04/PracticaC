#include <stdio.h>
int calculapotencia(int base,int exponente);
int main()
{
    int base,exponente,potencia;
    do
    {
        printf("Dime la base... ");
        scanf("%d",&base);
        if (base<0)
        {
            printf("Error, ha de ser positivo.\n");
        }
    } while (base<0);
    do
    {
        printf("Dime el exponente... ");
        scanf("%d",&exponente);
        if (exponente<0)
        {
            printf("Error, ha de ser positivo.\n");
        }
    } while (exponente<0);
    potencia=calculapotencia(base,exponente);
    printf("El resultado es %d.\n",potencia);
    return 0;
}

int calculapotencia(int base,int exponente)
{
    int potencia=1,i;
    if (base==0)
    {
        potencia=0;
    }
    if (exponente==0 && base!=0 || base==1)
    {
        potencia=1;
    }
    if (exponente!=0 && base!=0 || base!=1)
    {
        for (i=0;i<exponente;i++)
        {
            potencia*=base;
        }
    }
    return potencia;
}