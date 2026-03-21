#include <stdio.h>

struct Cliente {
    int id;
};

// Función para llenar la cola/fila de clientes usando FOR
void llenarCola(struct Cliente *p, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        (p + i)->id = 100 + (i + 1); // 101, 102, 103...
        printf("Llego el Cliente ID: %d\n", (p + i)->id);
    }
}

int main() {
    struct Cliente fila[3];
    struct Cliente *p_frente = &fila[0]; // El que será atendido

    printf("--- LLEGANDO LOS CLIENTES ---\n");
    llenarCola(p_frente, 3); // Llenamos con los clientes que van llegando, en este caso 3

    printf("\n--- DEMOSTRACION FIFO ---\n");

    // AQUÍ SUCEDE EL FIFO: First In, First Out
    for (int i = 0; i < 2; i++) {
        printf("SE ATIENDE AL PRIMERO QUE LLEGA, ATENDIENDO A: %d\n", p_frente->id);

        p_frente++; // <--- ESTO ES EL FIFO, NOS MOVEMOS AL SIGUIENTE QUE LLEGO ANTES QUE LOS DEMAS

        printf("  Siguiente en espera ahora es: %d\n", p_frente->id);
    }

    return 0;
}