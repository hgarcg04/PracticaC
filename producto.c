#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 3
#define COL 3
void inicializamatriz(int matriz[FIL][COL]);
void imprimematriz(int matriz[FIL][COL]);
void productomatriz(int matriz1[FIL][COL],int matriz2[FIL][COL],int producto[FIL][COL]);
int main()
{
    int matriz1[FIL][COL],matriz2[FIL][COL],matriz[FIL][COL],producto[FIL][COL];
    srand(time(NULL));
    inicializamatriz(matriz1);
    inicializamatriz(matriz2);
    imprimematriz(matriz1);
    printf("\n");
    imprimematriz(matriz2);
    printf("\n");
    productomatriz(matriz1,matriz2,producto);
    imprimematriz(producto);
    return 0;
}

void inicializamatriz(int matriz[FIL][COL])
{
    int i,j;
    for (i=0;i<FIL;i++)
    {
        for (j=0;j<COL;j++)
        {
            matriz[i][j]=rand()%5+1;
        }
    }
}

void imprimematriz(int matriz[FIL][COL])
{
   int i,j;
   for(i=0;i<FIL;i++)
   {
      for(j=0;j<COL;j++)
      {
         printf("%d ", matriz[i][j]);
      }
      printf("\n");
   }
}

void productomatriz(int matriz1[FIL][COL],int matriz2[FIL][COL],int producto[FIL][COL])
{
    int i,j,k;
    for (i=0;i<FIL;i++)
    {
        for (j=0;j<COL;j++)
        {
            producto[i][j]=0;
            for (k=0;k<COL;k++)
            {
                producto[i][j]+=matriz1[i][k]*matriz2[k][j];
            }
        }
    }
}