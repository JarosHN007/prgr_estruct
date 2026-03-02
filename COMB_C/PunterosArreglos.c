#include <stdio.h>

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    int estudiantesA[3] = {65,67,70};
    int estudiantesB[3] = {32,28,36};
    int totalestudiantes[3];
    int *punt1 = estudiantesA;
    int *punt2 = estudiantesB;
    int *punt3 = totalestudiantes;
    int *pntr,*pntr2;

    //La suma de *(punt3 + i) = *(punt1 + i) + *(punt2 + i) es igual a totalestudiantes[i] = estudiantesA[i] + estudiantesB[i];
    //estudiantesA es equivalente a &estudiantesA[0] --> primera posicion del arreglo
    //Un arreglo por si solo es una direccion - estudiantesA[i] se traduce a *(estudiantesA + i).

    pntr = &estudiantesA[0];
    printf("----------Direccion y valor de estudiantesA [0]----------\n");
    printf("Esta es la direccion de estudiantes [0]: %p \n",(void *)pntr);
    printf("Este es el valor que esta dentro de la direccion de estudiantes [0]: %d \n", *pntr);

    printf("\n");

    pntr2 = &estudiantesA[1];
    printf("----------Suma elementos arreglos estudiantesA [0] y estudiantesA [1]----------\n");
    printf("Esta es la direccion de estudiantes [1]: %p \n", (void *)pntr2);
    printf("Este es el valor que esta dentro de la direccion de estudiantes [0]: %d \n", *pntr2);
    printf("Suma de arreglo estudiantes [0] y estudiantes [1]: %d \n", *pntr+*pntr2);

    printf("\n");

    *pntr = *pntr + *(pntr+2);
    printf("----------Suma en movimento de direcciones----------\n");
    printf("Moviendonos en direcciones para suma de elementos de arreglos: *pntr = *pntr + *(pntr+2) \n");
    printf("Suma de elementos de arreglos en estudiantes [0] y estudiantes[2]: %d\n", *pntr);

    printf("\n");

    printf("----------Ejemplo suma de vectores sin punteros---------\n");
    for (int i=0;i<3;i++) {
        totalestudiantes[i] = estudiantesA[i] + estudiantesB[i];
    }
    for (int i=0;i<3;i++) {
        printf("Valor de posicion %d total de suma %d usando solamente arreglos\n",i, totalestudiantes[i]);
    }

    printf("\n");

    printf("----------Suma de Vectores---------- \n");
    for (int i=0;i<3;i++) {
        *(punt3 + i) = *(punt1 + i) + *(punt2 + i);
    }
    printf("Resultado de suma de vectores: \n");
    for (int i=0;i<3;i++) {
        printf("Valor de posicion %d total de suma %d\n",i, punt3[i]);
    }



    return 0;
}