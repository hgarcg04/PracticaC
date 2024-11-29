#include <stdio.h>
#include <string.h>
void quitaespacios(char *cadena, char *cadenasin);
int main()
{
    char cadena[100],cadenasin[100];
    int n;
    printf("Digame cuantos caracteres desea que tenga su cadena... ");
    scanf("%d",&n);
    getchar();
    printf("Escriba la cadena... ");
    fgets(cadena,n+1,stdin);
    quitaespacios(cadena,cadenasin);
    printf("La cadena sin espacios es:\n%s\n",cadenasin);
    return 0;
}

void quitaespacios(char *cadena, char *cadenasin)
{
    int i=0,j=0;
    while (cadena[i]!='\n' && cadena[i]!='\0')
    {
        if(cadena[i]!=' ')
        {
            cadenasin[j]=cadena[i];
            j++;
        }
        i++;
    }
    cadenasin[j] = '\0';
}