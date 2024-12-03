#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#define n 5
int main()
{
    int *matriz;
    int i,j,suma=0;
    double t1,t2;
    matriz=(int*)malloc(n*n*(sizeof(int)));
    srand(time(NULL));
    t1=omp_get_wtime();
    #pragma omp parallel private(i,j)
    {
        #pragma omp for
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                *(matriz+j+(i*n))=rand()%10+1;
            }
        }
    }
    #pragma omp parallel for reduction(+:suma) private(i,j)
    for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                suma+=(*(matriz+j+(i*n)));
            }
        }
    t2=omp_get_wtime();
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ",*(matriz+j+(i*n)));
        }
        printf("\n");
    }
    printf("\n");
    printf("La suma es %d.\n",suma);
    printf("El tiempo que dura es %f.\n",t2-t1);
    free(matriz);
    return 0;
}