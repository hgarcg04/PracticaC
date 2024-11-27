#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_matrix(int a,int b,int *p);
int compute_solution(int c,int d,int a,int b,int *p);
void procesa_cadena(char cadena[102],char solucion[102],int c,int d,char l);
int main()
{
    int a,b,c,d,*p,resultado;
    char cadena[102],solucion[102],l;
    printf("Escriba la cadena de máximo 100 caracteres... ");
    fgets(cadena,100,stdin);
    printf("Escribe una letra... ");
    scanf("%c",&l);
    do {
        printf("Introduce un valor para a (mayor que 0): ");
        scanf("%d", &a);
    } while (a <= 0);

    do {
        printf("Introduce un valor para b (mayor que 0): ");
        scanf("%d", &b);
    } while (b <= 0);

    do {
        printf("Introduce un valor para c (entre 0 y %d): ", b);
        scanf("%d", &c);
    } while (c < 0 || c >= b);

    do {
        printf("Introduce un valor para d (entre %d y %d): ", c, b - 1);
        scanf("%d", &d);
    } while (d < c || d >= b);
    srand(time(NULL));
    p=(int*)malloc(a*b*(sizeof(int)));
    init_matrix(a,b,p);
    resultado=compute_solution(c,d,a,b,p);
    procesa_cadena(cadena,solucion,c,d,l);
    printf("El resultado es %d.\n",resultado);
    printf("La cadena es %s.\n",solucion);
    free(p);
    return 0;
}

void init_matrix(int a,int b,int *p)
{
    int i,j;
    for (i=0;i<a;i++)
    {
        for (j=0;j<b;j++)
        {
            *(p+j+(b*i))=rand()%16+5;
        }
    }
}

int compute_solution(int c,int d,int a,int b,int *p)
{
    int i,j,suma=0;
    for (i=0;i<a;i++)
    {
        for (j=c;j<=d;j++)
        {           
            suma=suma+*(p+j+(b*i));
        }
    }
    return suma;
}

void procesa_cadena(char cadena[102],char solucion[102],int c,int d,char l)
{
    int i;
    for (i=0;cadena[i]!='\0';i++)
    {
        if (i>=c && i<=d)
        {
            if ((cadena[i])!='a')
            {
                solucion[i]=cadena[i];
            }
            else
            {
                solucion[i]=l;
            }
        }
        else
        {
            solucion[i]=cadena[i];
        }
    }
    solucion[i] = '\0';
}