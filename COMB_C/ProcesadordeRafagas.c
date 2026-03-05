#include <stdio.h>
void procesarRafaga (int *datos, int *registroHistorial);

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    int datos[5];
    int registroHistorial = 0;
    for (int i = 0; i < 5; i++) {
        printf("Ingrese valor del arreglo: \n");
        scanf("%d", &datos[i]);
    }
    procesarRafaga(datos, &registroHistorial);

    for (int i = 0; i < 5; i++) {
        printf("Los valores minimos de temperatura por esta rafaga rafaga son: %d \n", registroHistorial);
    }


    return 0;
}
void procesarRafaga (int *datos, int *registroHistorial) {
    *registroHistorial = *(datos + 1);
    for (int i = 0; i <5;i++) {
        if ((*(datos + i)) < *registroHistorial) {
            *registroHistorial = *(datos + i);
        }
        else {
            *registroHistorial;
        }
    }
}
