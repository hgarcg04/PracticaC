#include <stdio.h>
#include <omp.h>
#define n 20
int main() 
{
    int vector[n];
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int num_hilos = omp_get_num_threads();
        #pragma omp for schedule(static)
        for (int i = 0; i < n; i++) {
            vector[i] = id;
        }
        #pragma omp barrier
        #pragma omp single
        {
            printf("El vector después de la inicialización: \n");
            for (int i = 0; i < n; i++) {
                printf("%d ", vector[i]);
            }
            printf("\n");
        }
    }
    return 0;
}