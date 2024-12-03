#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#define n 5
int main()
{
    int A[n][n],B[n][n],C[n][n],D[n][n];
    int i,j,k;
    srand(time(NULL));
    omp_set_num_threads(4);
    #pragma omp parallel sections private(i,j)
    { 
        #pragma omp section
        {
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    A[i][j]=rand()%10+1;
                }
            }
        }
        #pragma omp section
        {
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    B[i][j]=rand()%10+1;
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
                    C[i][j]=0;
                    for (k=0;k<n;k++)
                    {
                        C[i][j]+=A[i][k]*B[k][j];
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
                    D[i][j]=A[i][j]+B[i][j];
                }
            }
        }
    }
    printf("Matriz A:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz C (producto A * B):\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz D (suma A + B):\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}