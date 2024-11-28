#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 3
#define COL 6
void inicializamatriz(int matriz[FIL][COL]);
void imprimematriz(int matriz[FIL][COL]);
int sumacolumna(int matriz[FIL][COL]);
int main()
{
    int matriz[FIL][COL];
    srand(time(NULL));
    inicializamatriz(matriz);
    imprimematriz(matriz);
    sumacolumna(matriz);
    printf("Fin del programa.\n");
    return 0;
}

void inicializamatriz(int matriz[FIL][COL])
{
    int i,j;
    for(i=0;i<FIL;i++)
    {
        for(j=0;j<COL;j++)
        {
            matriz[i][j]=rand()%10+1;
        }
    }
}

void imprimematriz(int matriz[FIL][COL])
{
    int i,j;
    for (i=0;i<FIL;i++)
    {
        for (j=0;j<COL;j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

int sumacolumna(int matriz[FIL][COL])
{
    int suma=0,i,j;
    for(j=0;j<COL;j++)
    {
        for(i=0;i<FIL;i++)
        {
            suma=suma+matriz[i][j];
        }
        printf("La suma de la columna %d es: %d\n",j+1,suma);
        suma=0;
    }
}