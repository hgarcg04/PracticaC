#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int n,i;
    int *vector;
    float media,resultado=0;
    double t1,t2;
    do
    {
        printf("Dime el tamaño del vector... ");
        scanf("%d",&n);
        if (n<=0)
        {
            printf("Error\n");
        }
    } while (n<=0);
    vector=(int*)malloc(n*(sizeof(int)));
    srand(time(NULL));
    t1=omp_get_wtime();
    #pragma omp parallel private(i) shared(n)
    {
        #pragma omp for
            for (i=0;i<n;i++)
            {
                *(vector+i)=rand()%100+1;
            }
    }
    #pragma omp parallel private(i) shared(n)
    {
        #pragma omp for reduction (+:resultado)
            for (i=0;i<n;i++)
            {
                resultado+=(*(vector+i));
            }
    }
    t2=omp_get_wtime();
    media=resultado/n;
    for (i=0;i<n;i++)
    {
        printf("%d ",*(vector+i));
    }
    printf("\n");
    printf("La media es %f\n",media);
    printf("El tiempo que dura es %f\n",t2-t1);
    free(vector);
    return 0;
}
