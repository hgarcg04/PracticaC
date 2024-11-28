#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
void inicializavector(int vector[TAM]);
void imprimevector(int vector[TAM]);
int sumaElementos(int vector [TAM]);
int main()
{
   int vector[TAM];
   srand(time(NULL));
   inicializavector(vector);
   imprimevector(vector);
   sumaElementos(vector);
   return 0;
}


void inicializavector(int vector[TAM])
{
   int i;
   for(i=0;i<TAM;i++)
      vector[i]=rand() %10+1;
}


void imprimevector(int vector[TAM])
{
   int i;
   printf ("El vector es:\n");
   for(i=0;i<TAM;i++)
      printf("%d\n", vector[i]);
}

int sumaElementos(int vector [TAM])
{
   int i,x=0;
   for(i=0;i<TAM;i++)
   {
      x+=vector[i];
   }
   printf("La suma es: %d\n",x);
   return x;
}
