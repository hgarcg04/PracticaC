#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int n;
    int *a,*b,*c,*d;
    int i,j,k;
    srand(time(NULL));
    omp_set_num_threads(4);
    do
    {
        printf("Dime el tamaño de la matriz... ");
        scanf("%d",&n);
        if (n<=0)
        {
            printf("Error\n");
        }
    }while (n<=0);
    a=(int*)malloc(n*n*(sizeof(int)));
    b=(int*)malloc(n*n*(sizeof(int)));
    c=(int*)malloc(n*n*(sizeof(int)));
    d=(int*)malloc(n*n*(sizeof(int)));
    #pragma omp parallel sections private(i,j)
    { 
        #pragma omp section
        {
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    *(a+j+(i*n))=rand()%10+1;
                }
            }
        }
        #pragma omp section
        {
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    *(b+j+(i*n))=rand()%10+1;
                }
            }
        }
    }
    #pragma omp parallel sections private(i,j,k)
    {
        #pragma omp section
        {
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    *(c+j+(i*n))=0;
                    for (k=0;k<n;k++)
                    {
                        *(c+j+(i*n))+=(*(a+j+(i*n)))*(*(b+j+(i*n)));
                    }
                }
            }
        }
        #pragma omp section
        {
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    *(d+j+(i*n))=(*(a+j+(i*n)))+(*(b+j+(i*n)));
                }
            }
        }
    }
    printf("Matriz A:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", *(a+j+(i*n)));
        }
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", *(b+j+(i*n)));
        }
        printf("\n");
    }

    printf("\nMatriz C (producto A * B):\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", *(c+j+(i*n)));
        }
        printf("\n");
    }

    printf("\nMatriz D (suma A + B):\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", *(d+j+(i*n)));
        }
        printf("\n");
    }
    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}