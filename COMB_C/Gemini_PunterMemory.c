#include <stdio.h>

#define TamañoArr 4
#define Tamañoextra 20

// Prototipos
void llenarconceros(char *pntr, int tamañoarreglo);
// Ahora esta función se encarga de TODO el llenado
void llenarmemorias(char caracter, char *pntr, int tamañoarreglo, int espacio, char *pntrExtra, int *posExtra);

int main(void) {
    char memoria[TamañoArr];
    char memoriaExtra[Tamañoextra];
    int posicionExtra = 0; // Este será nuestro marcador de posición
    int totalprocesos, espacio;
    char caracter;

    // Inicializamos
    llenarconceros(memoria, TamañoArr);
    llenarconceros(memoriaExtra, Tamañoextra);

    printf("Ingrese cuantos procesos desea almacenar: \n");
    if (scanf("%d", &totalprocesos) != 1) return 1;

    for (int i = 0; i < totalprocesos; i++) {
        printf("\n--- Proceso %d ---\n", i + 1);
        printf("Cuanta memoria abarca: ");
        scanf("%d", &espacio);
        printf("Caracter: ");
        scanf(" %c", &caracter);

        // Llamamos a la función mágica.
        // Pasamos &posicionExtra para que la función pueda actualizar el valor real en el main.
        llenarmemorias(caracter, memoria, TamañoArr, espacio, memoriaExtra, &posicionExtra);
    }

    // IMPRESIÓN FINAL
    printf("\n==========================================\n");
    printf("Memoria disponible: ");
    for (int i = 0; i < TamañoArr; i++) {
        printf("[%c]", memoria[i]);
    }

    printf("\nMemoria extra:      ");
    for (int i = 0; i < posicionExtra; i++) {
        printf("[%c]", memoriaExtra[i]);
    }
    printf("\n==========================================\n");

    return 0;
}

void llenarconceros(char *pntr, int tamañoarreglo) {
    for (int i = 0; i < tamañoarreglo; i++) {
        *(pntr + i) = '0'; // Usamos '0' para que se vea limpio
    }
}

void llenarmemorias(char caracter, char *pntr, int tamañoarreglo, int espacio, char *pntrExtra, int *posExtra) {
    int puestos_llenados = 0;

    // 1. Intentamos llenar en la memoria principal
    for (int i = 0; i < tamañoarreglo; i++) {
        if (*(pntr + i) == '0') {
            *(pntr + i) = caracter;
            puestos_llenados++;

            // Si ya llenamos lo que el usuario pidió, terminamos la función
            if (puestos_llenados == espacio) {
                return;
            }
        }
    }

    // 2. Si salimos del for y falta espacio, llenamos en la EXTRA
    if (puestos_llenados < espacio) {
        int restante = espacio - puestos_llenados;

        for (int j = 0; j < restante; j++) {
            // Usamos *posExtra para escribir en la posición actual
            *(pntrExtra + (*posExtra)) = caracter;
            // Aumentamos el valor de la posición en el main
            (*posExtra)++;
        }
    }
}