#include <stdio.h>
#include <stdlib.h>
#define TAM 9
#define MAT 9
void inicializamatriz(int matriz[TAM][MAT]);
void imprimematriz(int matriz[TAM][MAT]);
int main()
{
   int matriz[TAM][MAT];
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
            if(i==u)
            {
                matriz[i][u]=1;
            }
            else
            {
                matriz[i][u]=0;           
            }

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
         printf("%d  ", matriz[i][u]);
      }
      printf("\n");
   }
}