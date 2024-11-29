#include <stdio.h>
#include <string.h>
int main()
{
    int longitud;
    char cadena[100],compara[100]="Cadena a adivinar",añadida[100];
    fgets(cadena,100,stdin);
    fgets(añadida,100,stdin);
    
    printf("\n");

    longitud=strlen(cadena);
    if (cadena[longitud-1] == '\n')
        cadena[longitud-1]='\0';
    printf("La longitud de la cadena es: %d\n",longitud);    
    
    printf("\n");

    if (strcmp(cadena,compara)==0)
        printf("Las cadenas son iguales, muy bien\n");
    else if (strcmp(cadena,compara)>0)
            printf("La cadena es mayor\n");
        else
            printf("La cadena es menor\n");
    
    printf("\n");

    strcat(cadena,añadida);
    printf("Las cadenas concatenadas son:\n%s\n",cadena);
    
    return 0;
}