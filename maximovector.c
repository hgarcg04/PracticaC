#include <stdio.h>

int main() {
    int n, maximo;
    printf("Introduce un número: \n");
    scanf("%d", &n);
    
    int vector[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }
    
    maximo = vector[0];
    
    for (int i = 1; i < n; i++) {
        if (vector[i] > maximo) {
            maximo = vector[i];
        }
    }
    
    printf("\nEl máximo es: %d\n", maximo);
    
    return 0;
}