#include <stdio.h>

int main()
{
	int nota;
	printf("Digame su nota... \n");
	scanf("%d",&nota);
    switch(nota)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		   printf("Suspenso\n");
		   break;
		case 5:
		case 6:
		   printf("Aprobado\n");
		   break;
		case 7:
		case 8:
		   printf("Notable\n");
		   break;
		case 9:
		case 10:
		   printf("Sobresaliente\n");
		   break;
	        default:
	           printf("Introduzca una nota del 1 al 10, por favor.\n");
	           break;
	 }
     return 0;
}
