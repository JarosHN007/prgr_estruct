#include <stdio.h>
#define TamañoArr 4

void extramemoria (char *character, int e, char extra);

int main(void) {

    char memoria[TamañoArr];
    char *pntr = memoria;
    int e;
    int n;
    char extra;

    printf("Ingrese cuantos procesos desea realizar \n");
    scanf(" %d", &n);
    for (int i = 0; i<n; i++) {
        printf("Ingrese cuanto espacio cubre el proceso \n");
        scanf(" %d", &e);
        if (e > TamañoArr) {
            printf("Ingrese el proceso desea realizar \n");
            scanf(" %s", &extra);
            char memoriaextra[e];
            pntr = memoriaextra;
            extramemoria(pntr, e, extra);
            printf("El arreglo completo es: %s \n", pntr);

        }
        else {
            printf("Ingrese el caracter para almacenar proceso \n");
            scanf(" %s", &memoria);
            extramemoria(pntr, e, *memoria);
            printf("El arreglo completo es este: %s \n", pntr);

        }

    }


    return 0;
}
void extramemoria(char *character, int e, char extra) {
    for (int j = 0; j < e; j++) {
        *(character + j) = extra;
    }
}

