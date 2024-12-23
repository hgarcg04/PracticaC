#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void inicializarMatriz(int matriz[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (rand() % 10) + 1;
        }
    }
}
void multiplica(int A[][10], int B[][10], int C[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
int main() {
    int n;
    printf("Introduce el tamaño de la matriz: ");
    scanf("%d", &n);
    int A[n][10], B[n][10], C[n][10];
    srand(time(NULL));
    inicializarMatriz(A, n);
    inicializarMatriz(B, n);
    multiplica(A, B, C, n);
    printf("\nMatriz A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz C (Resultado):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}