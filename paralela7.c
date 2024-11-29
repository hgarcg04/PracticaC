#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int nthread,tid,x,num,ganador=0;
    omp_set_num_threads(10);
    srand(tid);
    num=rand()%10000+1;
    #pragma omp parallel private(tid,x) shared(num,ganador)
    {
        srand(tid);
        do
        {
            x=rand()%10000+1;
            tid=omp_get_thread_num();
            if (x==num)
            {
                printf("El thread %d genera el nº %d.\n",tid,x);
                printf("El thread %d ha ganado, enhorabuena :)\n",tid);
                ganador=1;
            }
        }while (ganador==0);
    }
    return 0;
}