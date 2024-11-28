#include <stdio.h>

//Este programa suma los numeros naturales hasta n

int main()
{
	int n;
	int i=1;
	int total=0;
	printf("Dime tu número: ");
	scanf("%d", &n);
	
	if (n>=1)
	{
		while (i<=n)
		{
			total = i + total;
			i++;
		}
	}
	
	else 
	{
		printf("Error, el número debe ser mayor o igual que 1");
	}
	
	printf("La suma es %d\n", total);

return 0;
}

