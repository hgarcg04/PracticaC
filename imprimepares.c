#include <stdio.h>
void imprimepares(int a,int b);
int main()
{
    int a,b;
    do
    {
        printf("Dime un numero... ");
        scanf("%d",&a);
        printf("Dime otro numero... ");
        scanf("%d",&b);
        if (a>b)
        {
            printf("Error, vuelve a escribir los números.\n");
        }
    } while (a>b);
    imprimepares(a,b);
    return 0;
}

void imprimepares(int a,int b)
{
    int i;
    for (i=a;i<=b;i++)
    {
        if (i%2==0)
        {
            printf("%d",i);
            printf("\n");
        }
    }
}