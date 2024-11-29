#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int nthread,tid,x;
    printf("Trabajamos con 8 hilos\n");
    omp_set_num_threads(8);
    srand(time(NULL));
    x=rand()%100+1;
    #pragma omp parallel private(tid) shared(x)
    {
        tid=omp_get_thread_num();
        printf("El thread %d genera el nº %d\n",tid,x);
    }
    return 0;
}