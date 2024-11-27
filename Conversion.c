#include <stdio.h>
int main()
{
    float km,millas,yardas,pies;
    printf("Escribe un numero de kilometros... ");
    scanf("%f",&km);
    millas=km/1.6;
    yardas=km*100000/91.44;
    pies=km*100000/30.48;
    printf("Las millas son %f, las yardas son %f y los pies son %f \n",millas,yardas,pies);
    return 0;
}
