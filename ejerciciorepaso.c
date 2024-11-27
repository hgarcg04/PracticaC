#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculamatriz(int f,int c,int *p);
void inicializamatriz(int f,int c,int *p);
void copiacadena(char cadena[100],char copia[100],char l);
void imprimematriz(int f,int c,int *p);

int main()
{
    char cadena[100],copia[100],l;
    int f,c,*p,producto;
    printf("Escriba una cadena de máximo 100 caracteres... ");
    fgets(cadena,100,stdin);
    do
    {
        printf("Escriba una letra minúscula... ");
        scanf("%c",&l);
        getchar();
        if (l>='A' && l<='Z')
        {
            printf("Error, ha de ser minúscula\n");
        }
    } while (l>='A' && l<='Z');
    do
    {
        printf("Escribe el numero de filas... ");
        scanf("%d",&f);
        if (f<=0 || f%4!=0)
        {
            printf("Error\n");
        }
    } while (f<=0 || f%4!=0);
    do
    {
        printf("Escribe el numero de columnas... ");
        scanf("%d",&c);
        if (c<=0 || c%4!=0)
        {
            printf("Error\n");
        }
    } while (c<=0 || c%4!=0);
    srand(time(NULL));
    p=(int*)malloc(f*c*(sizeof(int)));

    inicializamatriz(f,c,p);
    imprimematriz(f,c,p);
    producto=calculamatriz(f,c,p);
    printf("El resultado del cálculo es %d\n",producto);
    copiacadena(cadena,copia,l);
    printf("La copia de la cadena es %s",copia);
    free(p);
    return 0;
}


void inicializamatriz(int f,int c,int *p)
{
    int i,j;
    for (i=0;i<f;i++)
    {
        if (i%2==0)
        {
            for (j=0;j<c;j++)
            {
                *(p+j+(c*i))=rand()%6+5;
            }
        }
        if (i%2!=0)
        {
            for (j=0;j<c;j++)
            {
                *(p+j+(c*i))=rand()%11+20;
            }
        }
    }
}

int calculamatriz(int f,int c,int *p)
{
    int i,j,producto=1;
    for (i=0;i<f;i++)
    {
        for (j=0;j<c;j++)
        {
            if (j%2!=0)
            {
                producto=producto*(*(p+j+(c*i)));
            }
        }
    }
    return producto;
}

void copiacadena(char cadena[100],char copia[100],char l)
{
    int i;
    for (i=0;cadena[i]!='\0';i++)
    {
        if (cadena[i]==l)
        {
            copia[i]='X';
        }
        else
        {
            copia[i]=cadena[i];
        }
    }
    copia[i]='\0';
}

void imprimematriz(int f,int c,int *p)
{
    int i,j;
    for (i=0;i<f;i++)
    {
        for (j=0;j<c;j++)
        {
            printf("%d ",*(p+j+(c*i)));
        }
        printf("\n");
    }
}