#include <stdio.h>
#define  TamanoArreglo 6

void resultadoEntrega(char *puntero);
void estadoEntrega(char *puntero);

int main(void) {
    char ruta[TamanoArreglo] = {'C','L','H','H','O','Z'};
    int menu;
    do {
        printf("----Menu----\n");
        printf("1. Registrar Entrega \n");
        printf("2. Estado de Entregas\n");
        printf("3. Salir\n");
        scanf("%d", &menu);
        switch (menu) {
            case 1: resultadoEntrega(ruta);
            break;
            case 2: estadoEntrega(ruta);
            break;
            case 3: break;
        }

    } while (menu != 3);
   return 0;
}

void resultadoEntrega(char *puntero) {
    int entregaOpendiente;
    for (int i = 0; i < TamanoArreglo; i++) {
        printf("Presiona 1 para entregado y 2 para pendiente de la entrega %c\n", *(puntero + i));
        scanf(" %d", &entregaOpendiente);
        if (entregaOpendiente == 1) {
            *(puntero + i) = 'E';
        }
    }
}
void estadoEntrega(char *puntero) {
    int entregado = 0;
    int pendiente = 0;
    for (int i = 0; i < TamanoArreglo; i++) {
        if (*(puntero + i) == 'E') {
            entregado++;
        }
        else {
            pendiente++;
        }
    }
    printf("Total Entregado: %d y Total Pendiente: %d\n", entregado, pendiente);
}