#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_matrix(int fil,int col,int *p);
int compute_solution(int fil,int col,int num,int *p);
void procesa_cadena(char cadena[100],char solucion[100],char l,int num);
//void imprimematriz(int fil,int col,int *p);

int main()
{
    int *p,fil,col,num,producto;
    char cadena[100],solucion[100],l;
    printf("Introduzca una cadena de máximo 100 caracteres... ");
    fgets(cadena,100,stdin);
    printf("Escriba una letra... ");
    scanf("%c",&l);
    do
    {
        printf("Introduzca el numero de filas... ");
        scanf("%d",&fil);
        if (fil<=0)
        {
            printf("Error\n");
        }
    } while (fil<=0);
    
    do
    {
        printf("Introduzca el numero de columnas... ");
        scanf("%d",&col);
        if (col<=0)
        {
            printf("Error\n");
        }
    } while (col<=0);

    do
    {
        printf("Introduzca un numero... ");
        scanf("%d",&num);
        if (num<=0)
        {
            printf("Error\n");
        }
    } while (num<=0);
    
    srand(time(NULL));
    p=(int*)malloc(fil*col*(sizeof(int)));
    
    init_matrix(fil,col,p);
    //imprimematriz(fil,col,p);
    producto=compute_solution(fil,col,num,p);
    printf("El resultado es %d.\n",producto);
    procesa_cadena(cadena,solucion,l,num);
    printf("La cadena solucion es %s",solucion);
    free(p);
    return 0;
}

void init_matrix(int fil,int col,int *p)
{
    int i,j;
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            *(p+j+(col*i))=rand()%11+5;
        }
    }
}

/*void imprimematriz(int fil,int col,int *p)
{
    int i,j;
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            printf("%d ",*(p+j+(col*i)));
        }
        printf("\n");
    }
}
*/

int compute_solution(int fil,int col,int num,int *p)
{
    int i,j,producto=1,contador=0;
    for (i=0;i<fil;i++)
    {
        if(i%num==0)
        {
            for (j=0;j<col;j++)
            {
                producto*=(*(p+j+(col*i)));
            }
            contador++;
        }
    }
    if (contador==0)
    {
        producto=0;
    }
    return producto;
}

void procesa_cadena(char cadena[100],char solucion[100],char l,int num)
{
    int contador=0,i;
    for (i=0;cadena[i]!='\0';i++)
    {
        if (cadena[i]=='p')
        {
            if (contador<num)
            {
                solucion[i]=l;
                contador++;
            }
            else
            {
                solucion[i]=cadena[i];
            }
        }
        else
        {
            solucion[i]=cadena[i];
        }
    }
    solucion[i]='\0';
}