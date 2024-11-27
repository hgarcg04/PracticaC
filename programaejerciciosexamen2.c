#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_matrix(int n,int m,int *p);
void imprimematriz(int n,int m,int *p);
int compute_solution(int n,int m,int *p);

int main()
{
    int n,m,*p,producto;
    do
    {
        printf("Escribe el numero de filas...");
        scanf("%d",&n);
        if (n<=0)
        {
            printf("Error\n");
        }
    } while (n<=0);
    do
    {
        printf("Escribe el numero de columnas...");
        scanf("%d",&m);
        if (m<=0)
        {
            printf("Error\n");
        }
    } while (m<=0);
    p=(int*)malloc(n*m*(sizeof(int)));
    srand(time(NULL));
    init_matrix(n,m,p);
    imprimematriz(n,m,p);
    producto=compute_solution(n,m,p);
    printf("El resultado es %d.\n",producto);
    free(p);
    return 0;
}

void init_matrix(int n,int m,int *p)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            *(p+j+(m*i))=rand()%100+1;
        }
    }
}

void imprimematriz(int n,int m,int *p)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            printf("%d ",*(p+j+(m*i)));
        }
        printf("\n");
    }
}

int compute_solution(int n,int m,int *p)
{
    int i,j,producto=1,contador=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (i%2!=0 && *(p+j+(m*i))%5==0)
            {
                producto*=*(p+j+(m*i));
                contador+=1;
            }
        }
    }
    if (contador==0)
        {
           producto=0;
        }
    return producto;
}