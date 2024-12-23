#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int es_primo(int num)
{
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= num / 2; i += 2)
    {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() 
{
    int n;
    printf("Introduce un numero n: ");
    scanf("%d", &n);
    int contador_primos = 0;

    #pragma omp parallel for reduction(+:contador_primos)
    for (int i = 1; i <= n; i++)
    {
        if (es_primo(i)) contador_primos++;
    }
    printf("La cantidad de números primos en el intervalo [1, %d] es: %d\n", n, contador_primos);
    return 0;
}