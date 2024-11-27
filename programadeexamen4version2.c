#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_matrix(int a,int b,int *p);
int compute_solution(int a,int b,int *p);
void procesa_cadena(char cadena[100],char inversa[100],char l);
//void imprimematriz(int a,int b,int *p);

int main()
{
    int a,b,*p,resultado;
    char cadena[100],inversa[100],l;

    printf("Escriba una cadena... ");
    fgets(cadena,100,stdin);
    printf("Escriba una letra... ");
    scanf("%c",&l);
    do
    {
        printf("Escriba el numero de filas... ");
        scanf("%d",&a);
        if (a<=0)
        {
            printf("Error\n");
        }
    }while(a<=0);
    do
    {
        printf("Escriba el numero de columnas... ");
        scanf("%d",&b);
        if (b<=0)
        {
            printf("Error\n");
        }
    }while(b<=0);

    srand(time(NULL));
    p=(int*)malloc(a*b*(sizeof(int)));

    init_matrix(a,b,p);
    //imprimematriz(a,b,p);
    resultado=compute_solution(a,b,p);
    printf("El resultado es %d.\n",resultado);
    procesa_cadena(cadena,inversa,l);
    printf("La cadena inversa sin blancos es %s\n",inversa);
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
            *(p+j+(b*i))=rand()%10-10;
        }
    }
}


int compute_solution(int a,int b,int *p)
{
    int i,j,suma=0;
    for (i=0;i<a;i++)
    {
        for (j=0;j<b;j++)
        {
            if (i==j)
            {
                suma=suma+*(p+j+(b*i));
            }
        }
    }
    return suma;
}


void procesa_cadena(char cadena[100],char inversa[100],char l)
{
    int i,j=0,contador=0;
    for (i=0;cadena[i]!='\0';i++)
    {
        if (cadena[i]==l)
        {
            contador+=1;
            if (contador==2)
            {
                printf("La segunda letra %c está en la posición %d.\n",l,i);
            }
        }
    }
    while (cadena[i]!='\0')
    {
        i++;
    }
    for ((i=i-1);i>=0;i--)
    {
        if (cadena[i]!=' ')
        {
            inversa[j]=cadena[i];
            j++;
        }
    }
    inversa[j]='\0';
}


/*void imprimematriz(int a,int b,int *p)
{
    int i,j;
    for (i=0;i<a;i++)
    {
        for (j=0;j<b;j++)
        {
            printf("%d ",*(p+j+(b*i)));
        }
        printf("\n");
    }
}
*/