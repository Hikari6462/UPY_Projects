#include <stdio.h>

int main()
{
    float peso, altura, imc;
    printf("Ingrese su peso : ");
    scanf("%f", & peso);
    printf("Ingrese su altura: ");
    scanf("%f", &altura);
    imc = peso / (altura * altura);
    printf("Tu IMC es: %.2f\n", imc);
    if (imc < 18.5) {
        printf("Estás por debajo del peso normal.\n");
    } else if (imc >= 18.5 && imc <= 24.9) {
        printf("Estás en un peso normal.\n");
    } else if (imc >= 25 && imc <= 29.9) {
        printf("Tienes sobrepeso.\n");
    } else {
        printf("Tienes obesidad.\n");
    }
    return 0;
}