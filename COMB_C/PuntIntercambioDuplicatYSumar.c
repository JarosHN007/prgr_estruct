#include <stdio.h>
void intercambiar (int *a, int *b);
void duplicarYsumar (int *pntr , int *resultado);
void duplicarYsumar_n (int *pntr, int n, int *resultadosuma_n);


int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    int arreglo[3] = {10,20,30};
    int resultadosuma = 0;
    int a,b;
    int n;

    printf("Ingrese dos valores para a y b\n");
    scanf( "%d %d", &a , &b);
    printf("Valor anterior de a = %d y b = %d\n", a,b);
    intercambiar(&a,&b);
    printf("Valor actual de a = %d y b = %d\n",a,b);

//--------------------------------------------------------------------------------------------------------------------

    duplicarYsumar(arreglo,&resultadosuma);
    printf("\n------duplicar y sumar para arreglo establecido------\n");

    printf("Multiplicado por 2 el arreglo \n");
    for (int i = 0; i < 3; i++) {
        printf("Arreglo[%d] = %d \n",i,*(arreglo + i));
    }
    printf("Guardado de sumas %d\n", resultadosuma);


//----------------------------------------------------------------------------------------------------------------------

    printf("\n----------Arreglo n----------\n");
    printf("Ingrese el tamaño del arreglo: \n");
    scanf("%d",&n);
    int arreglo_n[n];
    int resultadosuma_n = 0;
    for (int i = 0; i < n; i++) {
        printf("Ingrese el valor de la posicion %d del arreglo\n", i);
        scanf(" %d", (arreglo_n + i));
    }
    duplicarYsumar_n (arreglo_n,n, &resultadosuma_n);
    for (int i = 0; i < n; i++) {
        printf("Valor duplicado en %d = %d\n",i, (*(arreglo_n + i)));
    }
    printf("Suma total de todo: %d", resultadosuma_n);

    return 0;
}

void intercambiar (int *a , int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}
void duplicarYsumar (int *pntr , int *resultadosuma) {
    for (int i = 0; i < 3; i++) {
        *(pntr + i) = *(pntr + i) * 2;
        *resultadosuma = *resultadosuma + *(pntr + i);

    }
}
//duplicarYsumar para arreglo n
void duplicarYsumar_n (int *pntr2, int n, int *resultadosuma_n) {
    for (int i = 0; i < n; i++) {
        *(pntr2 +i) = *(pntr2 + i) * 2;
        *resultadosuma_n = *resultadosuma_n + *(pntr2 + i);
    }
}