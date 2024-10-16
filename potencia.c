#include <stdio.h>

void potencia(int a, int b) {
    int resultado = 1;
    for(int i = 0; i < b; i++) {
        resultado = resultado * a;
    }
    printf ("O resultado é igual a %d", resultado)
}

void soma(int numeros[10]) {
    int total = 0;
    for(int i = 0; i < 10; i++){
        total += numeros[i];
    }
    printf("O total é %d", total);
}


void soma(int* num, int a, int b) {
   *num = a + b;
}
