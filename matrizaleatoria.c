#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5
#define MAT 5
void inicializamatriz(int matriz[TAM][MAT]);
void imprimematriz(int matriz[TAM][MAT]);
int main()
{
   int matriz[TAM][MAT];
   srand(time(NULL));
   inicializamatriz(matriz);
   imprimematriz(matriz);
   return 0;
}


void inicializamatriz(int matriz[TAM][MAT])
{
   int i,u;
   for(i=0;i<TAM;i++)
   {
      for(u=0;u<MAT;u++)
      {
         matriz[i][u]=rand() %13+3;
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
