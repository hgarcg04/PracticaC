#include <stdio.h>
#include <omp.h>
#define n 4
#define m 5
int main() {
    int matrix[n][m];
    #pragma omp parallel
    {       
        int id = omp_get_thread_num();
        #pragma omp for
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = id;
            }
        }
        #pragma omp barrier
        #pragma omp single
        {
            printf("Matriz después de la inicialización:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}