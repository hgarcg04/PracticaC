#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 6
#define MAT 6
void inicializamatriz(int matriz[TAM][MAT]);
void imprimematriz(int matriz[TAM][MAT]);
int sumaElementos(int matriz[TAM][MAT]);
int main()
{
   int matriz[TAM][MAT];
   srand(time(NULL));
   inicializamatriz(matriz);
   imprimematriz(matriz);
   sumaElementos(matriz);
   return 0;
}


void inicializamatriz(int matriz[TAM][MAT])
{
   int i,u;
   for(i=0;i<TAM;i++)
   {
      for(u=0;u<MAT;u++)
      {
         matriz[i][u]=rand() %10+1;
      }
   }
}


void imprimematriz(int matriz[TAM][MAT])
{
   int i,u;
   printf ("La matriz es:\n");
   for(i=0;i<TAM;i++)
   {
      for(u=0;u<MAT;u++)
      {
         printf("%d ", matriz[i][u]);
      }
      printf("\n");
   }
}

int sumaElementos(int matriz[TAM][MAT])
{
    int i,u,x=0;
    for (i=0;i<TAM;i++)
    {
        for (u=0;u<TAM;u++)
        {
            x=x+matriz[i][u];
        }
    }
    printf("La suma de los elementos de la matriz es: %d\n",x);
    return x;
}