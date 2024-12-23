#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n;
    printf("Introduce el numero de alumnos (n): ");
    scanf("%d", &n);
    if (n <= 0) return 1;

    int vector1[n], vector2[n];
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        vector1[i] = rand() % 11;
        vector2[i] = rand() % 11;
    }

    int sum1 = 0, sum2 = 0, min1 = 10, min2 = 10, max1 = 0, max2 = 0;
    #pragma omp parallel for reduction(+:sum1, sum2) reduction(min:min1, min2) reduction(max:max1, max2)
    for (int i = 0; i < n; i++) {
        sum1 += vector1[i];
        sum2 += vector2[i];
        if (vector1[i] < min1) min1 = vector1[i];
        if (vector1[i] > max1) max1 = vector1[i];
        if (vector2[i] < min2) min2 = vector2[i];
        if (vector2[i] > max2) max2 = vector2[i];
    }

    printf("Resultados para el primer parcial:\nMedia: %.2f\nMinimo: %d\nMaximo: %d\n", (double)sum1/n, min1, max1);
    printf("\nResultados para el segundo parcial:\nMedia: %.2f\nMinimo: %d\nMaximo: %d\n", (double)sum2/n, min2, max2);
    return 0;
}