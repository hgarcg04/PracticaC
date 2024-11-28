//Hugo García 23 de septiembre de 2024
#include <stdio.h>

void menu(int i);
int main()
{
   float lado1,lado2,radio1,volumen1=1,volumen2=1,altura1,altura2,pi=3.141592;
   int i;
   printf("Escriba 1 para calcular el volumen de un cono, escriba 2 para calcular el volumen de un ortoedro o escriba 3 para salir...\n");
   scanf("%d",&i);
   menu(i);
   return 0;
}   


void menu(int i)
{  
   float lado1,lado2,radio1,volumen1=1,volumen2=1,altura1,altura2,pi=3.141592;
   if(i==1)
   {
     printf("Escriba el valor de la altura... ");
     scanf("%f",&altura1);
     printf("Escriba el valor del radio... ");
     scanf("%f",&radio1);
     volumen1=((pi*radio1*radio1*altura1)/3);
     printf("El valor del volumen del cono es %f\n",volumen1);
   }
   
   if(i==2)
   {
     printf("Escriba el valor de la altura... ");
     scanf("%f",&altura2);
     printf("Escriba el valor del lado1... ");
     scanf("%f",&lado1);
     printf("Escriba el valor del lado2... ");
     scanf("%f",&lado2);
     volumen2=(lado1*lado2*altura2);
     printf("El valor del volumen del ortoedro es %f\n",volumen2);
   }
   
   if(i==3)
   {
     printf("Salir.\n");
   }
   
   if((i!=1) && (i!=2) && (i!=3))
   {
        printf("\nSolo puedes poner o 1 o 2 o 3, no pongas cualquier otro número.\n");
        printf("\nEscriba 1 para calcular el volumen de un cono, escriba 2 para calcular el volumen de un ortoedro o escriba 3 para salir...\n");
        scanf("%d",&i);
        menu(i);
   }
}
