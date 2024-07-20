#include <stdio.h>

int main()
{
    float valor, suma = 0, promedio, maximo = 0;
    int dia_maximo;
    for (int i = 0; i < 7; i++) {
        printf("Ingrese el valor del dólar para el día %d: ", i + 1);
        scanf("%f", &valor);
        suma += valor;
        if (valor > maximo) {
            maximo = valor;
            dia_maximo = i + 1;
        }
    }
    promedio = suma / 7;
    printf("El promedio del valor del dólar en los 7 días es: %.2f\n", promedio);
    printf("El día con el valor más alto fue el día %d con un valor de %.2f\n", dia_maximo, maximo);
    return 0;
}