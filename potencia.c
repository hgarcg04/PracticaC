//Hugo García 23 de septiembre de 2024
#include <stdio.h>
int main()
{
   int pot,base,exponente;
   printf("Introduzca la base... ");
   scanf("%d",&base);
   printf("Introduzca el exponente... ");
   scanf("%d",&exponente);
   if((base>=1) && (exponente>=1)){
       pot=1;
       while(exponente>=1){
         pot=pot*base;
         exponente--;
       }
       printf("El resultado es %d\n",pot);
   }
   else{
     printf("Error, los numeros han de ser mayores o iguales a 1\n");
   }
   return 0;
}
          
