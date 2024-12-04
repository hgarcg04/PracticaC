#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#define n 5
int main()
{
    int *matriza,*matrizb,*matrizc;
    int i,j,k;
    double t1,t2;
    srand(time(NULL));
    matriza=(int*)malloc(n*n*(sizeof(int)));
    matrizb=(int*)malloc(n*n*(sizeof(int)));
    matrizc=(int*)malloc(n*n*(sizeof(int)));
    omp_set_num_threads(8);
    t1=omp_get_wtime();
    #pragma omp parallel for private(i,j)
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            *(matriza+j+(n*i))=rand()%10+1;
            *(matrizb+j+(n*i))=rand()%10+1;
        }
    }
    #pragma omp parallel for private(i,j,k)
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            *(matrizc+j+(n*i))=0;
            for (k=0;k<n;k++)
            {
                *(matrizc+j+(n*i))+=(*(matriza+k+(n*i)))*(*(matrizb+j+(n*k)));
            }
        }
    }
    t2=omp_get_wtime();
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ",*(matriza+j+(i*n)));
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ",*(matrizb+j+(i*n)));
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ",*(matrizc+j+(i*n)));
        }
        printf("\n");
    }
    printf("\n");
    printf("El tiempo que dura es %f.\n",t2-t1);
    free(matriza);
    free(matrizb);
    free(matrizc);
    return 0;
}