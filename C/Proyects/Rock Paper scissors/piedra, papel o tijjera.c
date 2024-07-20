#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarJugadaComputadora() {
    // Generar un número aleatorio entre 0 y 2
    int jugada = rand() % 3;
    return jugada;
}

int determinarGanador(int jugadaUsuario, int jugadaComputadora) {
    // Si las jugadas son iguales, es un empate
    if (jugadaUsuario == jugadaComputadora) {
        return 0; // Empate
    }

    // Determinar el ganador basado en las reglas del juego
    // Piedra: 0, Papel: 1, Tijera: 2
    if ((jugadaUsuario == 0 && jugadaComputadora == 2) ||
        (jugadaUsuario == 1 && jugadaComputadora == 0) ||
        (jugadaUsuario == 2 && jugadaComputadora == 1)) {
        return 1; // El usuario gana
    } else {
        return -1; // La computadora gana
    }
}

void mostrarResultado(int resultado) {
    if (resultado == 0) {
        printf("Empate\n");
    } else if (resultado == 1) {
        printf("Ganaste!\n");
    } else {
        printf("JA JA JA Perdiste we\n");
    }
}

int main() {
    int jugarDeNuevo = 1;

    srand(time(0)); // Inicializar la semilla para los números aleatorios

    while (jugarDeNuevo) {
        int jugadaUsuario, jugadaComputadora, resultado;

        printf("Elige tu jugada:\n");
        printf("1 - Piedra\n");
        printf("2 - Papel\n");
        printf("3 - Tijera\n");
        scanf("%d", &jugadaUsuario);

        if (jugadaUsuario < 1 || jugadaUsuario > 3) {
            printf("Jugada inválida. Por favor, elige un número entre 1 y 3.\n");
            continue;
        }

        jugadaUsuario--; // Ajustar el valor ingresado para que coincida con los índices del arreglo

        jugadaComputadora = generarJugadaComputadora();
        resultado = determinarGanador(jugadaUsuario, jugadaComputadora);

        printf("La computadora eligió: ");

        char *opciones[] = {"Piedra", "Papel", "Tijera"};
        printf("%s\n", opciones[jugadaComputadora]);

        mostrarResultado(resultado);

        printf("¿Deseas jugar de nuevo? (S/N): ");
        char respuesta[2];
        scanf("%s", respuesta);

        if (respuesta[0] == 'N' || respuesta[0] == 'n') {
            jugarDeNuevo = 0;
        }
    }

    return 0;
}