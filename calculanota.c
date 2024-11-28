#include <stdio.h>

int main()
{
	int nota;
	printf("Digame su nota... \n");
	scanf("%d",&nota);
    if (nota==5 || nota==6)
    {
        printf("Aprobado.\n");
    }
    if (nota==7 || nota==8)
    {
        printf("Notable.\n");
    }
    if (nota==9 || nota==10)
    {
        printf("Sobresaliente.\n");
    }
    if (nota>=0 && nota<=4)
    {
        printf("Suspenso.\n");
    }
    return 0;
}