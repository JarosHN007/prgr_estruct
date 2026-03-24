#include <stdio.h>

#define MAX 3

struct Cola {
    int clientes[MAX];
    int frente;
    int final;
};

// Meter clientes (ENQUEUE)
void encolar(struct Cola *structCola, int id) {
    if (structCola->final < MAX - 1) { //Evitando el Desbordamiento
        structCola->final++; //Otra forma de escribirlo es (*q).final++;

        *(structCola->clientes + structCola->final) = id; //Otra forma de escribirlo es q->clientes[q->final]
                                                          //Otra forma tambien (*q).clientes[(*q).final] = id;

        printf("Llego el Cliente ID: %d (Posicion del arreglo: %d)\n", id, structCola->final);
    } else {
        printf("Fila llena. Cliente %d queda en espera \n", id);
    }
}

// Atender al primero que llego (DEQUEUE)
void desencolar(struct Cola *structCola) {
    if (structCola->frente <= structCola->final) {
        printf("ATENDIENDO A: %d\n", *(structCola->clientes + structCola->frente));

        structCola->frente++; // El FIFO sucede aquí: nos movemos al siguiente

    } else {
        printf("No hay nadie mas en la fila.\n");
    }
}

int main() {
    struct Cola fila = {{0}, 0, -1}; // Inicializamos el struct
    int menu, idCliente;

    do {
        printf("\n=======Menu=======\n");
        printf("1) Encolar\n");
        printf("2) Desencolar\n");
        printf("3) Salir\n");
        scanf(" %d", &menu);
        switch (menu) {
            case 1:
                printf("Ingrese el ID del cliente: \n");
                scanf("%d", &idCliente);
                encolar(&fila, idCliente);
                break;
            case 2:
                desencolar(&fila);
                break;
            case 3:
                printf("Se cerro caja...\n");
                break;
        }
        if (menu != 3 && fila.frente <= fila.final) {
            printf("El siguiente Cliente en espera: %d\n", *(fila.clientes + fila.frente));
        }
    } while (menu != 3);


    return 0;
}