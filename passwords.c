#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void inicializavectorchar(char vector[26]);
void inicializavector(int vectore[8]);
void generacontraseña(char vector[26],char password[9],int vectore[8]);

int main() {
    char vector[26],password[9];
    int vectore[8];

    inicializavectorchar(vector);
    inicializavector(vectore);
    generacontraseña(vector,password,vectore);
    printf("La contraseña generada es %s\n", password);
    return 0;
}

void inicializavectorchar(char vector[26]) {
    int i, letra='a';
    for (i=0;i<26;i++)
    {
        vector[i]=letra;
        letra+=1;
    }
}

void inicializavector(int vectore[8]) {
    for (int i=0;i<8;i++)
    {
        vectore[i]=rand()%26;
    }
}

void generacontraseña(char vector[26],char password[9],int vectore[8])
{
    int i;
    for (int i=0;i<8;i++)
    {
        password[i]=vector[vectore[i]];
    }
    password[8]='\0';
}