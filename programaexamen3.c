#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_matrix(int filas,int columnas,int *p);
int compute_solution(int filas,int columnas,int *p);
void copia_cadena(char cadena[100],char copia[100]);
//void imprimematriz(int filas,int columnas,int *p);

int main()
{
    int filas,columnas,*p,resultado;
    char cadena[100],copia[100];
    
    printf("Escriba una cadena de como máximo 100 caracteres... ");
    fgets(cadena,100,stdin);
    do
    {
        printf("Escribe el numero de filas... ");
        scanf("%d",&filas);
        if (filas<=0 || filas%3!=0)
        {
            printf("Error\n");
        }
    }while(filas<=0 || filas%3!=0);

    do
    {
        printf("Escribe el numero de columnas... ");
        scanf("%d",&columnas);
        if (columnas<=0 || columnas%3!=0)
        {
            printf("Error\n");
        }
    }while(columnas<=0 || columnas%3!=0);
    srand(time(NULL));
    p=(int*)malloc(filas*columnas*(sizeof(int)));
    
    init_matrix(filas,columnas,p);
    //imprimematriz(filas,columnas,p);
    resultado=compute_solution(filas,columnas,p);
    printf("El resultado es %d.\n",resultado);
    copia_cadena(cadena,copia);
    printf("La cadena copiada es %s",copia);

    free(p);
    return 0;
}


void init_matrix(int filas,int columnas,int *p)
{
    int i,j;
    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            if (j%2==0)
            {
                *(p+j+(columnas*i))=rand()%9+1;
            }
            if (j%2!=0)
            {
                *(p+j+(columnas*i))=rand()%9-9;
            }
        }
    }
}

/*void imprimematriz(int filas,int columnas,int *p)
{
    int i,j;
    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            printf("%d ",*(p+j+(columnas*i)));
        }
        printf("\n");
    }
}
*/

int compute_solution(int filas,int columnas,int *p)
{
    int i,j,contador=0;
    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            if (*(p+j+(columnas*i))%2==0)
            {
                contador++;
            }
        }
    }
    return contador;
}

void copia_cadena(char cadena[100],char copia[100])
{
    int i,j=0;
    for (i=0;cadena[i]!='\0';i++)
    {
        if (i%2==0)
        {
            copia[j]=cadena[i];
            j++;
        }
    }
    copia[j]='\0';
}