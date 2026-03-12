#include <stdio.h>
#define TamañoArr 4
#define Tamañoextra 10

//void extramemoria (char *character, int e, char extra);
void llenarconceros (char *pntr, int tamañoarreglo);
int llenarmemorias (char caracter, char *pntr, int tamañoarreglo, int espacio);

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    char memoria[TamañoArr];
    char memoriaExtra[Tamañoextra];
    char *pntr = memoria;
    char *pntrExtra = memoriaExtra;

    int espacio, totalprocesos, sobra;
    char caracter;

    llenarconceros(pntr, TamañoArr);

    printf("Ingrese cuantos procesos desea almacenar: \n" );
    scanf(" %d", &totalprocesos);

    for (int i = 0; i < totalprocesos; i++) {
        printf("\nCuanta memoria abarca el proceso %d \n", i +1);
        scanf(" %d", &espacio);
        printf("Ingrese el caracter con el cual desea guardar en el proceso %d \n", i + 1);
        scanf(" %c", &caracter);

        sobra = llenarmemorias(caracter, pntr, TamañoArr, espacio);

        printf("Se almaceno en memoria disponible: \n");
        for (int j = 0; j < TamañoArr; j++) {
            printf("[%c]", *(pntr + j));
        }
        if (sobra > 0) {
            for (int i = 0; i < sobra; i++) {
                *(pntrExtra + i) = caracter;
            }
            printf("\nSe tuvo que recurrir a memoria extra: \n");
            for (int j = 0; j < sobra; j++) {
                printf("[%c]", *(pntrExtra + j));
            }
        }

    }
    return 0;
}


void llenarconceros (char *pntr, int tamañoarreglo) {
    for (int i =0; i < tamañoarreglo; i++) {
        *(pntr + i) = 0;
    }

}

int llenarmemorias (char caracter, char *pntr, int tamañoarreglo, int espacio) {
    int contador = 0;
    for (int i = 0; i< tamañoarreglo; i++) {
        if (*(pntr + i) == 0) {
            *(pntr + i) = caracter;
            contador++;
            if (contador == espacio) {
                return 0;
            }
        }
    }
    return (espacio - contador);
}
