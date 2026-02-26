#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    int estudiante;

    float N1, N2, N3;
    float promediofinal;
    int CE;
    printf("Ingresa la cantidad de estudiantes:\n");
    scanf("%d", &CE);
    for (int i = 0; i < CE; i++) {
        printf("Ingrese el nombre del estudiante %d:\n",i+1);

        scanf("%d", &estudiante);

        printf("Nota 1: \n");
        scanf("%f", &N1);

        printf("Nota 2: \n");
        scanf("%f", &N2);

        printf("Nota 3: \n");
        scanf("%f", &N3);

        promediofinal = (N1 + N2 + N3) / 3;
        printf("Promedio del estudiante %d es de %f %\n", i+1, promediofinal);

        if (promediofinal < 65  ) {
            printf("¡¡¡TE QUEDASTE JAJAJA!!! \n");
        } else {
                printf("¡¡¡PASASTE JAJAJA!!! \n");
            }

    }
    return 0;
}