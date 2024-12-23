#include <stdio.h>
#include <stdlib.h>
void inicializamatriz(int **matriz, int n, int m);
int calculaminimo(int **matriz, int n, int m);
int main() {
    int n, m;
    srand(43);
    printf("Introduce tamaño de la matrix (filas,columnas): \n");
    scanf("%d %d", &n, &m);
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(m * sizeof(int));
    }
    inicializamatriz(matriz, n, m);
    int minimo = calculaminimo(matriz, n, m);
    printf("\nEl mínimo es: %d\n", minimo);
    printf("\nLa matriz es:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
void inicializamatriz(int **matriz, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = rand() % 10 + 1;
        }
    }
}
int calculaminimo(int **matriz, int n, int m) {
    int minimo = matriz[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
            }
        }
    }
    return minimo;
}