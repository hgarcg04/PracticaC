#include <stdio.h>
void leeredades(int p[6]);
int edad_maxima(int e[6]);

int main()
{
    int edadmaxima;
    int edades[6];
    leeredades(edades);
    edadmaxima=edad_maxima(edades);
    printf("La edad maxima escrita es %d años.",edadmaxima);
    return 0;
}
int edad_maxima(int e[6])
{
    int edadmaxima=0;
    int i;
    for(i=0;i<6;i++)
    {
        if(e[i]>edadmaxima){
        edadmaxima=e[i];
        }
    }
    return edadmaxima;
}
void leeredades(int p[6])
{
    int i;
    printf("Escribe las edades... \n");
    for(i=0;i<6;i++)
    {
        scanf("%d",&p[i]);
    }
}