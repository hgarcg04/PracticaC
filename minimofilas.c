#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void inicializarMatriz(int matriz[][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = (rand() % 21) - 10;
        }
    }
}
void minimoFilas(int matriz[][10], int n, int m, int minimos[]) {
    for (int i = 0; i < n; i++) {
        int min = matriz[i][0];
        for (int j = 1; j < m; j++) {
            if (matriz[i][j] < min) {
                min = matriz[i][j];
            }
        }
        minimos[i] = min;
    }
}
int main() {
    int n, m;
    printf("Introduce el número de filas (n): ");
    scanf("%d", &n);
    printf("Introduce el número de columnas (m): ");
    scanf("%d", &m);
    if (m > 10) {
        printf("El número máximo de columnas permitido es 10.\n");
        return 1;
    }
    int matriz[n][10];
    int minimos[n];
    srand(time(NULL));
    inicializarMatriz(matriz, n, m);
    minimoFilas(matriz, n, m, minimos);
    printf("\nLa matriz generada es:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nLos valores mínimos por fila son:\n");
    for (int i = 0; i < n; i++) {
        printf("Fila %d: %d\n", i + 1, minimos[i]);
    }
    return 0;
}
