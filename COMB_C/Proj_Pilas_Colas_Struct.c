#include <stdio.h>

#define MAX 3

struct Cola {
    int clientes[MAX];
    int frente;
    int final;
};

// Meter clientes (ENQUEUE)
void encolar(struct Cola *q, int id) {
    if (q->final < MAX - 1) { //Evitando el Desbordamiento
        q->final++;

        *(q->clientes + q->final) = id;

        printf("Llego el Cliente ID: %d (Posicion del arreglo: %d)\n", id, q->final);
    } else {
        printf("Fila llena. Cliente %d queda en espera \n", id);
    }
}

// Atender al primero que llego (DEQUEUE)
void desencolar(struct Cola *q) {
    if (q->frente <= q->final) {
        printf("ATENDIENDO A: %d\n", *(q->clientes + q->frente));

        q->frente++; // El FIFO sucede aquí: nos movemos al siguiente

    } else {
        printf("No hay nadie mas en la fila.\n");
    }
}

int main() {
    struct Cola fila = {{0}, 0, -1}; // Inicializamos el struct

    printf("------------ENCOLAR----------\n");

    printf("--- LLEGANDO CLIENTES ---\n");
    encolar(&fila, 101);
    encolar(&fila, 102);
    encolar(&fila, 103);
    encolar(&fila, 104); // Este ya no cabe (MAX es 3)

    printf("\n------------DESENCOLAR------------\n");

    printf("--- ATENDIENDO (FIFO) ---\n");
    desencolar(&fila); // Atiende al 101
    desencolar(&fila); // Atiende al 102

    printf("\nSiguiente cliente esperando: %d\n", *(fila.clientes + fila.frente));

    return 0;
}