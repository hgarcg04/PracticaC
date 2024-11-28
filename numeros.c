#include <stdio.h>
int main()
{
    int a,b,i;
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
    for (i=a;i<=b;i++)
        {
            if (i%2==0)
            {
                printf("%d",i);
                printf("\n");
            }
        }
    return 0;
}