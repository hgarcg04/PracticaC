#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int nthread,tid,x,num,ganador=0;
    omp_set_num_threads(8);
    srand(tid);
    printf("Dime un número... ");
    scanf("%d",&num);
    #pragma omp parallel private(tid,x) shared(num,ganador)
    {
        srand(tid);
        do
        {
            x=rand()%10000+1;
            tid=omp_get_thread_num();
            if (x==num)
            {
                #pragma omp critical
                    printf("El thread %d genera el nº %d.\n",tid,x);
                    printf("El thread %d ha ganado.\n",tid);
                    ganador=1;
            }
        }while (ganador==0);
    }
    return 0;
}